#!/bin/bash

pdflatex 140601.en.tex
pdflatex 140601.en.tex
pdflatex 140601.ru.tex
pdflatex 140601.ru.tex

rm *.log
rm *.aux
