//Name: Zihao Zhang
//Date: 10/28/2018
#ifndef HEAVYHITTER_H
#define HEAVYHITTER_H
#include <cstdlib>
#include <iostream>
#include <string>
#include <set>

#include "MinHeap.h"
#include "MinHeapNode.h"
#include "HashTable.h"
#include "HashTableNode.h"
 
using namespace std;

class MinHeap;
class HashTable;
class MinHeapNode;
class HashTableNode;

class HeavyHitter
	{
	public:
		HeavyHitter();
		~HeavyHitter();
		void Insert(string word);
		void ReplaceMin(string word);
		void PrintHeap();
		void PrintHashTable();
		
	private:
		MinHeap* minHeap;
		HashTable* hashTable;	
	};
#endif
