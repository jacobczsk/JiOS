# Compile ASM -> BIN
nasm -f bin "src/boot/boot.asm" -o "bin/boot/boot.bin"
# Compile ASM -> O
nasm -f elf "src/boot/krnlent.asm" -o "bin/boot/krnlent.o"
# Compile C -> O
i386-elf-gcc -ffreestanding -m32 -g -c "src/lib/jiosio.c" -o "bin/lib/jiosio.o"
i386-elf-gcc -ffreestanding -m32 -g -c "src/lib/jiosstring.c" -o "bin/lib/jiosstring.o"
i386-elf-gcc -ffreestanding -m32 -g -c "src/lib/jiosmem.c" -o "bin/lib/jiosmem.o"
i386-elf-gcc -ffreestanding -m32 -g -c "src/krnl/jioskrnl.c" -o "bin/krnl/jioskrnl.o"
# Link libaries together
i386-elf-ld -o "bin/finallib.o" "bin/lib/jiosmem.o" "bin/lib/jiosstring.o" -Ttext 0x0 "bin/lib/jiosio.o"
# Link O's together
i386-elf-ld -o "bin/finalkrnl.bin" -Ttext 0x1000 "bin/boot/krnlent.o" "bin/krnl/jioskrnl.o" "bin/finallib.o" --oformat binary
# Concat BOOTSECT and KRNL
cat "bin/boot/boot.bin" "bin/finalkrnl.bin" > "release/jios.bin"
# Run VM (Qemu)
qemu-system-x86_64 "release/jios.bin"