#!/bin/sh

gcc cptest.c -o cptest.exe
g++ regions_gen.cpp -lm -o regions_gen.exe -O2
g++ regions_gen_rand.cpp -lm -o regions_gen_rand.exe -O2
g++ regions_gen_spiral.cpp -lm -o regions_gen_spiral.exe -O2
g++ regions_gen_spiral2.cpp -lm -o regions_gen_spiral2.exe -O2
g++ regions_hand_gen.cpp -lm -o regions_hand_gen.exe -O2
g++ regions_validator.cpp -lm -o regions_validator.exe -O2
g++ regions.cpp -lm -o regions.exe -O2

./cptest.exe < 01.hand > 001
./cptest.exe < 02.hand > 002
./cptest.exe < 03.hand > 003
./cptest.exe < 04.hand > 004

./regions_gen_rand.exe 2000 2000 1000000 > 005
./regions_gen.exe 37 37 10 > 006
./regions_gen.exe 37 37 20 > 007
./regions_gen.exe 37 37 30 > 008
./regions_gen.exe 37 37 40 > 009
./regions_gen.exe 37 37 50 > 010
./regions_gen.exe 37 37 60 > 011
./regions_gen.exe 37 37 70 > 012
./regions_gen.exe 37 37 80 > 013
./regions_gen.exe 37 37 90 > 014
./regions_gen.exe 37 37 100 > 015
./regions_gen.exe 37 37 1 > 016
./regions_gen.exe 1 100 30 > 017
./regions_gen.exe 100 1 70 > 018
./regions_gen.exe 37 37 1 > 019
./regions_gen.exe 37 37 99 > 020
./regions_gen.exe 1 999 1 > 021
./regions_gen.exe 999 1 99 > 022
./regions_gen_rand.exe 1998 2000 1 > 023
./regions_gen_rand.exe 2000 1999 2 > 024
./regions_gen_rand.exe 2000 2000 999998 > 025
./regions_gen_rand.exe 2000 1989 999997 > 026
./regions_gen_rand.exe 2000 2000 300000 > 027
./regions_gen_rand.exe 2000 2000 500000 > 028
./regions_gen_spiral.exe 5 5 500000 > 029
./regions_gen_spiral.exe 6 6 500000 > 030
./regions_gen_spiral.exe 1999 2000 500000 > 031
./regions_gen_spiral.exe 2000 2000 500000 > 032
./regions_gen_spiral.exe 1999 1999 500000 > 033
./regions_gen_spiral2.exe 2000 2000 500000 > 034
./regions_hand_gen.exe 500000 0 > 035
./regions_hand_gen.exe 500000 1 > 036
./regions_hand_gen.exe 500000 2 > 037
./regions_gen_rand.exe 1 1 1 > 038
./regions_gen_rand.exe 1 1 999999 > 039
./regions_gen_rand.exe 1 2000 10000 > 040
./regions_gen_rand.exe 2000 1 990000 > 041


mkdir ../tests
for i in ???;do
echo Validating $i
./regions_validator.exe <$i
echo Generating $i.a
./regions.exe <$i >../tests/$i.a
mv $i ../tests/$i
done
rm *.exe
rm *.class
