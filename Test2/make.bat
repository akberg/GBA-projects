
gcc -c -O3 -mthumb -mthumb-interwork gfx.c
gcc -c -O3 -mthumb -mthumb-interwork main.c
gcc -mthumb -mthumb-interwork -o main.elf main.o gfx.o -lm

objcopy -O binary main.elf main.gba

main.gba
