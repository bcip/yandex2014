#!/bin/sh

gcc cptest.c -o cptest.exe
g++ validate.cpp -lm -o validate.exe -O2
g++ genRand.cpp -lm -o genRand.exe -O2
g++ gen.cpp -lm -o gen.exe -O2
g++ stack_kadr.cpp -lm -o stack_kadr.exe -O2

./cptest.exe < 42.hand > 042
./cptest.exe < 43.hand > 043
./cptest.exe < 44.hand > 044

./gen.exe 0 50 prefix 512 256 128 64 32 16 8 4 2 1 > 001
./gen.exe 0 50 prefix 512 256 128 64 32 16 8 4 2 > 002
./gen.exe 0 20 prefix 512 256 128 64 32 16 8 4 2 1 > 003
./gen.exe 0 80 prefix 512 256 128 64 32 16 8 4 2 1 > 004
./gen.exe 0 20 prefix 512 256 128 64 32 16 8 4 2 > 005
./gen.exe 0 80 prefix 512 256 128 64 32 16 8 4 2 > 006
./gen.exe 0 60 prefix 1024 > 007
./gen.exe 0 40 prefix 512 512 > 008
./gen.exe 0 60 prefix 512 256 128 64 16 16 16 4 4 2 2 2 2 > 009
./gen.exe 10 20 prefix 512 256 128 64 32 16 8 4 2 1 > 010
./gen.exe 10 80 prefix 512 256 128 64 32 16 8 4 2 1 > 011
./gen.exe 10 20 prefix 512 256 128 64 32 16 8 4 2 > 012
./gen.exe 10 80 prefix 512 256 128 64 32 16 8 4 2 > 013
./gen.exe 99990 30 prefix 512 256 128 64 32 16 8 4 2 1 > 014
./gen.exe 99990 30 prefix 256 64 16 4 1 > 015
./gen.exe 99990 70 prefix 512 256 128 64 32 16 8 4 2 1 > 016
./gen.exe 99991 30 prefix 512 256 128 64 32 16 8 4 2 > 017
./gen.exe 99991 70 prefix 512 256 128 64 32 16 8 4 2 > 018
./gen.exe 99999 80 prefix 1024 > 019
./gen.exe 99999 10 prefix 1 > 020
./gen.exe 99999 50 prefix 1 > 021
./gen.exe 99999 90 prefix 1 > 022
./gen.exe 99999 100 prefix 1024 > 023
./gen.exe 100000 10 prefix > 024
./gen.exe 100000 20 prefix > 025
./gen.exe 100000 30 prefix > 026
./gen.exe 100000 40 prefix > 027
./gen.exe 100000 50 prefix > 028
./gen.exe 100000 60 prefix > 029
./gen.exe 100000 70 prefix > 030
./gen.exe 100000 80 prefix > 031
./gen.exe 100000 90 prefix > 032
./gen.exe 100000 100 prefix > 033
./gen.exe 99989 30 prefix 512 512 256 128 64 32 16 8 4 2 1 > 034
./gen.exe 99989 30 prefix 512 256 128 64 32 16 8 4 2 1 1 > 035
./gen.exe 99970 30 prefix 512 256 128 64 32 16 2 2 2 2 2 2 2 2 > 036
./gen.exe 99970 30 prefix 512 256 128 64 32 16 4 4 4 4 > 037
./gen.exe 99970 30 prefix 512 256 128 64 32 16 4 4 2 2 2 2 > 038
./gen.exe 99970 30 prefix 512 256 128 64 16 16 16 4 4 2 2 2 2 > 039
./gen.exe 99970 30 prefix 512 256 128 64 32 16 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 > 040
./gen.exe 4 80 prefix 256 256 256 256 > 041


mkdir ../tests
for i in ???;do
echo Validating $i
./validate.exe <$i
echo Generating $i.a
./stack_kadr.exe <$i >../tests/$i.a
mv $i ../tests/$i
done
rm *.exe
rm *.class
