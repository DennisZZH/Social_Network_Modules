//Name: Zihao Zhang
//Date: 10.7.2018
#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include "transaction.h"
#include <cstdlib>
#include <iostream>
#include <string>
 
using namespace std;

class transaction;

class blockChain
	{
	public:
		blockChain();
		~blockChain();
		void add_transaction(int amount, string sender, string receiver);
		void find_transaction(string sender);
		bool verify_and_print_transaction();

	private:
		transaction* head;
		transaction* current;
		int numOfTrans;
	};
#endif