.DEFAULT_GOAL := test.img

./build/boot.o:
	nasm -f elf ./scr/grubLoad/boot.asm -o ./build/boot.o

./build/core.o:
	clang -m32 -c -o ./build/core.o ./scr/system/core.c

./build/screen.o:
	clang -m32 -c -o ./build/screen.o ./scr/system/api/screen.c

./build/asmfunc.o:
	nasm -f elf ./scr/system/api/asmfunc.asm -o ./build/asmfunc.o

./iso/boot/sys.bin: ./build/boot.o ./build/core.o ./build/screen.o ./build/asmfunc.o
	ld -T ./scr/othertool/link.ld -m elf_i386 -nostdlib ./build/boot.o ./build/core.o ./build/screen.o ./build/asmfunc.o -o ./iso/boot/sys.bin

./test.img:	./iso/boot/sys.bin
	grub-mkrescue -o ./test.iso ./iso
	qemu-system-i386 ./test.iso
	rm ./build/*.*
	rm ./iso/boot/sys.bin
	rm ./test.iso