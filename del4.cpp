#include <stdio.h>
#include <string>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <ctime>
#include <vector>

using namespace std;

int TableSize = 31;
vector<string> Table;

class HashTable{
	private:
		unsigned int HashFunction(string);
	
	public:
		HashTable();
		~HashTable();
		void Insert(string);
		void PrintAll();
		bool Search(string);
		void UpdateTSize(int);
};

HashTable::HashTable() {
	Table.reserve(TableSize);
}

void HashTable::UpdateTSize(int t_size)
{
	Table.clear();
	for(int i = 0; i < t_size; i++){
		Table.push_back("");
	}
	TableSize = t_size;
}

HashTable::~HashTable(){
	
}

unsigned int HashTable::HashFunction(string key){
	unsigned long hashkey = 0;
	for(char ch:key){
		hashkey = 37 * hashkey + ch;
	}
	return hashkey % TableSize;
}

void HashTable::Insert(string key){
	unsigned int hashkey = HashFunction(key);
	
	unsigned int index = hashkey;
	for(unsigned int i = 1; i <= TableSize/2 ;i++){
		if(Table[index]== ""){
			Table[index] = key;
			return;
		}
		else if(Table[index]==key){
			return;
		}
		index = (hashkey + (i*i)) % TableSize;
	}
}

bool HashTable::Search(string key){
	unsigned int hashkey = HashFunction(key);
	
	unsigned int index = hashkey;
	for(unsigned int i = 1; i <= TableSize/2 ;i++){
		if(Table[index] == key){
			return true;
		}
		index = (hashkey + (i*i)) % TableSize;
	}
	return false;
}

void HashTable::PrintAll() {
	int index = 0;
	cout<<endl<<endl;
	for(index = 0; index < Table.size(); index++){
		cout<<"Index "<<index<<":"<<"\t"<<Table[index]<<endl;
	}
}

int main(){
	bool bLoop2 = true;

	while(1){
		
		HashTable h;
		
		bool bLoop = true;
		
		char select;
		
		clock_t start;
		double duration;
		
		int t_size2 = 1;
		system("CLS");
		cout<<"========CREATE A HASHTABLE======"<<endl;
		cout<<"Enter a table size or '0' to exit: ";
		cin>>t_size2;
		cin.ignore();
		
		if (t_size2 == 0){
			break;
		}
		
		h.UpdateTSize(t_size2);
		
		cout<<"New Table Size is "<<Table.size();
		getch();
		
		while(bLoop){
			system("CLS");
			cout<<"Select an opton below: "<<endl;
			cout<<"1 - Add a value"<<endl;
			cout<<"2 - Add from file"<<endl;
			cout<<"3 - Search"<<endl;
			cout<<"4 - Show All"<<endl;
			cout<<"0 - Back to Create HashTable"<<endl;
			cout<<"Selection: ";
	
			select = getche();
			
			switch(select)
			{
				case '1':{
					string value;
					cout<<endl<<endl<<endl<<"Enter a value to add: ";
					cin>>value;
					cin.ignore();
					start = clock();
					h.Insert(value);
					duration = (clock() - start)/ (double) CLOCKS_PER_SEC;
					cout<<"Time elapsed: "<<duration<<endl;
					getch();
					start = 0;
					duration = 0;
					break;
				}
				case '2':
				{
					string value;
					cout<<endl<<endl<<"Enter file path: ";
					getline(cin, value);
					cout<<endl<<endl;
					
					ifstream file(value);
					string out;
					
					start = clock();
					while(file>>out){
						h.Insert(out);
					}
					duration = (clock() - start )/ (double) CLOCKS_PER_SEC;
					cout<<"Time elapsed: "<<duration<<endl;
					getch();
					start = 0;
					duration = 0;
					break;
				}
				case '3':{
					string value;
					cout<<endl<<endl<<"Enter a value to search: ";
					cin>>value;
					start = clock();
					if(h.Search(value)){
						cout<<"Value already in the table.";
					}
					else{
						cout<<"Value not yet in the table.";
					}
					duration = (clock() - start )/ (double) CLOCKS_PER_SEC;
					cout<<"Time elapsed: "<<duration<<endl;
					getch();
					start = 0;
					duration = 0;
					break;
				}
				case '4':
					h.PrintAll();
					getch();
					break;
				case '0':
					bLoop = false;
					break;
			}
		}	
	}

	
}
