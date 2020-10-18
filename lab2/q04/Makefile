q02 : main.o add.o divide.o multiply.o subtract.o 
	gcc -o q02 main.o add.o divide.o multiply.o subtract.o 
	ar rcs ./lib/libq02.a add.o divide.o multiply.o subtract.o
	gcc -o ./lib/lq02 -L./lib main.c -lq02
main.o : main.c
	gcc -c main.c	
add.o : add.c
	gcc -c add.c
divide.o : divide.c
	gcc -c divide.c
multiply.o : multiply.c
	gcc -c multiply.c
subtract.o : subtract.c
	gcc -c subtract.c

