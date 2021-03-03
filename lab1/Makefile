all: clean compileMain runMain test

compileMain: main.c
	gcc -o main main.c -std=c89

runMain: 
	./main
	
test: test.c
	gcc -o test -Dmain=_main main.c test.c -std=c89 
	./test

clean:
	rm -rf C_labs