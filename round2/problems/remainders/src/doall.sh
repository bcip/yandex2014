#!/bin/sh

gcc cptest.c -o cptest.exe
g++ rem_validator.cpp -lm -o rem_validator.exe -O2
g++ remainders_gen_rand.cpp -lm -o remainders_gen_rand.exe -O2
g++ remainders_it.cpp -lm -o remainders_it.exe -O2

./cptest.exe < 01.hand > 001
./cptest.exe < 02.hand > 002
./cptest.exe < 03.hand > 003
./cptest.exe < 11.hand > 011
./cptest.exe < 12.hand > 012
./cptest.exe < 13.hand > 013
./cptest.exe < 14.hand > 014
./cptest.exe < 15.hand > 015
./cptest.exe < 16.hand > 016
./cptest.exe < 17.hand > 017
./cptest.exe < 21.hand > 021

./remainders_gen_rand.exe 10 10000 300000 > 004
./remainders_gen_rand.exe 10 100000 300000 > 005
./remainders_gen_rand.exe 10 1000 300000 > 006
./remainders_gen_rand.exe 100 10000 300000 > 007
./remainders_gen_rand.exe 100 100000 300000 > 008
./remainders_gen_rand.exe 100 1000 300000 > 009
./remainders_gen_rand.exe 100 50000 300000 > 010
./remainders_gen_rand.exe 100 299990 300000 > 018
./remainders_gen_rand.exe 100 1 20 > 019
./remainders_gen_rand.exe 100 299000 300000 > 020
./remainders_gen_rand.exe 100 1 300000 > 022
./remainders_gen_rand.exe 99 1 300000 > 023
./remainders_gen_rand.exe 99 290000 300000 > 024
./remainders_gen_rand.exe 97 100000 300000 > 025
./remainders_gen_rand.exe 100 300000 300000 > 026


mkdir ../tests
for i in ???;do
echo Validating $i
./rem_validator.exe <$i
echo Generating $i.a
./remainders_it.exe <$i >../tests/$i.a
mv $i ../tests/$i
done
rm *.exe
rm *.class
