path=D:\Users\Andreas\Documents\Dev\C\devkitPro\devkitadv\bin

rem If you compile using this line and not the next three
rem it will run like 5 frames a second
rem gcc  -o tank.elf main.c gfx.c

gcc -c -O3 -mthumb -mthumb-interwork gfx.c
gcc -c -O3 -mthumb -mthumb-interwork main.c
gcc -mthumb -mthumb-interwork -o tank.elf main.o gfx.o

objcopy -O binary tank.elf tank.gba

pause

