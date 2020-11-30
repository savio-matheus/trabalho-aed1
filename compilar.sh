#! /bin/bash

gcc -Wall -pedantic -c src/tad.c
gcc -Wall -pedantic -c src/main.c
gcc -Wall -pedantic -o Projeto_AED_I.out main.o tad.o

rm *.o

