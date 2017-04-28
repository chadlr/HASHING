#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<fstream>
#include<ctime>

using namespace std;

//class HashEntry
//{
//	public:
//	string key;
//	unsigned int value;
//	
//	HashEntry (string key, unsigned int value)
//	{
//		this->key = key;
//		this->value = value;
//	}
//};

class HashTable
{
		private:
		int HashFunction(string key);
	
	public:
		HashTable();
		void Insert(string key);
		
		const int TableSize = 1001;
		string Table[];
};

HashTable::HashTable()	
{
	Table[TableSize];
}

int HashTable::HashFunction(string key)
{
	int HashVal=0;
	for (int i = 0; i < key.size(); i++)
		HashVal = 37 * HashVal + key[i];
	return HashVal % TableSize;
}

void HashTable::Insert(string key)
{
	int hash = HashFunction(key);
	int i = 0;
	int index = hash;
	while (Table[index] != "" && Table[index] != key && i != TableSize/2)
	{
		//quadratic probing
		index = hash+(i*i);
		i = i + 1;
	}
}

int main()
{
	HashTable hash;
	string key, value;
	char choice;
	clock_t start;
	double duration;
	while (1)
	{
		cout<<"Operations"<<endl;
		cout<<"1.Add"<<endl;
		cout<<"2.Add from file"<<endl;
		cout<<"3.Search"<<endl;
		cout<<"4.Del"<<endl;
		cout<<"5.Exit"<<endl;
		cin>>choice;
		
		switch(choice)
		{
			case '1':
				cout<<"value"<<endl;
				cin>>value;
				start = std::clock();
				hash.Insert(value);
				duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
				cout<<"Time Elapsed: "<<duration<<endl;
				start = 0; //reset start time
				duration = 0; //reset duration
				break;
			
			case '2':
				cin.ignore();
				string strLoc;
				string line;
				
				cout<<"Enter file location: "<<endl;
				getline(cin, strLoc);
				
				ifstream myfile (strLoc);

				
				start = std::clock();
				while (myfile >> line)
				{
					cout<<line<<endl;
					hash.Insert(line);
				}
				duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
				
				cout<<"Time Elapsed: "<<duration<<endl;
				start = 0; //reset start time
				duration = 0; //reset duration
				break;
		}
	}
}
