#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<stdio.h>
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
#define MAX 400000
int getIndex(char base);
class Sequence{
	private:
		struct Table{
			
			int common;
			string Heads[4];
			int cMatchs;

			int* cStarts;
			Table* Sons[4];

			Table(string baseString,int com);
		};
	private:
		ifstream fin;
		string s;
		string BestString;
		Table* Ancestor;
		long Num[4];
		long Start[4];
		long Max[4];
		char last;
	private:
		void Filter(Table* t);
		void ReadFile();
		void getX(char base);
	public:
		Sequence(string filename);
		int length(){return s.size();}
		int numberOf(char base){return Num[getIndex(base)];}
		string longestConsecutive();
		string longestRepeated();
};
#endif
