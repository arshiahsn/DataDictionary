//Created by Arshia Hosseini
//89213056
#ifndef DATA_DICTIONARY_H_
#define DATA_DICTIONARY_H_

#include <iostream>
using namespace std;
//====================Node====================
struct tree_node
{
	char Data;
	bool isWord;
	tree_node* Children;
	tree_node* Next;
	tree_node();
};

//====================Class====================
class Data_Dictionary
{
	
public:
	Data_Dictionary();
	tree_node* Root;
	void Insert(char*);
	void Delete(char* &);
	bool Search(char*);
};

#endif