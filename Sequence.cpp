#include"/home/peng201730683314/github/Sequence/Sequence.h"

Sequence::Sequence(string filename):A(0),C(0),T(0),G(0),Amax(0),Astart(0),Cmax(0),Cstart(0),Tmax(0),Tstart(0),Gmax(0),Gstart(0),last(0){
	fin.open(filename.c_str());
	if(!fin.is_open())
		cout<<"Fail to open file:"<<filename<<endl;
	ReadFile();
}
int Sequence::numberOf(char base){
	switch(base){
		case 'A':return A;
				 break;
		case 'C':return C;
				 break;
		case 'T':return T;
				 break;
		case 'G':return G;
				 break;
		default:return 0;
	}
}

void Sequence::ReadFile(){
	char p;
	while((p=fin.get())!=EOF){
		switch(p){
			case 'A':getA();
					 break;
			case 'C':getC();
					 break;
			case 'T':getT();
					 break;
			case 'G':getG();
					 break;
			default:{
						last_t=last;
						last='\n';
					}
					 continue;
		}
		s+=p;
	}
	last=0;
}

void Sequence::getA(){
	static int tmpAstart=0;
	static int tmpAmax=0;
	A++;
	if(last=='A'){
		tmpAmax++;
		last='A';
	}
	else {
		if(last=='\n'){
			last=last_t;
			return;
		}
		last='A';
		if(tmpAmax>Amax)
			Astart=tmpAstart;
		tmpAmax=1;
		tmpAstart=s.size();
	}
}
void Sequence::getC(){
	static int tmpCstart=0;
	static int tmpCmax=0;
	C++;
	if(last=='C'){
		tmpCmax++;
		last='C';
	}
	else {
		if(last=='\n'){
			last=last_t;
			return;
		}
		last='C';
		if(tmpCmax>Cmax)
			Cstart=tmpCstart;
		tmpCmax=1;
		tmpCstart=s.size();
	}
}
void Sequence::getT(){
	static int tmpTstart=0;
	static int tmpTmax=0;
	T++;
	if(last=='T'){
		tmpTmax++;
		last='T';
	}
	else {
		if(last=='\n'){
			last=last_t;
			return;
		}
		last='T';
		if(tmpTmax>Tmax)
			Tstart=tmpTstart;
		tmpTmax=1;
		tmpTstart=s.size();
	}
}
void Sequence::getG(){
	static int tmpGstart=0;
	static int tmpGmax=0;
	G++;
	if(last=='G'){
		tmpGmax++;
		last='G';
	}
	else {
		if(last=='\n'){
			last=last_t;
			return;
		}
		last='G';
		if(tmpGmax>Gmax)
			Gstart=tmpGstart;
		tmpGmax=1;
		tmpGstart=s.size();
	}
}

string Sequence::longestConsecutive(){
	int max=Amax;
	if(Cmax>max)
		max=Cmax;
	if(Tmax>max)
		max=Tmax;
	if(Gmax>max)
		max=Gmax;
	int num[4]={Amax,Cmax,Tmax,Gmax};
	int loc[4]={Astart,Cstart,Tstart,Gstart};
	int min=99999999;
	int index;
	for(int i=0;i<4;i++)
		if(num[i]==max&&loc[i]<min)
			index=i;
	cout<<Amax<<" "<<Cmax<<" "<<Tmax<<" "<<Gmax<<Astart<<" "<<Cstart<<" "<<Gstart<<" "<<Tstart<<endl;
	switch(index){
	case 1:return(string('A',Amax));
	case 2:return(string('C',Cmax));
	case 3:return(string('T',Tmax));
	case 4:return(string('G',Gmax));
	}
}
string Sequence::longestRepeated(){
}
