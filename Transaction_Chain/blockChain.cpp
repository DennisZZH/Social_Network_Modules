//Name: Zihao Zhang
//Date: 10.7.2018
#include "transaction.h"
#include "blockChain.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include <stdio.h>
#include <string.h>

#include <openssl/sha.h>

using namespace std;

	blockChain::blockChain(){
		transaction *head = NULL;
		transaction *current = NULL;
		numOfTrans = 0;
	}

	blockChain::~blockChain(){
		for(transaction* ptr = current; ptr != NULL; ptr = current){
			current = current->get_next();
			delete ptr;
		}
	}

	void blockChain::add_transaction(int amount, string sender, string receiver){
		if(numOfTrans == 0){
			head = new transaction(amount, sender, receiver);
			current = head;
			numOfTrans++;
		}else{
			transaction *newTrans = new transaction(amount, sender, receiver);
			newTrans->set_next(current);
			newTrans->set_hash(current->find_hash());
			current = newTrans;
			numOfTrans++;
		}
		cout<<endl;
		cout<<"-------One transaction has been added-------"<<endl;
		current->printTrans();
		cout<<"The previous transaction's hash value is "<<current->find_hash()<<endl;
	}

	void blockChain::find_transaction(string sender){
		cout<<endl;
		cout<<"-------All the transactions found under "<<sender<<"-------"<<endl;
		for(transaction* ptr = current; ptr != NULL; ptr = ptr->get_next()){
			if(ptr->get_sender() == sender){
				ptr->printTrans();
			}
		}
	}

	 bool blockChain::verify_and_print_transaction(){
		for(transaction* ptr = current; ptr != head; ptr = ptr->get_next()){
			if(ptr->get_hash() != transaction::sha256(to_string(ptr->get_next()->get_amount()) + ptr->get_next()->get_sender() + ptr->get_next()->get_receiver() + ptr->get_next()->get_nounce())){
				cout<<endl;
				cout<<"-------This two transactions do not match-------"<<endl;
				ptr->printTrans();
				ptr->get_next()->printTrans();
				return false;
			}
		}

		cout<<endl;
		cout<<"-------This is the block chain-------"<<endl;
		for(transaction* ptr = current; ptr != NULL; ptr = ptr->get_next()){
			ptr->printTrans();
		}
		cout<<"-------End of block chain-------"<<endl;

	 	return true;
	}





















