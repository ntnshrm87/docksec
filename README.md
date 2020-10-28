# seccomp
For all the snippets related to Docker Security.

1. seccomp_bpf - This is a file to check for seccomp bpf mode (mode2 or filter mode).
2. seccomp_strict and seccomp_strict2 - These are the files to check for seccomp strict mode (mode 1).

Source for seccomp_strict2 and seccomp_bpf - https://security.stackexchange.com/questions/168452/how-is-sandboxing-implemented/175373

Source for seccomp_strict - https://gist.githubusercontent.com/mstemm/3e29df625052616fffcd667ff59bf32a/raw/a200d7d158f4794da8696e7ddcba47042f8a6425/seccomp_strict.c

For a much in-depth review of Seccomp, please see this presentation by Michael Kerrisk - https://www.youtube.com/watch?v=-hmG5An2bN8
