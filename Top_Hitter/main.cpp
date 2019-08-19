//Name: Zihao Zhang
//Date: 10.31.2018
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include <fstream>

#include "HeavyHitter.h"
#include "MinHeap.h"
#include "MinHeapNode.h"
#include "HashTable.h"
#include "HashTableNode.h"

using namespace std;

void print_menu();

char get_command();

void test_Insert(HeavyHitter& test);

void test_Input_File(HeavyHitter& test);

void test_Print_Heap(HeavyHitter& test);

void test_Print_HashTable(HeavyHitter& test);

int main()
{
	HeavyHitter hh;
	char command;

	do
	{
		print_menu();
		command = toupper(get_command());

		switch(command)
		{
			case '1': test_Insert(hh);
				break;
			case '2': test_Print_Heap(hh);
				break;
			case '3': test_Print_HashTable(hh);
				break;
			case '4': test_Input_File(hh);
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
	cout <<"Welcome to The Hottest of Them All application ...."<<endl;
	cout <<" 1) Insert a word."<<endl;
	cout <<" 2) Print the MinHeap."<<endl;
	cout <<" 3) Print the HashTable"<<endl;
	cout <<" 4) Input a text file"<<endl;
	cout <<" Q) Quit this interactive test program"<<endl;
	cout <<" Which operation do you want to make? (1, 2, 3, 4,Q):"<<endl;
}

char get_command(){
	char command;

	cout << ">";
	cin >> command;

	return(toupper(command));
}

void test_Insert(HeavyHitter& test){
	string word;

	cout << "Enter word: ";
	cin >> word;

	for(int i = 0; i < word.size(); i++){
	    if(word[i]>=65 && word[i]<=92){
			word[i] = word[i]+32;
	    }
  	}

	test.Insert(word);
	//cout<<"Main: Insert finished"<<endl;
}

void test_Print_Heap(HeavyHitter& test){

	test.PrintHeap();

}

void test_Print_HashTable(HeavyHitter& test){
	
	test.PrintHashTable();
}

void test_Input_File(HeavyHitter& test){
	ifstream file;
	string word;
	file.open("article_ta.txt");

	while(file >> word){
		for(int i = 0; i < word.size(); i++){
		    if(word[i]>=65 && word[i]<=92){
				word[i] = word[i]+32;
		    }
  		}

		test.Insert(word);
	}
}













