#!/bin/sh

gcc cptest.c -o cptest.exe
g++ gen.cpp -lm -o gen.exe -O2
g++ gen_large.cpp -lm -o gen_large.exe -O2
g++ sun.cpp -lm -o sun.exe -O2
g++ validator.cpp -lm -o validator.exe -O2
javac DistanceAF.java

./cptest.exe < 01.hand > 001
./cptest.exe < 02.hand > 002
./cptest.exe < 03.hand > 003
./cptest.exe < 04.hand > 004
./cptest.exe < 05.hand > 005

./gen.exe 1234 > 006
./gen.exe 11234 > 007
./gen.exe 21234 > 008
./gen.exe 31234 > 009
./gen.exe 41234 > 010
./gen.exe 51234 > 011
./gen.exe 61234 > 012
./gen.exe 71234 > 013
./gen.exe 81234 > 014
./gen.exe 91234 > 015
./gen.exe 101234 > 016
./gen_large.exe 1231 > 017
./gen_large.exe 10231 > 018
./gen_large.exe 11231 > 019
./gen_large.exe 12231 > 020
./gen_large.exe 13231 > 021
./gen_large.exe 14231 > 022
./gen_large.exe 15231 > 023
./gen_large.exe 16231 > 024
./gen_large.exe 17231 > 025
./gen_large.exe 18231 > 026
./gen_large.exe 19231 > 027
./gen_large.exe 231 > 028
./gen_large.exe 2231 > 029
./gen_large.exe 3231 > 030
./sun.exe 100000 > 031
./sun.exe 99999 > 032


mkdir ../tests
for i in ???;do
echo Validating $i
./validator.exe <$i
echo Generating $i.a
java DistanceAF <$i >../tests/$i.a
mv $i ../tests/$i
done
rm *.exe
rm *.class
