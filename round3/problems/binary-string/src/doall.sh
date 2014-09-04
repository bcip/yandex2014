#!/bin/sh

gcc cptest.c -o cptest.exe
g++ validator.cpp -lm -o validator.exe -O2
g++ gen.cpp -lm -o gen.exe -O2
g++ matrix_rad_ac.cpp -lm -o matrix_rad_ac.exe -O2

./cptest.exe < 01.hand > 001
./cptest.exe < 02.hand > 002
./cptest.exe < 03.hand > 003
./cptest.exe < 04.hand > 004
./cptest.exe < 05.hand > 005
./cptest.exe < 06.hand > 006
./cptest.exe < 07.hand > 007
./cptest.exe < 08.hand > 008
./cptest.exe < 09.hand > 009
./cptest.exe < 10.hand > 010
./cptest.exe < 11.hand > 011
./cptest.exe < 12.hand > 012
./cptest.exe < 13.hand > 013
./cptest.exe < 14.hand > 014
./cptest.exe < 15.hand > 015
./cptest.exe < 16.hand > 016
./cptest.exe < 17.hand > 017
./cptest.exe < 18.hand > 018
./cptest.exe < 19.hand > 019
./cptest.exe < 20.hand > 020
./cptest.exe < 21.hand > 021
./cptest.exe < 22.hand > 022
./cptest.exe < 23.hand > 023
./cptest.exe < 24.hand > 024
./cptest.exe < 25.hand > 025
./cptest.exe < 26.hand > 026
./cptest.exe < 27.hand > 027
./cptest.exe < 28.hand > 028
./cptest.exe < 29.hand > 029
./cptest.exe < 30.hand > 030
./cptest.exe < 40.hand > 040
./cptest.exe < 41.hand > 041

./gen.exe 3731 > 031
./gen.exe 13731 > 032
./gen.exe 23731 > 033
./gen.exe 33731 > 034
./gen.exe 43731 > 035
./gen.exe 53731 > 036
./gen.exe 63731 > 037
./gen.exe 73731 > 038
./gen.exe 83731 > 039


mkdir ../tests
for i in ???;do
echo Validating $i
./validator.exe <$i
echo Generating $i.a
./matrix_rad_ac.exe <$i >../tests/$i.a
mv $i ../tests/$i
done
rm *.exe
rm *.class
