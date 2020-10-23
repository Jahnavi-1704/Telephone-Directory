/*
 * openhttest.cpp
 *
 *  Created on: 07-Oct-2020
 *      Author: Jahnavi Shah
 */
#include<iostream>
using namespace std;

#include<string.h>
using namespace std;

#include "openht.h"

int main()
{
	string input;
	char first_letter;

	//object 'Table' of class double_hashing, it is global for all commands
	double_hashing Table;

	getline(cin,input);
	first_letter=input[0];

	while(first_letter!='e')
	{
		if(first_letter=='n')
		{
			string m;
			m=input.substr(2);
			int value=stoll(m);

			if(value>0)
			{
				// updating m value & resizing the hash_table of object 'Table'
				Table.modify_size(value);
				Table.modify_hashtable();
				Table.modify_status();
				cout<<"success";
			}
			else
				cout<<"failure";
		}

		else if(first_letter=='i')
		{
			string key=input.substr(2,10);
			long long int temp=stoll(key);
			string caller=input.substr(13);

			Table.insert(temp, caller);
		}

		else if(first_letter=='d')
		{
			string key=input.substr(2);
			long long int temp=stoll(key);
			Table.delete_entry(temp);
		}

		else if(first_letter=='s')
		{
			string key=input.substr(2);
			long long int temp=stoll(key);
			long long int value=Table.search(temp);
			if(value==-1)
				cout<<"not found";
			else
			{
				vector <data> tempo=Table.return_hashtable();
				string name=tempo[value].caller_name;
				cout<<"found "<<name<<" in "<<value;
			}
		}
		cout<<"\n";
		getline(cin,input);
		first_letter=input[0];
	}
}




