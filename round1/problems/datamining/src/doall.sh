#!/bin/bash

g++ solution.cpp -o sol.exe || exit 1
g++ validate.cpp -o validate.exe || exit 1
g++ generate.cpp -o gen.exe || exit 1
gcc cptest.c -o cptest.exe || exit 1

for i in *.hand; do
./cptest.exe <$i >0${i:0:2}
done



./gen.exe

mkdir ../tests

for i in ???
do
    echo Validating $i
    ./validate.exe <$i || exit 1
    echo Generating $i.a
    ./sol.exe <$i >../tests/$i.a
    mv $i ../tests
done

rm *.class
rm *.exe
