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

	MinHeap::MinHeap(){
		//cout<<"In the consctructor of MinHeap"<<endl;
		heap_array = new MinHeapNode*[16];
		for(int i = 0; i < 16; i++){
			heap_array[i] = NULL;
		}
		current = 1;
	}

	MinHeap::~MinHeap(){
		//cout<<"In the desctructor of MinHeap"<<endl;
		for(int i = 1; i < current; i++){
			// cout<<"i = "<<i<<endl;
			// if(heap_array[i] == NULL){
			// 	cout<<"NULL"<<endl;
			// }else{
			// 	cout<<heap_array[i]->get_word()<<endl;
			// }

			delete heap_array[i];
			//cout<<"heap node deleted"<<endl;
		}
		delete [] heap_array;
		//cout<<"heap array deleted"<<endl;
	}

	bool MinHeap::isFull(){
		if(current > 15){
			return true;
		}else{
			return false;
		}
	}

	int MinHeap::find(string word){
		for(int i = 1; i < current; i++){
			if(heap_array[i]->get_word() == word){
				return i;
			}
		}
		return -1; // return -1 if word not found
	}

	void MinHeap::add(string word, int frequency){
		heap_array[current] = new MinHeapNode(word, frequency);
		current = current + 1;
	}

	MinHeapNode* MinHeap::get_node_ptr(int index){
		return (heap_array[index]);
	}

	void MinHeap::percolate_down(int index, MinHeapNode node){
		int left, right;
		int target;
		MinHeapNode* temp;

		while(2 * index < current){
			left = 2 * index;
			right = 2 * index + 1;
			if( right >= current || heap_array[left]->get_frequency() < heap_array[right]->get_frequency()){
				target = left;
			}else{
				target = right;
			}
			if( heap_array[target]->get_frequency() < node.get_frequency()){
				temp = heap_array[index];
				heap_array[index] = heap_array[target];
				heap_array[target] = temp;
				index = target;
			}else{
				break;
			}
		}
	}

	void MinHeap::percolate_up(int index, MinHeapNode node){
		MinHeapNode* temp;
		//cout<<"index is "<<index<<endl;
		if(index == 1){
			return;
		}
		while(node.get_frequency() < heap_array[index / 2]->get_frequency()){
			temp = heap_array[index];
			heap_array[index] = heap_array[index / 2];
			heap_array[index / 2] = temp;
			index = index / 2;
			if(index == 1){
				break;
			}
		}
	}











