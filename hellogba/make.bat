
gcc -o hello.elf hello.cpp -lm
objcopy -O binary hello.elf hello.gba
pause