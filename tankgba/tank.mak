CFLAGS = -c -O3
MODEL = -mthumb -mthumb-interwork 
all : tank.gba

tank.gba : tank.elf
	objcopy -O binary tank.elf tank.gba

tank.elf : gfx.o main.o 
	gcc $(MODEL) -o tank.elf main.o gfx.o 

main.o : main.c
	gcc $(CFLAGS) $(MODEL) main.c

gfx.o : gfx.c
	gcc $(CFLAGS) $(MODEL) gfx.c

