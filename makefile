all:
	gcc -o picmaker firstpic.c
run: picmaker
	./picmaker
