#!/bin/sh

g++ validate.cpp -lm -o validate.exe -O2
g++ gen.cpp -lm -o gen.exe -O2
g++ solution.cpp -lm -o solution.exe -O2


./gen.exe random 2 3 3 > 001
./gen.exe random 2 3 10 > 002
./gen.exe random 2 2 10 > 003
./gen.exe good 10 5 40 0 > 004
./gen.exe good 10 5 40 1 > 005
./gen.exe good 10 5 40 9 > 006
./gen.exe good 10 5 40 10 > 007
./gen.exe good 10 6 40 0 > 008
./gen.exe good 10 6 40 1 > 009
./gen.exe good 10 6 40 9 > 010
./gen.exe good 10 6 40 10 > 011
./gen.exe random 10 5 10 > 012
./gen.exe random 10 7 10 > 013
./gen.exe random 10 9 10 > 014
./gen.exe random 10 2 10 > 015
./gen.exe random 10 3 10 > 016
./gen.exe random 10 5 10 > 017
./gen.exe random 10 7 10 > 018
./gen.exe random 10 9 10 > 019
./gen.exe random 10 7 7 > 020
./gen.exe random 10 9 9 > 021
./gen.exe random 10 4 10 > 022
./gen.exe random 10 6 10 > 023
./gen.exe random 10 8 10 > 024
./gen.exe random 10 2 10 > 025
./gen.exe random 10 4 10 > 026
./gen.exe random 10 6 10 > 027
./gen.exe random 10 8 10 > 028
./gen.exe random 10 10 10 > 029
./gen.exe random 10 6 6 > 030
./gen.exe random 10 8 8 > 031
./gen.exe good 100000 5 100 0 > 032
./gen.exe good 100000 5 100 1 > 033
./gen.exe good 100000 5 100 99999 > 034
./gen.exe good 100000 5 100 100000 > 035
./gen.exe good 100000 6 100 0 > 036
./gen.exe good 100000 6 100 1 > 037
./gen.exe good 100000 6 100 99999 > 038
./gen.exe good 100000 6 100 100000 > 039
./gen.exe random 100000 5 100 > 040
./gen.exe random 100000 7 100 > 041
./gen.exe random 100000 9 100 > 042
./gen.exe random 100000 51 100 > 043
./gen.exe random 100000 2 100000 > 044
./gen.exe random 100000 5 100000 > 045
./gen.exe random 100000 7 100000 > 046
./gen.exe random 100000 9 100000 > 047
./gen.exe random 100000 50001 100000 > 048
./gen.exe random 100000 2 100 > 049
./gen.exe random 100000 6 100 > 050
./gen.exe random 100000 8 100 > 051
./gen.exe random 100000 10 100 > 052
./gen.exe random 100000 50 100 > 053
./gen.exe random 100000 2 100000 > 054
./gen.exe random 100000 4 100000 > 055
./gen.exe random 100000 6 100000 > 056
./gen.exe random 100000 8 100000 > 057
./gen.exe random 100000 50000 100000 > 058


mkdir ../tests
for i in ???;do
echo Validating $i
./validate.exe <$i
echo Generating $i.a
./solution.exe <$i >../tests/$i.a
mv $i ../tests/$i
done
rm *.exe
rm *.class
