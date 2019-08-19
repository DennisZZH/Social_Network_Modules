//Name: Zihao Zhang
//Date: 10/28/2018
 #ifndef HASHTABLE_H
 #define HASHTABLE_H
#include <cstdlib>
#include <iostream>
#include <string>
#include "HeavyHitter.h"
#include "MinHeap.h"
#include "MinHeapNode.h"
#include "HashTableNode.h"

using namespace std;

class HeavyHitter;
class MinHeap;
class MinHeapNode;
class HashTableNode;

class HashTable{
	public:
		HashTable();

		~HashTable();

		static int hash(string word);

		int search(string word);

		void delete_entry(string word);

		void update(MinHeap& minheap);

		HashTableNode* get_node_ptr(int index){return hash_array[index];};

	private:

		HashTableNode** hash_array;
};
#endif