/*
 * openht.cpp
 *
 *  Created on: 07-Oct-2020
 *      Author: Jahnavi Shah
 */
#include<iostream>
using namespace std;

#include<vector>
using namespace std;

#include<math.h>
using namespace std;

#include "openht.h"

// default constructor
double_hashing::double_hashing()
{
	m=0;
	hash_table.resize(m);
	status.resize(m);
}

// parameterized constructor
double_hashing::double_hashing(long int hash_table_size)
{
	m=hash_table_size;
	hash_table.resize(m);
	status.resize(m,"empty");
}

// default destructor
double_hashing::~double_hashing()
{
	//this is the destructor
}

// function to return size of the hash table of current object
long int double_hashing::return_size()
{
	return m;
}

// function to return hash table of current object
vector<data> double_hashing::return_hashtable()
{
	return hash_table;
}

// function to return status of hash table of current object
vector<string> double_hashing::return_status()
{
	return status;
}

// function to modify size of hash table of current object
void double_hashing::modify_size(long int size)
{
	this->m=size;
}

// function to resize hash table of current object
void double_hashing::modify_hashtable()
{
	this->hash_table.resize(this->m);
}

// function to update/resize status of hash table of current object
void double_hashing::modify_status()
{
	this->status.resize(this->m,"empty");
}

// function to insert a key and its associated caller in the hash table
void double_hashing::insert(long long int key, string callername)
{
	int count=0;
	long long int value=search(key);
	for(int i=0;i<this->m;i++)
	{
		if(status[i]=="empty" || status[i]=="deleted")
			count++;
	}

	if(count==0)
	{
		cout<<"failure";
	}
	else
	{
		int probe=key % (this->m);
		int offset=int(floor(key/this->m)) % this->m;
		if(offset%2==0)
		{
			offset++;
		}

		if(value!=-1)
			cout<<"failure";
		else
		{
			if(status[probe]!="occupied")
			{
				hash_table[probe].phone_number=key;
				hash_table[probe].caller_name=callername;
				status[probe]="occupied";
				cout<<"success";
			}
			else
			{
				while(status[probe]=="occupied")
				{
					probe=(probe+offset) % this->m;
				}

				hash_table[probe].phone_number=key;
				hash_table[probe].caller_name=callername;
				status[probe]="occupied";
				cout<<"success";
			}
		}
	}
}

// function to delete a key and its associated caller from hash table
void double_hashing::delete_entry(long long int key)
{
	long long int value=search(key);
	if(value==-1)
		cout<<"failure";
	else
	{
		hash_table[value].phone_number=0;
		hash_table[value].caller_name="";
		status[value]="deleted";
		cout<<"success";
	}
}

long int double_hashing::search(long long int key)
{
	int diff;
	int probe=key % this->m;
	int offset=int(floor(key/this->m)) % this->m;
	if(offset%2==0)
	{
		offset++;
	}

	if(hash_table[probe].phone_number==key)
	{
		return probe;
	}
	else
	{
		int temp=probe+offset;
		if(temp<this->m)
			probe=(probe+offset) % this->m;
		else
		{
			diff=this->m-probe;
			probe=offset-diff;
		}

		while(status[probe]!="empty")
		{
			if(hash_table[probe].phone_number==key)
				return probe;

			temp=probe+offset;
			if(temp<this->m)
				probe=(probe+offset) % this->m;
			else
			{
				diff=this->m-probe;
				probe=offset-diff;
			}
		}
		return -1;
	}
}
