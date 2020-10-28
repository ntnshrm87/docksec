#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/prctl.h>
#include <sys/syscall.h>
#include <linux/seccomp.h>

/* "mov al,42; ret" aka "return 42" */
static const unsigned char code[] = "\xb0\x2a\xc3";

void main(void)
{
    int fd[2], ret;

    /* spawn child process, connected by a pipe */
    pipe(fd);
    if (fork() == 0) {
        close(fd[0]);

        /* enter mode 1 seccomp and execute untrusted bytecode */
        prctl(PR_SET_SECCOMP, SECCOMP_MODE_STRICT);
        ret = (*(uint8_t(*)())code)();

        /* send result over pipe, and exit */
        write(fd[1], &ret, sizeof(ret));
        syscall(SYS_exit, 0);
    } else {
        close(fd[1]);

        /* read the result from the pipe, and print it */
        read(fd[0], &ret, sizeof(ret));
        printf("untrusted bytecode returned %d\n", ret);
    }
}
