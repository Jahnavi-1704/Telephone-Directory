/*
 * orderedht.cpp
 *
 *  Created on: 09-Oct-2020
 *      Author: Jahnavi Shah
 */

#include<iostream>
using namespace std;

#include<vector>
using namespace std;

#include "orderedht.h"

// default constructor
chaining::chaining()
{
	m=0;
	head=new data_node();
	hash_table.resize(m);
}

// parameterized constructor
chaining::chaining(long int hash_table_size)
{
	m=hash_table_size;
	head=new data_node();
	hash_table.resize(m);
}

// destructor
chaining::~chaining()
{
	head=NULL;
	delete head;
}

// function to return size of hash table of current object
long int chaining::return_size()
{
	return m;
}

// function to return hash table of current object
vector<linked_list> chaining::return_hashtable()
{
	return hash_table;
}

// function to modify size of hash table
void chaining::modify_size(long int size)
{
	this->m=size;
}

// function to resize/ modify the hash table
void chaining::modify_hashtable()
{
	this->hash_table.resize(this->m);
}

// function to insert a key & its associated caller in a new node of the LL(i.e temp pointer) at a slot of the hash table
void chaining::insert(long long int key, string callername)
{
	int probe=key % this->m;
	int count=0,flag=-1;

	data_node* node=new data_node();
	data_node* next=new data_node();
	data_node* x=new data_node();

	head=hash_table[probe].pointer;

	if(head->link==0) // slot is empty, i.e no linked list present
	{
		node->phone_number=key;
		node->caller_name=callername;
		node->link=NULL;
		head=node;
		cout<<"success";
		flag=0;
	}

	else
	{
		head=head->link;
		x=head;
		next=x->link;

			if(key<(head->phone_number))
			{
				node->phone_number=key;
				node->caller_name=callername;
				node->link=head;
				head=node;
				cout<<"success";
				flag=0;
			}

			if(key>(head->phone_number))
			{
				if(next==NULL)
				{
					node->phone_number=key;
					node->caller_name=callername;
					node->link=NULL;
					head->link=node;
					cout<<"success";
					flag=0;
					count++;
				}
				while(count==0 && key>(next->phone_number))
				{

					if(next->link==NULL)
					{
						node->phone_number=key;
						node->caller_name=callername;
						node->link=NULL;
						next->link=node;
						cout<<"success";
						flag=0;
						count++;
					}
					else
					{
						x=x->link;
						next=next->link;
					}
				}

				if(count==0)
				{
					node->phone_number=key;
					node->caller_name=callername;
					node->link=next;
					x->link=node;
					cout<<"success";
					flag=0;
				}
			}
	}

	if(flag==-1)
		cout<<"failure";

	hash_table[probe].pointer->link=head;

	node=NULL;
	delete node;

	next=NULL;
	delete next;

	x=NULL;
	delete x;
}

// function to return the caller name when its key is passed
string chaining::return_name(long long int probe, long long int key)
{
	head=hash_table[probe].pointer;
	head=head->link;

	if(head->link==0)
		return head->caller_name;
	else
	{
		while(head->link!=NULL)
		{
			if(key==head->phone_number)
				return head->caller_name;
			head=head->link;
		}
		return head->caller_name;
	}
}

// function to search for a key in the hash table and return result accordingly
long int chaining::search(long long int key)
{
	int probe=key % this->m;
	head=hash_table[probe].pointer;
	if(head->link==0)
	{
		return -1;
	}

	else
	{
		head=head->link;
		data_node* y=new data_node();
		y=head;

		while(y->link!=NULL)
		{
			if(key==y->phone_number)
			{
				y=NULL;
				delete y;
				return probe;
			}
			y=y->link;
		}

		if(y->link==NULL)
		{
			if(key==y->phone_number)
			{
				y=NULL;
				delete y;
				return probe;
			}
			else
			{
				y=NULL;
				delete y;
				return -1;
			}
		}
	}
}

// function to delete a key and its associated caller from the hash table
int chaining::delete_entry(long long int key)
{
	int probe=key % this->m;
	int count=0;
	head=hash_table[probe].pointer;

	if(head->link==0)
	{
		cout<<"failure";
	}

	else
	{
		head=head->link;
		data_node *z=new data_node();
		z=head->link;

		if(z==NULL)
		{
			if(key==head->phone_number)
			{
				cout<<"success";
				hash_table[probe].pointer->link=0;
				delete z;
				return 0;
			}
			else
			{
				cout<<"failure";
				delete z;
				return 0;
			}
		}

		while(z!=NULL)
		{
			if(key==z->phone_number)
			{
				count++;
				cout<<"success";
				head->link=z->link;
				z=NULL;
				delete z;
				return 0;
			}

			if(count==0)
			{
				z=z->link;
				head=head->link;
			}
		}
	}
}

// function to print the chain of keys starting at a position in the hash table
int chaining::print(long long int position)
{
	head=hash_table[position].pointer;
	if(head->link!=0)
	{
		head=head->link;
		if(head->link==NULL)
		{
			cout<<head->phone_number;
			return 1;
		}
		else
		{
			while(head->link!=NULL)
			{
				cout<<head->phone_number<<" ";
				head=head->link;
			}
			cout<<head->phone_number;
			return 1;
		}
	}
	else
		return 0;
}
