
#include<stdio.h>
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int getIndex(char base);
char getBase(int index);

class Sequence{
		enum {INI=100,MAX=1000000};
	private:
		ifstream fin;
		string s;
		string BestString;
		long Num[4];
		long Start[4];
		long Max[4];
		char last;
	private:
		struct Table{
			Table* Sons[4];
			string Heads[4];
			long matchs[4];
			Table(string baseString){
				for(int i=0;i<4;i++){
					//char rear={getBase(i),0};
					Heads[i]=baseString+getBase(i);
					matchs[i]=0;
				}
			}
		};
		struct Init{
			string head;
			long matchs;
			long starts[50]={};
			Init(string stmp,long st){
				head=stmp;
				matchs=1;
				starts[0]=st;
			}
		};
	private:
		Init* Inits[MAX];
		long InitNum;
		void Filter(Table* t);
		void ReadFile();
		void getX(char base);
		long Match(string t);
	public:
		Sequence(string filename);
		int length(){return s.size();}
		long numberOf(char base){return Num[getIndex(base)];}
		string longestConsecutive();
		string longestRepeated();
};
