#!/bin/sh

gcc cptest.c -o cptest.exe
g++ sval.cpp -lm -o sval.exe -O2
g++ sval.cpp -lm -o sval.exe -O2
g++ almost_at.cpp -lm -o almost_at.exe -O2

./cptest.exe < 01.hand > 001
./cptest.exe < 02.hand > 002
./cptest.exe < 03.hand > 003
./cptest.exe < 04.hand > 004
./cptest.exe < 05.hand > 005
./cptest.exe < 06.hand > 006
./cptest.exe < 07.hand > 007
./cptest.exe < 08.hand > 008
./cptest.exe < 09.hand > 009
./cptest.exe < 10.hand > 010
./cptest.exe < 11.hand > 011
./cptest.exe < 12.hand > 012
./cptest.exe < 13.hand > 013
./cptest.exe < 14.hand > 014
./cptest.exe < 15.hand > 015
./cptest.exe < 16.hand > 016
./cptest.exe < 17.hand > 017
./cptest.exe < 18.hand > 018
./cptest.exe < 19.hand > 019
./cptest.exe < 20.hand > 020
./cptest.exe < 21.hand > 021
./cptest.exe < 22.hand > 022
./cptest.exe < 23.hand > 023
./cptest.exe < 24.hand > 024
./cptest.exe < 25.hand > 025
./cptest.exe < 26.hand > 026
./cptest.exe < 27.hand > 027
./cptest.exe < 28.hand > 028
./cptest.exe < 29.hand > 029
./cptest.exe < 30.hand > 030
./cptest.exe < 31.hand > 031
./cptest.exe < 32.hand > 032
./cptest.exe < 33.hand > 033
./cptest.exe < 34.hand > 034
./cptest.exe < 35.hand > 035
./cptest.exe < 36.hand > 036
./cptest.exe < 37.hand > 037
./cptest.exe < 38.hand > 038
./cptest.exe < 39.hand > 039
./cptest.exe < 40.hand > 040
./cptest.exe < 41.hand > 041
./cptest.exe < 42.hand > 042
./cptest.exe < 43.hand > 043
./cptest.exe < 44.hand > 044
./cptest.exe < 45.hand > 045
./cptest.exe < 46.hand > 046
./cptest.exe < 47.hand > 047
./cptest.exe < 48.hand > 048
./cptest.exe < 49.hand > 049
./cptest.exe < 50.hand > 050
./cptest.exe < 51.hand > 051
./cptest.exe < 52.hand > 052
./cptest.exe < 53.hand > 053
./cptest.exe < 54.hand > 054
./cptest.exe < 55.hand > 055



mkdir ../tests
for i in ???;do
echo Validating $i
./sval.exe <$i
echo Generating $i.a
./almost_at.exe <$i >../tests/$i.a
mv $i ../tests/$i
done
rm *.exe
rm *.class
