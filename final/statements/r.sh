#!/bin/bash

pdflatex 140801.ru.tex
pdflatex 140801.ru.tex

pdflatex 140801.en.tex
pdflatex 140801.en.tex

pdflatex 140801analysis.ru.tex
pdflatex 140801analysis.ru.tex

pdflatex 140801analysis.en.tex
pdflatex 140801analysis.en.tex

rm *.dvi
rm *.aux
rm *.log
rm *.1
rm *.2
rm *.3
rm *.4
rm *.5
rm *.6
rm *.7
rm *.8
