//Name: Zihao Zhang
//Date: 10/28/2018
#include <iostream>
#include <cstdlib>
#include <string>

#include "HeavyHitter.h"
#include "MinHeap.h"
#include "MinHeapNode.h"
#include "HashTable.h"
#include "HashTableNode.h"

using namespace std;

	HashTableNode::HashTableNode(string word, int index){
		this->word = word;
		this->index = index;
		this->next = NULL;
	}