/*
 * openht.h
 *
 *  Created on: 07-Oct-2020
 *      Author: Jahnavi Shah
 */

#include<iostream>
using namespace std;

#include<vector>
using namespace std;

class data
{
	public:
		long long int phone_number=0;
		string caller_name="";
};

class double_hashing
{
	private:
		long int m; // size of the hash table
		vector <data> hash_table;  // hash table in the form of a resizable array
		vector <string> status;  // to keep track of the slots of the hash table

	public:
		// default constructor
		double_hashing();

		// parameterized constructor
		double_hashing(long int hash_table_size);

		// destructor
		~double_hashing();

		// function to return size of hash table of current object
		long int return_size();

		// function to return hash table of current object
		vector<data> return_hashtable();

		// function to return status of hash table of current object
		vector<string> return_status();

		// function to modify size of hash table
		void modify_size(long int size);

		// function to resize/modify hash table
		void modify_hashtable();

		// function to update/resize status
		void modify_status();

		// function to insert a key and its associated caller in hash table
		void insert(long long int key,string callername);

		// function to delete a key and its associated caller from hash table
		void delete_entry(long long int key);

		// function to search for a key in the hash table
		long int search(long long int key);
};


