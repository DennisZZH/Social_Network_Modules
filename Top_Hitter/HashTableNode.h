//Name: Zihao Zhang
//Date: 10/28/2018
 #ifndef HASHTABLENODE_H
 #define HASHTABLENODE_H
#include <cstdlib>
#include <iostream>
#include <string>
#include "HeavyHitter.h"
#include "MinHeap.h"
#include "MinHeapNode.h"
#include "HashTable.h"

using namespace std;

class HashTableNode{
	public:
		HashTableNode(string word, int index);

		string get_word(){return word;};		// getter functions

		int get_index(){return index;};

		HashTableNode* get_next(){return next;};

		void set_word(string word){this->word = word;};			// setter functions

		void set_index(int index){this->index = index;};

		void set_next(HashTableNode* next){this->next = next;};

	private:
		string word;
		int index;
		HashTableNode* next;
};
#endif