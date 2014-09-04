#!/bin/sh

gcc cptest.c -o cptest.exe
g++ e0.cpp -lm -o e0.exe -O2
g++ gen_small_rand.cpp -lm -o gen_small_rand.exe -O2
g++ validator.cpp -lm -o validator.exe -O2
g++ ar_prog.cpp -lm -o ar_prog.exe -O2
g++ e123.cpp -lm -o e123.exe -O2
g++ gen_less_numbers.cpp -lm -o gen_less_numbers.exe -O2
g++ gen_perm.cpp -lm -o gen_perm.exe -O2
g++ gen_rand.cpp -lm -o gen_rand.exe -O2
javac IntervalsAF.java

./cptest.exe < 01.hand > 001
./cptest.exe < 02.hand > 002
./cptest.exe < 03.hand > 003
./cptest.exe < 04.hand > 004
./cptest.exe < 05.hand > 005
./cptest.exe < 48.hand > 048
./cptest.exe < 49.hand > 049
./cptest.exe < 50.hand > 050
./cptest.exe < 51.hand > 051

./gen_small_rand.exe 1234 > 006
./gen_small_rand.exe 11234 > 007
./gen_small_rand.exe 12234 > 008
./gen_small_rand.exe 13234 > 009
./gen_small_rand.exe 14234 > 010
./gen_small_rand.exe 15234 > 011
./gen_small_rand.exe 16234 > 012
./gen_small_rand.exe 17234 > 013
./gen_small_rand.exe 18234 > 014
./gen_less_numbers.exe 1234 > 015
./gen_less_numbers.exe 11234 > 016
./gen_less_numbers.exe 12234 > 017
./gen_less_numbers.exe 13234 > 018
./gen_less_numbers.exe 14234 > 019
./gen_less_numbers.exe 15234 > 020
./gen_less_numbers.exe 16234 > 021
./gen_perm.exe 1234 > 022
./gen_perm.exe 11234 > 023
./gen_perm.exe 12234 > 024
./gen_perm.exe 13234 > 025
./gen_perm.exe 14234 > 026
./gen_perm.exe 15234 > 027
./gen_perm.exe 16234 > 028
./gen_perm.exe 17234 > 029
./gen_perm.exe 18234 > 030
./gen_perm.exe 19234 > 031
./gen_perm.exe 112234 > 032
./gen_rand.exe 1234 > 033
./gen_rand.exe 11234 > 034
./gen_rand.exe 12234 > 035
./gen_rand.exe 13234 > 036
./gen_rand.exe 14234 > 037
./gen_rand.exe 15234 > 038
./gen_rand.exe 16234 > 039
./gen_rand.exe 17234 > 040
./gen_rand.exe 18234 > 041
./gen_rand.exe 19234 > 042
./gen_rand.exe 24234 > 043
./gen_rand.exe 23234 > 044
./gen_rand.exe 21234 > 045
./e123.exe 300000 > 046
./e123.exe 299999 > 047
./e0.exe 300000 1 > 052
./e0.exe 300000 2 > 053
./e0.exe 300000 3 > 054
./ar_prog.exe 300000 0 > 055
./ar_prog.exe 300000 1 > 056
./ar_prog.exe 300000 2 > 057
./ar_prog.exe 300000 10 > 058
./ar_prog.exe 300000 3 > 059
./ar_prog.exe 300000 100 > 060
./ar_prog.exe 300000 200 > 061
./ar_prog.exe 300000 1000 > 062
./ar_prog.exe 300000 11111 > 063
./ar_prog.exe 300000 150001 > 064
./ar_prog.exe 300000 255555 > 065


mkdir ../tests
for i in ???;do
echo Validating $i
./validator.exe <$i
echo Generating $i.a
java IntervalsAF <$i >../tests/$i.a
mv $i ../tests/$i
done
rm *.exe
rm *.class
