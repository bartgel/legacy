rm -rf target
mkdir target
nasm -f elf64 -o target/hello.o src/hello.asm
ld -o target/hello target/hello.o
