
arm-none-eabi-gcc -c -O3 -mthumb -mthumb-interwork gfx.c
arm-none-eabi-gcc -c -O3 -mthumb -mthumb-interwork main.c
arm-none-eabi-gcc -mthumb -mthumb-interwork -o main.elf main.o gfx.o -lm

arm-none-eabi-objcopy -O binary main.elf main.gba

main.gba
