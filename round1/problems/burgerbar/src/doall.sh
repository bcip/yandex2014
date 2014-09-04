#!/bin/bash

g++ solution.cpp -o sol.exe || exit 1
g++ validate.cpp -o validate.exe || exit 1
g++ generate.cpp -o gen.exe || exit 1

./gen.exe

mkdir ../tests

for i in ???
do
    echo Validating $i
    ./validate.exe <$i
    echo Generating $i.a
    ./sol.exe <$i >../tests/$i.a
    mv $i ../tests
done

rm *.class
rm *.exe
