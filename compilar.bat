gcc -Wall -pedantic -c src\tad.c
gcc -Wall -pedantic -c src\main.c
gcc -Wall -pedantic -o Projeto_AED_I.exe main.o tad.o

del *.o
