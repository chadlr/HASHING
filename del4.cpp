#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<ctime>

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
		int HashVal=0;
		for (char ch: key)
			HashVal = 37 * HashVal + ch;
		return HashVal % TableSize;
	}
	void Insert(int key, int value)
	{
		int hash = HashFunction(key);
		int i
		while (Table[hash] != NULL && Table[hash]->key != key)
		{
			//quadratic probing
			hash = HashFunction (hash + i * i);
			i = i + 1;
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
	clock_t start;
	double duration;
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
			start = std::clock();
			hash.Insert(key, value);
			duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
			cout<<"Time Elapsed: "<<duration<<endl;
			start = 0; //reset start time
			duration = 0; //reset duration
			break;
		}
	}
}
