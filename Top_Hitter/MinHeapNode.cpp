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

	MinHeapNode::MinHeapNode(string word, int frequency){
		this->word = word;
		this->frequency = frequency;
	}

	void MinHeapNode::increase_frequency(){
		// cout<<"before increase: "<< frequency <<endl;
		frequency += 1;
		// cout<<"after increase: "<< frequency <<endl;
	}