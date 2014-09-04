#!/bin/sh

gcc cptest.c -o cptest.exe
g++ validator.cpp -lm -o validator.exe -O2
g++ gen.cpp -lm -o gen.exe -O2
g++ solution.cpp -lm -o solution.exe -O2

./cptest.exe < 01.hand > 001
./cptest.exe < 02.hand > 002
./cptest.exe < 03.hand > 003
./cptest.exe < 44.hand > 044

./gen.exe random 10 10 1 > 004
./gen.exe random 10 10 2 > 005
./gen.exe random 10 10 3 > 006
./gen.exe random 10 10 4 > 007
./gen.exe random 10 1000 5 > 008
./gen.exe sum 10 10 1 > 009
./gen.exe sum 10 10 2 > 010
./gen.exe sum 10 10 3 > 011
./gen.exe sum 10 10 4 > 012
./gen.exe sum 10 500 5 > 013
./gen.exe big_sides 10 1000 1 > 014
./gen.exe big_sides 10 1000 2 > 015
./gen.exe big_sides 10 1000 3 > 016
./gen.exe big_sides 10 1000 4 > 017
./gen.exe big_sides 10 1000 5 > 018
./gen.exe big_sum 10 1000 1 > 019
./gen.exe big_sum 10 1000 2 > 020
./gen.exe big_sum 10 1000 3 > 021
./gen.exe big_sum 10 1000 4 > 022
./gen.exe big_sum 10 1000 5 > 023
./gen.exe random 100 1000 1 > 024
./gen.exe sum 100 500 2 > 025
./gen.exe big_sides 100 1000 3 > 026
./gen.exe big_sum 100 1000 4 > 027
./gen.exe random 200 1000 5 > 028
./gen.exe sum 200 500 1 > 029
./gen.exe big_sides 200 1000 2 > 030
./gen.exe big_sum 200 1000 3 > 031
./gen.exe random 2000 1000 4 > 032
./gen.exe random 2000 1000 5 > 033
./gen.exe random 2000 1000 6 > 034
./gen.exe sum 2000 500 1 > 035
./gen.exe sum 2000 500 2 > 036
./gen.exe sum 2000 500 3 > 037
./gen.exe big_sides 2000 1000 4 > 038
./gen.exe big_sides 2000 1000 5 > 039
./gen.exe big_sides 2000 1000 6 > 040
./gen.exe big_sum 2000 1000 1 > 041
./gen.exe big_sum 2000 1000 2 > 042
./gen.exe big_sum 2000 1000 3 > 043


mkdir ../tests
for i in ???;do
echo Validating $i
./validator.exe <$i
echo Generating $i.a
./solution.exe <$i >../tests/$i.a
mv $i ../tests/$i
done
rm *.exe
rm *.class
