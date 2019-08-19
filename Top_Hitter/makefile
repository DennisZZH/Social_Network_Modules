main: HeavyHitter.o MinHeap.o MinHeapNode.o HashTable.o HashTableNode.o main.o
	g++ HeavyHitter.o MinHeap.o MinHeapNode.o HashTable.o HashTableNode.o main.o -o main

MinHeap.o: MinHeap.cpp MinHeap.h
	g++ MinHeap.cpp MinHeap.h -c

MinHeapNode.o: MinHeapNode.cpp MinHeapNode.h
	g++ MinHeapNode.cpp MinHeapNode.h -c

HashTable.o: HashTable.cpp HashTable.h
	g++ HashTable.cpp HashTable.h -c

HashTableNode.o: HashTableNode.cpp HashTableNode.h
	g++ HashTableNode.cpp HashTableNode.h -c

HeavyHitter.o: HeavyHitter.cpp HeavyHitter.h
	g++ HeavyHitter.cpp HeavyHitter.h -c

main.o: main.cpp
	g++ main.cpp -c

clean:
	rm HeavyHitter.o HashTable.o MinHeap.o HashTableNode.o MinHeapNode.o main.o 

