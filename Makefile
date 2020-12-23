
all: output chain
output: newfile.o
		g++ newfile.o -o output
newfile.o: newfile.c
		g++ -c newfile.c
chain: chain.o
		g++ chain.o -o chain
chain.o: chain.c
		g++ -c chain.c
clean:
	rm *.o output
	rm *.o chain
