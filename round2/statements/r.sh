#!/bin/bash

pdflatex 140606.en.tex
pdflatex 140606.en.tex
pdflatex 140606.ru.tex
pdflatex 140606.ru.tex

rm *.log
rm *.aux
