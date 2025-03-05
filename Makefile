all:
	rm -f *.bin *.o Katux.img
	nasm -f bin bootloader.asm -o bootloader.bin
	i686-linux-gnu-gcc -ffreestanding -m32 -nostdlib -fno-pic -c kernel.c keyboard.c screen.c lib.c
	i686-linux-gnu-ld -m elf_i386 -T link.ld -o kernel.bin kernel.o keyboard.o screen.o lib.o
	cat bootloader.bin kernel.bin > Katux.img

clean:
	rm -f *.bin *.o Katux.img

