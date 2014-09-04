#!/bin/sh

g++ gen.cpp -lm -o gen.exe -O2
g++ validate.cpp -lm -o validate.exe -O2
g++ cycles_it.cpp -lm -o cycles_it.exe -O2


./gen.exe 3 small giant random > 001
./gen.exe 3 random random random > 002
./gen.exe 10 fib giant random > 003
./gen.exe 10 random random small > 004
./gen.exe 10 giant giant random > 005
./gen.exe 10 small small small > 006
./gen.exe 10 fib fib giant > 007
./gen.exe 10 giant random small > 008
./gen.exe 10 giant giant small > 009
./gen.exe 10 fib random small > 010
./gen.exe 10 fib giant small > 011
./gen.exe 10 random small small > 012
./gen.exe 10 giant random random > 013
./gen.exe 10 giant giant giant > 014
./gen.exe 10 fib fib fib > 015
./gen.exe 10 fib random random > 016
./gen.exe 10 fib small small > 017
./gen.exe 10 fib fib random > 018
./gen.exe 10 random random random > 019
./gen.exe 10 fib fib small > 020
./gen.exe 10 giant small small > 021
./gen.exe 10 fib giant giant > 022
./gen.exe 100 fib giant random > 023
./gen.exe 100 random random small > 024
./gen.exe 100 giant giant random > 025
./gen.exe 100 small small small > 026
./gen.exe 100 fib fib giant > 027
./gen.exe 100 giant random small > 028
./gen.exe 100 giant giant small > 029
./gen.exe 100 fib random small > 030
./gen.exe 100 fib giant small > 031
./gen.exe 100 random small small > 032
./gen.exe 100 giant random random > 033
./gen.exe 100 giant giant giant > 034
./gen.exe 100 fib fib fib > 035
./gen.exe 100 fib random random > 036
./gen.exe 100 fib small small > 037
./gen.exe 100 fib fib random > 038
./gen.exe 100 random random random > 039
./gen.exe 100 fib fib small > 040
./gen.exe 100 giant small small > 041
./gen.exe 100 fib giant giant > 042
./gen.exe 30000 fib giant random > 043
./gen.exe 30000 random random small > 044
./gen.exe 30000 giant giant random > 045
./gen.exe 30000 small small small > 046
./gen.exe 30000 fib fib giant > 047
./gen.exe 30000 giant random small > 048
./gen.exe 30000 giant giant small > 049
./gen.exe 30000 fib random small > 050
./gen.exe 30000 fib giant small > 051
./gen.exe 30000 random small small > 052
./gen.exe 30000 giant random random > 053
./gen.exe 30000 giant giant giant > 054
./gen.exe 30000 fib fib fib > 055
./gen.exe 30000 fib random random > 056
./gen.exe 30000 fib small small > 057
./gen.exe 30000 fib fib random > 058
./gen.exe 30000 random random random > 059
./gen.exe 30000 fib fib small > 060
./gen.exe 30000 giant small small > 061
./gen.exe 30000 fib giant giant > 062
./gen.exe 30000 sqrt sqrt sqrt > 063


mkdir ../tests
for i in ???;do
echo Validating $i
./validate.exe <$i
echo Generating $i.a
./cycles_it.exe <$i >../tests/$i.a
mv $i ../tests/$i
done
rm *.exe
rm *.class
