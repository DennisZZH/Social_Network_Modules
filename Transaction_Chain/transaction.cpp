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

	transaction::transaction(int amount, string sender, string receiver){
		this->next = NULL;
		this->amount = amount;
		this->sender = sender;
		this->receiver = receiver;
		this->nounce = findNounce();
		this->hash = "";
		//cout<<"222    "<<this->amount<<"    222"<<endl;
	}

	string transaction::sha256(const string str){
	    unsigned char hash[SHA256_DIGEST_LENGTH];
	    SHA256_CTX sha256;
	    SHA256_Init(&sha256);
	    SHA256_Update(&sha256, str.c_str(), str.size());
	    SHA256_Final(hash, &sha256);
	    stringstream ss;
	    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
	    {
	        ss << hex << setw(2) << setfill('0') << (int)hash[i];
	    }
	    return ss.str();
	}

	string transaction::findNounce(){
		string tempNounce;
		string allInfo;
		string hashInfo;

		do{
		srand(time(NULL));
		tempNounce = string(1, char(rand()%26 + 97));
		allInfo = to_string(amount) + sender + receiver + tempNounce;
		hashInfo = sha256(allInfo);
		}while( (*hashInfo.rbegin() != '0') && (*hashInfo.rbegin() != '1') && (*hashInfo.rbegin() != '2') && (*hashInfo.rbegin() != '3') && (*hashInfo.rbegin() != '4'));

		//cout<<"111    "<<allInfo<<"    111"<<endl;
		return tempNounce;
	}

	string transaction::find_hash(){
		string allInfo = to_string(amount) + sender + receiver + nounce;
		string hashInfo = sha256(allInfo);
		return hashInfo;
	}

	void transaction::printTrans(){
		cout<<endl;
		cout<<"---This is a transaction---"<<endl;
		cout<< sender <<" transfered "<< amount <<" dollar to "<< receiver <<endl;
		cout<<"---End of transaction---"<<endl;

	}














