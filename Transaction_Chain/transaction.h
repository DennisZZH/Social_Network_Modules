//Name: Zihao Zhang
//Date: 10.7.2018
 #ifndef TRANSACTION_H
 #define TRANSACTION_H
#include "blockChain.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class blockChain;

class transaction
	{
	public:
		transaction(int amount, string sender, string receiver);
		
		static string sha256(const string str);

		void set_next(transaction* ptr){ next = ptr;};
		void set_hash(string hashcode){ hash = hashcode;};

		transaction* get_next(){return next;};
		int get_amount(){return amount;};
		string get_sender(){return sender;};
		string get_receiver(){return receiver;};
		string get_hash(){return hash;}; // return the private vairable hash of the current transaction
		string get_nounce(){return nounce;}//return the private variable nounce of the current transaction

		string find_hash();//find and calculate the hashcode of the previous transaction

		void printTrans();

	private:
		transaction* next;
		int amount;
		string sender;
		string receiver;
		string nounce;
		string hash;

		string findNounce();//find and calculate the appropriate nounce for the current transaction
	};
#endif

