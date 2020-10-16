/*
 * orderedht.h
 *
 *  Created on: 09-Oct-2020
 *      Author: Dhairya
 */

#include<iostream>
using namespace std;

#include<vector>
using namespace std;

class data_node
{
	public:
		long long int phone_number=0;  // phone number of data node in LL of a slot
		string caller_name="";         // caller name of data node in LL of a slot
		data_node* link;      // pointer to next node of data in the linked list of a slot
};

class linked_list
{
	public:
		data_node* pointer=new data_node();

//		~linked_list()
//		{
//			delete pointer;
//		}
};

class chaining
{
	public:
		long long int m; // size of the hash table
		vector <linked_list> hash_table; // hash table in the form of a resizable array
		data_node* head;

		// default constructor
		chaining();

		// parameterized constructor
		chaining(long int hash_table_size);

		//destructor
		~chaining();

		// function to return size of hash table of current object
		long int return_size();

		// function to return hash table of current object
		vector<linked_list> return_hashtable();

		// function to return the caller name of a slot when its key is passed
		string return_name(long long int probe, long long int key);

		// function to modify size of hash table
		void modify_size(long int size);

		// function to resize/modify hash table of current object
		void modify_hashtable();

		// function to insert a key & its associated caller in a new node of the LL(i.e head pointer) at a slot of hash table
		void insert(long long int key, string callername);

		// function to search for a key in the hash table and return result accordingly.
		long int search(long long int key);

		//function to delete a key and its associated caller from the hash table
		int delete_entry(long long int key);

		// function to print the chain of keys starting at a position in the hash table
		int print(long long int position);
};


