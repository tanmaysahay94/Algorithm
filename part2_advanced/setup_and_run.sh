#!/bin/bash

#executable
nasm simple_bootsect.asm -o simple_bootsect.bin

#floppy drive for boot sector
dd if=/dev/zero of=bootdisk.bin bs=512 count=2880
dd if=simple_bootsect.bin of=bootdisk.bin conv=notrunc

#setting up the kernel
nasm keyboard_kernel.asm -o keyboard_kernel.bin
dd if=keyboard_kernel.bin of=bootdisk.bin conv=notrunc bs=512 seek=1

#running the kernel
qemu-system-i386 -fda bootdisk.bin -boot a
