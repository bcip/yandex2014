#!/bin/sh

gcc cptest.c -o cptest.exe
g++ validate.cpp -lm -o validate.exe -O2
g++ genMax.cpp -lm -o genMax.exe -O2
g++ genRand.cpp -lm -o genRand.exe -O2
g++ musicworld_pkun.cpp -lm -o musicworld_pkun.exe -O2

./cptest.exe < 01.hand > 001
./cptest.exe < 02.hand > 002
./cptest.exe < 03.hand > 003

./genRand.exe 1 > 004
./genRand.exe 2 > 005
./genRand.exe 3 > 006
./genRand.exe 4 > 007
./genRand.exe 5 > 008
./genRand.exe 6 > 009
./genRand.exe 7 > 010
./genRand.exe 8 > 011
./genRand.exe 9 > 012
./genRand.exe 10 > 013
./genRand.exe 11 > 014
./genRand.exe 12 > 015
./genRand.exe 13 > 016
./genRand.exe 14 > 017
./genRand.exe 15 > 018
./genRand.exe 16 > 019
./genRand.exe 17 > 020
./genRand.exe 18 > 021
./genRand.exe 19 > 022
./genRand.exe 20 > 023
./genRand.exe 5000 > 024
./genRand.exe 10000 > 025
./genRand.exe 15000 > 026
./genRand.exe 20000 > 027
./genRand.exe 25000 > 028
./genRand.exe 30000 > 029
./genRand.exe 35000 > 030
./genRand.exe 40000 > 031
./genRand.exe 45000 > 032
./genRand.exe 50000 > 033
./genRand.exe 55000 > 034
./genRand.exe 60000 > 035
./genRand.exe 65000 > 036
./genRand.exe 70000 > 037
./genRand.exe 75000 > 038
./genRand.exe 80000 > 039
./genRand.exe 85000 > 040
./genRand.exe 90000 > 041
./genRand.exe 95000 > 042
./genRand.exe 100000 > 043
./genMax.exe 100000 > 044


mkdir ../tests
for i in ???;do
echo Validating $i
./validate.exe <$i
echo Generating $i.a
./musicworld_pkun.exe <$i >../tests/$i.a
mv $i ../tests/$i
done
rm *.exe
rm *.class
