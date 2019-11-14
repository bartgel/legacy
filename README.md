# The original legacy project

## What

(https://jameshfisher.com/2018/03/10/linux-assembly-hello-world/)[Original code by James Fisher]

## Hello world in Linux x86-64 assembly

A “hello world” program writes to stdout (calling write) then exits (calling exit). The assembly program hello.s below does that on Linux x86-64.

```c
global _start

section .text

_start:
  mov rax, 1        ; write(
  mov rdi, 1        ;   STDOUT_FILENO,
  mov rsi, msg      ;   "Hello, world!\n",
  mov rdx, msglen   ;   sizeof("Hello, world!\n")
  syscall           ; );

  mov rax, 60       ; exit(
  mov rdi, 0        ;   EXIT_SUCCESS
  syscall           ; );

section .rodata
  msg: db "Hello, world!", 10
  msglen: equ $ - msg

```

To run it:

```bash
$ nasm -f elf64 -o hello.o hello.s
$ ld -o hello hello.o
$ ./hello
Hello, world!
```

The first important document is the x86-64 ABI specification, maintained by Intel. (Weirdly, the official location for the ABI specification is some random dude’s personal GitHub account. Welcome to the sketchy world of assembly.) The ABI specification describes system calls in the abstract, as it applies to any operating system. Importantly:

- The system call number is put in rax.
- Arguments are put in the registers rdi, rsi, rdx, rcx, r8 and r9, in that order.
- The system is called with the syscall instruction.
- The return value of the system call is in rax. An error is signalled by returning -errno.
- The second document is the Linux 64-bit system call table. This specifies the system call number for each Linux system call. For our example, the write system call is 1 and exit is 60.

Finally, you want the man pages for the system calls, which tell you their signature, e.g.:


```c
#include <unistd.h>
ssize_t write(int fd, const void *buf, size_t count);
```

Armed with this, we know to:

- put the system call number 1 in rax
- put the fd argument in rdi
- put the buf argument in rsi
- put the count argument in rdx
- finally, call syscall
