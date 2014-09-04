#!/bin/sh

gcc cptest.c -o cptest.exe
g++ gen_small_plus_one.cpp -lm -o gen_small_plus_one.exe -O2
g++ validator.cpp -lm -o validator.exe -O2
g++ gen_big_minus_one.cpp -lm -o gen_big_minus_one.exe -O2
g++ gen_big.cpp -lm -o gen_big.exe -O2
g++ gen_from_zero.cpp -lm -o gen_from_zero.exe -O2
g++ gen_small_minus_one.cpp -lm -o gen_small_minus_one.exe -O2
g++ gen_big_plus_one.cpp -lm -o gen_big_plus_one.exe -O2
g++ gen_pali.cpp -lm -o gen_pali.exe -O2
g++ gen_small.cpp -lm -o gen_small.exe -O2
javac EvilPalindromAF.java

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
./cptest.exe < 82.hand > 082
./cptest.exe < 83.hand > 083
./cptest.exe < 84.hand > 084
./cptest.exe < 85.hand > 085
./cptest.exe < 86.hand > 086
./cptest.exe < 87.hand > 087

./gen_small_plus_one.exe 1235 > 018
./gen_small_plus_one.exe 1233 > 019
./gen_small_plus_one.exe 12 > 020
./gen_small_plus_one.exe 135 > 021
./gen_small_plus_one.exe 125 > 022
./gen_small_plus_one.exe 123512 > 023
./gen_small_plus_one.exe 1215 > 024
./gen_from_zero.exe 123 > 025
./gen_from_zero.exe 145 > 026
./gen_from_zero.exe 3981 > 027
./gen_from_zero.exe 12309 > 028
./gen_from_zero.exe 8472 > 029
./gen_small_minus_one.exe 1231 > 030
./gen_small_minus_one.exe 11231 > 031
./gen_small_minus_one.exe 21231 > 032
./gen_small_minus_one.exe 31231 > 033
./gen_small_minus_one.exe 41231 > 034
./gen_small_minus_one.exe 51231 > 035
./gen_small_minus_one.exe 61231 > 036
./gen_small.exe 12312 > 037
./gen_small.exe 22312 > 038
./gen_small.exe 32312 > 039
./gen_small.exe 42312 > 040
./gen_small.exe 52312 > 041
./gen_small.exe 62312 > 042
./gen_small.exe 72312 > 043
./gen_small.exe 82312 > 044
./gen_big_minus_one.exe 2312 > 045
./gen_big_minus_one.exe 12312 > 046
./gen_big_minus_one.exe 22312 > 047
./gen_big_minus_one.exe 32312 > 048
./gen_big_minus_one.exe 42312 > 049
./gen_big_plus_one.exe 21312 > 050
./gen_big_plus_one.exe 12231 > 051
./gen_big_plus_one.exe 13231 > 052
./gen_big_plus_one.exe 14231 > 053
./gen_big_plus_one.exe 15231 > 054
./gen_big_plus_one.exe 16231 > 055
./gen_big_plus_one.exe 17231 > 056
./gen_big.exe 86123 > 057
./gen_big.exe 16123 > 058
./gen_big.exe 26123 > 059
./gen_big.exe 36123 > 060
./gen_big.exe 46123 > 061
./gen_big.exe 56123 > 062
./gen_big.exe 66123 > 063
./gen_big.exe 76123 > 064
./gen_big.exe 86123 > 065
./gen_big.exe 96123 > 066
./gen_big.exe 6123 > 067
./gen_big.exe 816123 > 068
./gen_big.exe 826123 > 069
./gen_big.exe 836123 > 070
./gen_big.exe 846123 > 071
./gen_pali.exe 12378 > 072
./gen_pali.exe 2378 > 073
./gen_pali.exe 22378 > 074
./gen_pali.exe 32378 > 075
./gen_pali.exe 42378 > 076
./gen_pali.exe 52378 > 077
./gen_pali.exe 62378 > 078
./gen_pali.exe 72378 > 079
./gen_pali.exe 82378 > 080
./gen_pali.exe 92378 > 081


mkdir ../tests
for i in ???;do
echo Validating $i
./validator.exe <$i
echo Generating $i.a
java EvilPalindromAF <$i >../tests/$i.a
mv $i ../tests/$i
done
rm *.exe
rm *.class
