#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<fstream>
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
	int HashFunction(const string & key, int TableSize)
	{
		int HashVal=0;
		for (int i = 0; i < key.size(); i++)
			HashVal = 37 * HashVal + key[i];
		return HashVal % TableSize;
	}
	void Insert(int key, unsigned int value)
	{
		int hash = HashFunction(key,value);
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
	char choice;
	clock_t start;
	double duration;
	ifstream myfile ("InputFile.txt");
	while (1)
	{
		cout<<"Operations"<<endl;
		cout<<"1.Add"<<endl;
		cout<<"2.Add from file"<<endl;
		cout<<"3.Search"<<Endl;
		cout<<"4.Del"<<endl;
		cout<<"5.Exit"<<endl;
		cin>>choice;
		
		switch(choice)
		{
			case '1':
			cout<<"key"<<endl;
			cin>>key;
			cout<<"value"<<endl;
			cin>>value;
			start = std::clock();
			hash.Insert(key, value);
			duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
			cout<<"Time Elapsed: "<<duration<<endl;
			start = 0; //reset start time
			duration = 0; //reset duration
			break;
			
			case '2':
			cout<<"value"<<endl;
			cin>>value;
			cout<<"key"<<endl;
			cin>>key;
			start = std::clock();
			if (myfile.is_open())
			{
				while (getline (myfile,line))
				{
					cout<<line<<endl;
					key = line;
					root = hash.Insert(key);
				}
			duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
			cout<<"Time Elapsed: "<<duration<<endl;
			start = 0; //reset start time
			duration = 0; //reset duration
			break;
		}
	}
}
