all: clex

clex: clex.o app.o
	gcc -o clex -g clex.o app.o

clex.o: ../src/clex.c
	gcc -c -g ../src/clex.c

app.o: ../src/app.c
	gcc -c -g ../src/app.c