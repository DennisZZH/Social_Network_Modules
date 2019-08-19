//Name: Zihao Zhang
//Date: 10/28/2018
#include <iostream>
#include <cstdlib>
#include <string>
#include <set>
#include "HeavyHitter.h"
#include "MinHeap.h"
#include "MinHeapNode.h"
#include "HashTable.h"
#include "HashTableNode.h"

using namespace std;

	HeavyHitter::HeavyHitter(){
		minHeap = new MinHeap();
		hashTable = new HashTable();	
	}

	HeavyHitter::~HeavyHitter(){
		//cout<<"in the destructor of HeavyHitter"<<endl;
		//cout<<"deleting minheap"<<endl;
		delete minHeap;
		//cout<<"deleting hashTable"<<endl;
		delete hashTable;
	}
		
	void HeavyHitter::Insert(string word){
		//cout<<"This Is One Insertion!!!!"<<endl;
		if(hashTable->search(word) != -1){
			//cout<<"increase a word: "<<word<<endl;
			minHeap->get_node_ptr(minHeap->find(word))->increase_frequency();
			//cout<<"percolating down a word: "<<word<<endl;
			minHeap->percolate_down(minHeap->find(word), *(minHeap->get_node_ptr(minHeap->find(word))));
			hashTable->update(*minHeap);
		}else{
			if(minHeap->isFull()){
				//cout<<"replace min: "<<word<<endl;
				ReplaceMin(word);
			}else{
				//cout<<"adding a word: "<<word<<endl;
				minHeap->add(word,1);
				//cout<<"percolating up a word: "<<word<<endl;
				minHeap->percolate_up(minHeap->find(word), *(minHeap->get_node_ptr(minHeap->find(word))));
				//cout<<"updating a word: "<<word<<endl;
				hashTable->update(*minHeap);
			}
		}
	}

	void HeavyHitter::ReplaceMin(string word){
		//cout<<"getting word"<<endl;
		string temp = minHeap->get_node_ptr(1)->get_word();
		//cout<<"changing word"<<endl;
		minHeap->get_node_ptr(1)->change_word(word);
		//this->PrintHashTable();
		//cout<<"deleting entry"<<endl;
		hashTable->delete_entry(temp);
		//this->PrintHashTable();
		//cout<<"updating hashTable"<<endl;
		hashTable->update(*minHeap);
		//this->PrintHashTable();
	}
		
	void HeavyHitter::PrintHeap(){
		string word;
		int frequency;
		cout<<"----------Now Printing The MinHeap----------"<<endl;
		for(int i = 1; i < minHeap->get_current(); i++){
			word = minHeap->get_node_ptr(i)->get_word();
			frequency = minHeap->get_node_ptr(i)->get_frequency();
			cout<<"Word: "<<word<<" of "<<"Frequency: "<<frequency<<endl;
		}
		cout<<"---------The MinHeap Is Printed----------"<<endl;

	}
		
	void HeavyHitter::PrintHashTable(){
		string word;
		int index;
		cout<<"----------Now Printing The HashTable----------"<<endl;
		for(int a = 0; a < 11; a++){
			//cout<<"index is "<<a<<endl;
			for(HashTableNode* i = hashTable->get_node_ptr(a); i != NULL; i = (*i).get_next()){
				//cout<<"11111111111"<<endl;
				// if( i == NULL){
				// 	cout<<"i is NULL"<<endl;
				// }else{
				// 	cout<<"i is not MULL"<<endl;
				// }
				word = (*i).get_word();
				//cout<<"222222222222"<<endl;
				index = (*i).get_index();
				cout<<"Word: "<<word<<" in "<<"Index: "<<index<<endl;
			}
		}
		cout<<"---------The HashTable Is Printed----------"<<endl;
	}




