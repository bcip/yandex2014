#!/bin/sh

gcc cptest.c -o cptest.exe
g++ validator.cpp -lm -o validator.exe -O2
g++ gen.cpp -lm -o gen.exe -O2
g++ matching_rad_ac.cpp -lm -o matching_rad_ac.exe -O2

./cptest.exe < 01.hand > 001
./cptest.exe < 02.hand > 002

./gen.exe 1 1 0 > 003
./gen.exe 1 1 1 > 004
./gen.exe 3 5 6 > 005
./gen.exe 4 3 10 > 006
./gen.exe 5 5 5 > 007
./gen.exe 5 9 11 > 008
./gen.exe 2 1 0 > 009
./gen.exe 2 1 1 > 010
./gen.exe 2 1 2 > 011
./gen.exe 1 2 1 > 012
./gen.exe 10 100 0 > 013
./gen.exe 10 100 1 > 014
./gen.exe 10 100 2 > 015
./gen.exe 10 100 10 > 016
./gen.exe 10 100 100 > 017
./gen.exe 10 100 200 > 018
./gen.exe 10 100 300 > 019
./gen.exe 10 100 400 > 020
./gen.exe 10 100 500 > 021
./gen.exe 10 100 600 > 022
./gen.exe 10 100 700 > 023
./gen.exe 10 100 800 > 024
./gen.exe 10 100 900 > 025
./gen.exe 10 100 1000 > 026
./gen.exe 10 100 999 > 027
./gen.exe 10 100 998 > 028
./gen.exe 10 99 901 > 029
./gen.exe 9 100 825 > 030


mkdir ../tests
for i in ???;do
echo Validating $i
./validator.exe <$i
echo Generating $i.a
./matching_rad_ac.exe <$i >../tests/$i.a
mv $i ../tests/$i
done
rm *.exe
rm *.class
