#!/bin/sh

gcc cptest.c -o cptest.exe
g++ validate.cpp -lm -o validate.exe -O2
g++ generate.cpp -lm -o generate.exe -O2
gcc aliens_sn.c -lm -o aliens_sn.exe -O2

./cptest.exe < 01.hand > 001
./cptest.exe < 02.hand > 002

./generate.exe s 1 142857 > 003
./generate.exe s 1 1 i 9 2 x > 004
./generate.exe s 1 1 i 5 2 i 5 3 x > 005
./generate.exe i 4 1 i 4 2 i 4 3 i 4 4 x > 006
./generate.exe s 2 1 i 6 4 x > 007
./generate.exe s 3 1 i 5 4 x > 008
./generate.exe r 20 1 2 > 009
./generate.exe r 20 1 5 > 010
./generate.exe r 20 1 10 > 011
./generate.exe s 1000000 1 x > 012
./generate.exe i 1000000 1000000 x > 013
./generate.exe s 10 1 i 999990 1000000 x > 014
./generate.exe s 20 1 i 999980 999999 x > 015
./generate.exe r 1000000 999999 1000000 x > 016
./generate.exe r 10000 1 10000 x > 017
./generate.exe r 100000 1 100000 x > 018
./generate.exe r 1000000 1 1000000 x1 > 019
./generate.exe r 1000000 1 1000000 x2 > 020
./generate.exe i 2 1 > 021
./generate.exe s 2 1 > 022
./generate.exe i 3 1 > 023


mkdir ../tests
for i in ???;do
echo Validating $i
./validate.exe <$i
echo Generating $i.a
./aliens_sn.exe <$i >../tests/$i.a
mv $i ../tests/$i
done
rm *.exe
rm *.class
