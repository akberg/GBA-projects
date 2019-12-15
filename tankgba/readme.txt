Tank -------------------------------------------------------

A very very simple MODE4 game for the gameboy advance. It
is very compact, and uses software sprites to keep the
code simple and easy to understand. It is less than 400
lines of code so enjoy.

Instructions.
Use the keypad to dodge the failing bombs. If a bomb hits
you, health will be subtracted until you die.

I have included the dsp files for Visual C++ if you want
to use that as your development environment. You will need
to add C:\devkitadv\bin selecting tools, options, then the
directories tab, then adding that directory to the
executables. When compiled the project runs nmake on the
tank.mak file. 

If you dont have or want to use VisualC++ as your IDE, then
you can simply run use MAKE.BAT, which is included.

Tank was for the GBA was first made back in Nov 2001, but
some small changes have been made since, like the switch
to the devkitadv, and also some code simplifications and
comment additions.

About the graphics. The tool pcx2gba.exe included is made
by Dovoto. It was part of the Pern tutorial he wrote. It
has a few quircks like the name of the C structure
containing the data from the PCX for some reason cuts off
the first letter of the PCX filename, however the resulting
header file still has the right name. Wierd, anyhow the
resulting header files I use to build were hand edited a
little to correct these things, and also some small objects
were combined into one header file, via copy and paste.
You should be able to figure it out. 

Comments or Questions, then goto www.loirak.com or you
can email Ben Rhoades at benr@loirak.com

