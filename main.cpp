//Created by Arshia Hosseini
//89213056
#include <iostream>
#include "Data_Dictionary.h"
using namespace std;

//====================Main====================
int main()
{
	int Input;
	char* Word;
	Data_Dictionary DD;
	cout<<"Enter 1 to insert."<<endl;
	cout<<"Enter 2 to search."<<endl;
	cout<<"Enter 3 to delete."<<endl;
	cout<<"Enter 4 to exit."<<endl<<endl;
	cout<<"Enter your choice:"<<endl;

	 while(cin>>Input)
	 {
		cout<<endl;
		Word = new char[10];
		if(Input == 1)
		{
			cout<<"Enter a word to insert:"<<endl;
			cin>>Word;
			if(DD.Search(Word)) 
				cout<<"This word already exists."<<endl;
			else
			{
				DD.Insert(Word);
				cout<<"Word is inserted successfully"<<endl;
			}

		}

		if(Input == 2)
		{
			cout<<"Enter a word to search:"<<endl;
			cin>>Word;
			if(DD.Search(Word)) 
				cout<<"Word is found."<<endl;
			else
				cout<<"Word is not found."<<endl;
		}

		if(Input == 3)
		{
			cout<<"Enter a word to delete:"<<endl;
			cin>>Word;
			if(!DD.Search(Word)) 
				cout<<"Word is not found for deletion."<<endl;
			else
			{
				DD.Delete(Word);
				cout<<"Word is deleted successfully."<<endl;
			}
		}
		if(Input == 4) goto Exit;
	}
	Exit:
	return 0;
}