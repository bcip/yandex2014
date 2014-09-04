#!/bin/sh

gcc cptest.c -o cptest.exe
g++ validate.cpp -lm -o validate.exe -O2
g++ generate.cpp -lm -o generate.exe -O2
gcc cube_sn.c -lm -o cube_sn.exe -O2

./cptest.exe < 01.hand > 001
./cptest.exe < 02.hand > 002

./generate.exe f 0 1 > 003
./generate.exe f 0 -1 > 004
./generate.exe f 1 1 > 005
./generate.exe f 1 -1 > 006
./generate.exe f 2 1 > 007
./generate.exe f 2 -1 > 008
./generate.exe f 3 1 > 009
./generate.exe f 3 -1 > 010
./generate.exe f 4 1 > 011
./generate.exe f 4 -1 > 012
./generate.exe f 5 1 > 013
./generate.exe f 5 -1 > 014
./generate.exe f 6 1 > 015
./generate.exe f 6 -1 > 016
./generate.exe f 7 1 > 017
./generate.exe f 7 -1 > 018
./generate.exe f 8 1 > 019
./generate.exe f 8 -1 > 020
./generate.exe f 9 1 > 021
./generate.exe f 9 -1 > 022
./generate.exe f 10 1 > 023
./generate.exe f 10 -1 > 024
./generate.exe f 11 0 > 025
./generate.exe f 12 0 > 026
./generate.exe f 13 0 > 027
./generate.exe f 14 0 > 028
./generate.exe f 15 0 > 029
./generate.exe f 16 0 > 030
./generate.exe f 17 0 > 031
./generate.exe f 18 0 > 032
./generate.exe f 19 0 > 033
./generate.exe f 20 0 > 034
./generate.exe f 21 0 > 035
./generate.exe f 22 0 > 036
./generate.exe f 23 0 > 037
./generate.exe f 24 0 > 038
./generate.exe f 25 0 > 039
./generate.exe f 26 0 > 040
./generate.exe f 27 0 > 041
./generate.exe f 28 0 > 042
./generate.exe f 29 0 > 043
./generate.exe f 30 0 > 044
./generate.exe f 31 0 > 045
./generate.exe f 32 0 > 046
./generate.exe f 33 0 > 047
./generate.exe f 34 0 > 048
./generate.exe r abc > 049
./generate.exe r def > 050
./generate.exe r ghi > 051
./generate.exe r jkl > 052
./generate.exe r mno > 053
./generate.exe g abc > 054
./generate.exe g def > 055
./generate.exe g ghi > 056
./generate.exe g jkl > 057
./generate.exe g mno > 058
./generate.exe b abc > 059
./generate.exe b def > 060
./generate.exe b ghi > 061
./generate.exe b jkl > 062
./generate.exe b mno > 063
./generate.exe f 0 2 > 064
./generate.exe f 1 2 > 065
./generate.exe f 2 2 > 066
./generate.exe f 3 2 > 067
./generate.exe f 4 2 > 068
./generate.exe f 5 2 > 069
./generate.exe f 6 2 > 070
./generate.exe f 7 2 > 071
./generate.exe f 8 2 > 072
./generate.exe f 9 2 > 073
./generate.exe f 10 2 > 074


mkdir ../tests
for i in ???;do
echo Validating $i
./validate.exe <$i
echo Generating $i.a
./cube_sn.exe <$i >../tests/$i.a
mv $i ../tests/$i
done
rm *.exe
rm *.class
