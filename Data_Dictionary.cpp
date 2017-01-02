//Created by Arshia Hosseini
//89213056
#include "Data_Dictionary.h"
#include <iostream>
using namespace std;

//====================Insert====================
void Data_Dictionary::Insert(char* Word)
{
	tree_node* temp = new tree_node;
	temp = Root;
	tree_node* q;
	tree_node* p;
	

	for(int i = 0;i<strlen(Word);i++)
	{
		bool Flag = false;
		if(temp->Children == NULL)
		{
			q = new tree_node;
			q ->Data = Word[i];
			q ->Next = NULL;
			q->Children = NULL;
			if(i == (strlen(Word)-1) )
				q->isWord = true;
			temp->Children = q;
			temp = q;
		}
		else
		{
			q = temp->Children;
			if(q->Data == Word[i])
			{
				if(i == (strlen(Word)-1) )
					q->isWord = true;
				temp = q;
			}
			else
			{
				while(q->Next != NULL)
				{
					q = q->Next;
					if(q->Data == Word[i])
					{
						Flag = true;
						temp = q;
					}
				}
				if(!Flag)
				{
					tree_node* l = new tree_node;
					q = temp->Children;
					p = new tree_node;
					p->Data = Word[i];
					if(q->Next == NULL)
					{
						if (p->Data < q->Data)
							{
								p->Next = q;
								temp->Children = p;
							}
						else
							{
								q->Next = p;
								p->Next = NULL;
							}

					}
					else
					{
						while(q->Next != NULL && p->Data > q->Data)
						{
							l = q;
							q = q->Next;
						}
						if(q->Next == NULL)
						{
							q->Next = p;
							p->Next = NULL;
						}
						else
						{
							p->Next = l->Next;
							l->Next = p;
						}

					}
					p->Children = NULL;
					if(i == (strlen(Word)-1) )
						p->isWord = true;
					temp = p;
				}
				
			}
			
		}

	}

}

//====================Delete====================
void Data_Dictionary::Delete(char* &Word)
{
	tree_node* q = Root;
	tree_node* Parent = Root;

	tree_node* p = Root->Children;
	tree_node* temp = Root->Children;
	for(int i = 0 ; i < strlen(Word); i++) 
	{
		if(!temp)
			return;

		if(temp->Data == Word[i])
		{
			if(temp->Next || (temp->isWord && i != strlen(Word)-1)) 
			{
				q = Parent;
				p = temp;
			}
			Parent = temp;
			temp = temp->Children;
			continue;
		}

		while(temp && temp->Data < Word[i])
		{
			q = temp;
			temp = temp->Next;
			p = temp;
		}
		if(!temp || temp->Data > Word[i])
			return;
		Parent = temp;
		temp = temp->Children;
	}

	if(Parent->isWord == true)
	{
		if(temp != NULL) 
		{
			Parent->isWord = false;
			return;
		}
		if(p == q->Children) 
		{
			q->Children = p->Next;
		}
		else
			q->Next = p->Next;

		q = p;
		p = p->Children;
		while(p)
		{
			delete q;
			q = p;
			p = p->Children;
		}
		delete q;
		return;
	}
	return;
}


//====================Search====================
bool Data_Dictionary::Search(char* Word)
{
	tree_node* temp = new tree_node;
	temp = Root;
	tree_node* q = new tree_node;
	tree_node* p = new tree_node;
	for(int i=0;i<strlen(Word);i++)
	{
		if(temp->Children != NULL)
			q = temp->Children;
		else
			return false;
		bool Flag = false;
		if(q->Data == Word[i])
		{
			if(i == (strlen(Word)-1))
				{
					if(q->isWord)
						return true;
					else
						return false;
				}
			else
				if(i < (strlen(Word)-1))
					temp = q;
		}
		else
		{
			p = q;
			while(p->Next != NULL)
			{
				p = p->Next;
				if(p->Data == Word[i])
					{
						Flag = true;
						q = p;
					}
			}
			if(!Flag) 
				return false;
			else
			{
				if(i == (strlen(Word)-1))
				{
					if(q->isWord)
						return true;
					else
						return false;
				}
				else
					if(i < (strlen(Word)-1))
						temp = q;
			}
		}
	}
}

//====================Constructor====================
Data_Dictionary::Data_Dictionary()
{
	Root = new tree_node;
	Root->Children = NULL;
	Root->Next = NULL;
	Root->Data = NULL;
	Root->isWord = false;
}
tree_node::tree_node()
{
	isWord = false;
}
