
gcc -c -O3 -mthumb -mthumb-interwork gfx.c
gcc -c -O3 -mthumb -mthumb-interwork mode4.c
gcc -c -O3 -mthumb -mthumb-interwork Main.c
gcc -mthumb -mthumb-interwork -o Main.elf Main.o gfx.o mode4.o -lm

objcopy -O binary Main.elf Main.gba

Main.gba
pause