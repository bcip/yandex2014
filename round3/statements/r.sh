#!/bin/bash

pdflatex 140615.en.tex
pdflatex 140615.en.tex
pdflatex 140615.ru.tex
pdflatex 140615.ru.tex

rm *.log
rm *.aux
