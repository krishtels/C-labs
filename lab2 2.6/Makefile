all: clean compileMain test

compileMain: main.c
	gcc -o main main.c -std=c89 -lm

runMain: 
	./main
	
test: test.c
	gcc -o test -Dmain=_main main.c test.c -std=c89 -lm
	./test

clean:
	rm -rf lab2