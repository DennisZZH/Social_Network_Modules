main: transaction.o blockChain.o main.o
	g++ transaction.o blockChain.o main.o -o main -lcrypto

transaction.o: transaction.cpp transaction.h
	g++ transaction.cpp transaction.h -c

blockChain.o: blockChain.cpp blockChain.h
	g++ blockChain.cpp blockChain.h -c

main.o: main.cpp
	g++ main.cpp -c

clean:
	rm transaction.o blockChain.o main.o

