//Name: Zihao Zhang
//Date: 10/28/2018
 #ifndef MINHEAPNODE_H
 #define MINHEAPNODE_H
#include <cstdlib>
#include <iostream>
#include <string>
#include "HeavyHitter.h"
#include "MinHeap.h"
#include "HashTable.h"
#include "HashTableNode.h"

using namespace std;

class MinHeapNode{
	public:

		MinHeapNode(string word, int frequency);

		void increase_frequency();

		int get_frequency(){return frequency;};

		string get_word(){return word;};

		void change_word(string newword){word = newword;};

	private:
		string word;
		int frequency;
};
#endif