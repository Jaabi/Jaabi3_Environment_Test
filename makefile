default:
	gcc -o testprog ./testfile.c
	chmod a+x ./testprog

run:
	./testprog
