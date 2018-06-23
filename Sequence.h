
#include<stdio.h>
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

class Sequence{
		ifstream fin;
		int A;
		int C;
		int T;
		int G;
		string s;

		int Astart;
		int Amax;
		int Cstart;
		int Cmax;
		int Tstart;
		int Tmax;
		int Gstart;
		int Gmax;
		char last;
		char last_t;
	private:
		void getA();
		void getC();
		void getT();
		void getG();
		void ReadFile();
	public:
		Sequence(string filename);
		int length(){return s.size();}
		int numberOf(char base);
		string longestConsecutive();
		string longestRepeated();
};
