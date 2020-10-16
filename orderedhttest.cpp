/*
 * orderedhttest.cpp
 *
 *  Created on: 09-Oct-2020
 *      Author: Dhairya
 */
#include<iostream>
using namespace std;

#include<string.h>
using namespace std;

#include "orderedht.h"

int main()
{
	string input;
	char first_letter;

	int flag=-1;

	chaining Table; // local object of class chaining

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

		    	cout<<"success";
		    }
		    else
		    	cout<<"failure";
		}

		else if(first_letter=='i')
		{
			string key=input.substr(2,10);
			long long int tempkey=stoll(key);
			string caller=input.substr(13);

			Table.insert(tempkey, caller);
		}

		else if(first_letter=='s')
		{
			string key=input.substr(2,10);
			long long int tempkey=stoll(key);

			long long int value=Table.search(tempkey);
			if(value==-1)
				cout<<"not found";
			else
			{
				string name=Table.return_name(value,tempkey);
				cout<<"found "<<name<<" in "<<value;
			}
		}

		else if(first_letter=='d')
		{
			string key=input.substr(2,10);
			long long int tempkey=stoll(key);

			Table.delete_entry(tempkey);
		}

		else if(first_letter=='p')
		{
			string pos=input.substr(2);
			long long int temppos=stoll(pos);
			flag=Table.print(temppos);
		}

		if(first_letter!='p' || flag==1)
		{
			cout<<"\n";
		}
		getline(cin,input);
		first_letter=input[0];
	}
}



