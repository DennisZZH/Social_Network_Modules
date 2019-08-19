//Name: Zihao Zhang
//Date: 10/28/2018
 #ifndef MINHEAP_H
 #define MINHEAP_H
#include <cstdlib>
#include <iostream>
#include <string>
#include <set>
#include "HeavyHitter.h"
#include "HashTable.h"
#include "MinHeapNode.h"
#include "HashTableNode.h"

using namespace std;

class HeavyHitter;
class HashTable;
class MinHeapNode;

class MinHeap{
	public:

		MinHeap();

		~MinHeap();

		int find(string word);   // return the index of the node found

		void add(string word, int frequency);

		void percolate_down(int index, MinHeapNode node);

		void percolate_up(int index, MinHeapNode node);

		MinHeapNode* get_node_ptr(int index); // get the node in the given index

		int get_current(){return current;};

		bool isFull();			// check if the heap_array is full (15 elements)

	private:

		int current;	// current available index, if there is any

		MinHeapNode** heap_array;
};
#endif