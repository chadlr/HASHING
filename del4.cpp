#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>

using namespace std;
const int TableSize = 1001;

class HashEntry
{
	public:
	string key;
	unsigned int value;
	
	HashEntry (string key, unsigned int value)
	{
		this->key = key;
		this->value = value;
	}
};
class HashTable
{
	private:
	HashEntry **Table;
	
	public:
	HashTable()
	{
		Table = new HashEntry * [TableSize];
		for (int i=0; i<TableSize; i++)
		{
			Table[i]=NULL;
		}
	}
	int HashFunction(int key)
	{
		return key % TableSize;
	}
	void Insert(int key, int value)
	{
		int hash = HashFunction(key);
		while (Table[hash] != NULL && Table[hash]->key != key)
		{
			hash = HashFunction (hash+1);
		}
		if (Table[hash] !=NULL)
			delete Table[hash];
		Table[hash]=new HashEntry(key,value);
	}
	//search
	//remove
}
int main()
{
	HashTable hash;
	string key, value;
	int choice;
	while (1)
	{
		cout<<"Operations"<<endl;
		cout<<"1.Add"<<endl;
		cout<<"2.Search"<<Endl;
		cout<<"3.Del"<<endl;
		cout<<"4.Exit"<<endl;
		cin>>choice;
		
		switch(choice)
		{
			case 1:
			cout<<"value"<<endl;
			cin>>value;
			cout<<"key"<<endl;
			cin>>key;
			hash.Insert(key, value);
			break;
		}
	}
}
