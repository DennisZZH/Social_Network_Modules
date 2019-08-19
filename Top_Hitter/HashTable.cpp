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

	HashTable::HashTable(){
		//cout<<"In the consctructor of HashTable"<<endl;
		this->hash_array = new HashTableNode*[11];
		for(int i = 0; i < 11; i++){
			hash_array[i] = NULL;
		}
	}

	HashTable::~HashTable(){
		HashTableNode* temp;
		//cout<<"In the desctructor of HashTable"<<endl;
		for(int a = 0; a < 11; a++){
			//cout<<"a = "<<a<<endl;
			for(HashTableNode* i = hash_array[a]; i != NULL; i = temp){
				// if(i == NULL){
				// 	cout<<"i is NULL"<<endl;
				// }else{
				// 	cout<<(*i).get_word();
				// }

				temp = (*i).get_next();
				delete i;
			}
		}
		//cout<<"hash nodes deleted"<<endl;
		delete []hash_array;
	}

	int HashTable::hash(string word){
		int sum = 0;
		for(int i = 0; i < word.size(); i++){
			sum += (int)word[i];
		}
		return sum % 11;
	}

	int HashTable::search(string word){
		int hashcode = hash(word);
		for(HashTableNode* i = hash_array[hashcode]; i != NULL; i = (*i).get_next()){
			if((*i).get_word() == word){
				return (*i).get_index();
			}
		}
		return -1; // -1 means not found
	}

	void HashTable::delete_entry(string word){
		//cout<<"inside delete entry function"<<endl;
		HashTableNode* temp;
		int hashcode = hash(word);
		if(hash_array[hashcode]->get_word() == word){
			temp = hash_array[hashcode];
			hash_array[hashcode] = hash_array[hashcode]->get_next();
			delete temp;
		}else{
			for(HashTableNode* i = hash_array[hashcode]; i->get_next()!= NULL; i = i->get_next()){
				if(i->get_next()->get_word() == word){
					temp = i->get_next()->get_next();
					delete i->get_next();
					i->set_next(temp);
					break;
				}

			}
		}	
	}

	void HashTable::update(MinHeap& minheap){
		string target_word;
		int hashcode;
		HashTableNode* temp;

		for(int a = 1; a < minheap.get_current(); a++){
			//cout<<"a is "<<a<<endl;
			target_word = minheap.get_node_ptr(a)->get_word();
			//cout<<"target_word is "<<target_word<<endl;
			hashcode = hash(target_word);
			//cout<<"hashcode is "<<hashcode<<endl;

			if(hash_array[hashcode] == NULL){
					//cout<<"In the blank chain"<<endl;
					hash_array[hashcode] = new HashTableNode(target_word, a);
					//cout<<"a new node is created"<<endl;
			}else{
					//cout<<"In the existing chain"<<endl;
				for(HashTableNode* i = hash_array[hashcode]; i != NULL; i = (*i).get_next()){

						if((*i).get_word() == target_word){
							(*i).set_index(a);
							//cout<<target_word<<" is set to the index "<<a<<endl;
							break;
						}
						if((*i).get_next() == NULL){
							temp = new HashTableNode(target_word, a);
							(*i).set_next(temp);
						}
				}
			}

		}
		//cout<<"update is finished"<<endl;
	}


