default:
	gcc -o testprog ./testfile.c
	chmod a+x ./testprog

clean: 
	rm -f ./testprog

run:
	./testprog || { echo "\n./testprog does not exist. Try 'make'. Exiting...\n"; exit 1; }
