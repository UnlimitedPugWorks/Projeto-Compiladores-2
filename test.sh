./minor -trace < $1.min
nasm -felf32 out.asm
ld -m elf_i386 out.o run/libminor.a -o out
./out 3 100 10



