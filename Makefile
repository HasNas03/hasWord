all: hasWord

hasWord: hasWord.o parseArgs.o myStrings.o
	gcc -o hasWord hasWord.o parseArgs.o myStrings.o

hasWord.o: hasWord.c myStrings.h parseArgs.h
	gcc -c hasWord.c

myStrings.o: myStrings.h myStrings.c
	gcc -c myStrings.c

parseArgs.o: parseArgs.h parseArgs.c myStrings.h
	gcc -c parseArgs.c
		
clean:
	rm -f *.o hasWord test_myStrings

