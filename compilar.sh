#! /bin/bash

gcc -Wall -pedantic -c src/tad.c
gcc -Wall -pedantic -c src/arquivo.c
gcc -Wall -pedantic -c src/func.c
gcc -Wall -pedantic -c src/main.c
gcc -Wall -pedantic -o Projeto_AED_I.out main.o tad.o arquivo.o func.o

rm *.o

