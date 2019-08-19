//Name: Zihao Zhang
//Date: 10.13.2018
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include <stdio.h>
#include <string.h>

#include <openssl/sha.h>
#include "transaction.h"
#include "blockChain.h"

using namespace std;

void print_menu();

char get_command();

void test_add_transaction(blockChain& test);

void test_find_transaction(blockChain& test);

void test_verify_and_print_the_chain(blockChain& test);

int main()
{
	blockChain bc;
	char command;

	do
	{
		print_menu();
		command = toupper(get_command());

		switch(command)
		{
			case '1': test_add_transaction(bc);
				break;
			case '2': test_find_transaction(bc);
				break;
			case '3': test_verify_and_print_the_chain(bc);
				break;
			case 'Q':
				break;
			default: cout << "Invalid command."<< endl;
				break;
		}
	}while(command != 'Q');

	return (EXIT_SUCCESS);
}

void print_menu()
{
	cout<<endl;
	cout <<"-------------------------------Main Menu------------------------------------"<<endl;
	cout <<"Welcome to the transaction-chain application ...."<<endl;
	cout <<" 1) Add a transaction to the chain."<<endl;
	cout <<" 2) Find a transaction with the name of receiver or sender."<<endl;
	cout <<" 3) Verify and print the chain."<<endl;
	cout <<" Q) Quit this interactive test program"<<endl;
	cout <<" Which operation do you want to make? (1, 2, 3, Q):"<<endl;
}

char get_command(){
	char command;

	cout << ">";
	cin >> command;

	return(toupper(command));
}

void test_add_transaction(blockChain& test){
	int amount;
	string sender;
	string receiver;

	cout << "Enter amount: ";
	cin >> amount;
	while(cin.fail()){
		cout<<"INPUT TYPE ERROR, TRY AGAIN"<<endl;
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Enter amount: ";
		cin >> amount;
	}

	cout << "Enter sender: ";
	cin >> sender;
	cout<< "Enter receiver: ";
	cin >> receiver;

	test.add_transaction(amount, sender, receiver);
}

void test_find_transaction(blockChain& test){
	string sender;

	cout << "Enter sender: ";
	cin >> sender;

	test.find_transaction(sender);

}

void test_verify_and_print_the_chain(blockChain& test){
	bool result;
	result = test.verify_and_print_transaction();

	if(result == true){
		cout<<endl;
		cout << "-------------The verification is successed!-------------"<<endl;
	}else{
		cout<<endl;
		cout << "-------------The verification failed!-------------"<<endl;
	}
}


















