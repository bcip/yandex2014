#!/bin/sh

gcc cptest.c -o cptest.exe
g++ gen.cpp -lm -o gen.exe -O2
g++ validate.cpp -lm -o validate.exe -O2
gcc tetra_snark.c -lm -o tetra_snark.exe -O2

./cptest.exe < 01.hand > 001
./cptest.exe < 02.hand > 002
./cptest.exe < 03.hand > 003
./cptest.exe < 16.hand > 016
./cptest.exe < 17.hand > 017

./gen.exe random1 > 004
./gen.exe random2 > 005
./gen.exe random3 > 006
./gen.exe random4 > 007
./gen.exe random5 > 008
./gen.exe random6 > 009
./gen.exe random7 > 010
./gen.exe random8 > 011
./gen.exe random9 > 012
./gen.exe randoma > 013
./gen.exe randomb > 014
./gen.exe randomc > 015


mkdir ../tests
for i in ???;do
echo Validating $i
./validate.exe <$i
echo Generating $i.a
./tetra_snark.exe <$i >../tests/$i.a
mv $i ../tests/$i
done
rm *.exe
rm *.class
