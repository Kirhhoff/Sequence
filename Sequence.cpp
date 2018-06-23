#include"Sequence.h"

Sequence::Sequence(string filename):last(0){
	Num[4]={};
	Start[4]={};
	Max[4]={};
	fin.open(filename.c_str());
	if(!fin.is_open())
		cout<<"Fail to open file:"<<filename<<endl;
	ReadFile();
}

void Sequence::ReadFile(){
	char p;
	while((p=fin.get())!=EOF){
		if(p=='\n')
			continue;
		getX(p);
		s+=p;
	}
	//getX('p');
}

int getIndex(char base){
	switch(base){
			case 'A':return 0;
			case 'C':return 1;
			case 'T':return 2;
			case 'G':return 3;
	}
}
char getBase(int index){
	switch(index){
		case 0:return 'A';
		case 1:return 'C';
		case 2:return 'T';
		case 3:return 'G';
	}
}
void Sequence::getX(char base){
	static long tmpStart[4]={};
	static long tmpMax[4]={};
	static int index=0;
	
	if(base=='p'){
		for(int i=0;i<4;i++)
			if(tmpMax[i]>Max[i])
				Max[i]=tmpMax[i];
		return;
	}
	index=getIndex(base);
	Num[index]++;
	if(last==base){
		tmpMax[index]++;
		last=base;
	}
	else{
		last=base;
		if(tmpMax[index]>Max[index]){
			Start[index]=tmpStart[index];
			Max[index]=tmpMax[index];
		}
		tmpMax[index]=1;
		tmpStart[index]=s.size();
	}
}
string Sequence::longestConsecutive(){
	int maxIndex=0;
	long maxMax=0;
	long minStart=9999999;
	for(int i=0;i<4;i++)
		if(Max[i]>maxMax){
			maxIndex=i;
			maxMax=Max[i];
		}
	for(int i=0;i<4;i++)
		if(Max[i]==maxMax&&Start[i]<minStart)
			maxIndex=i;
	//for(int i=0;i<4;i++)
		//cout<<i<<": "<<Max[i]<<" "<<Start[i]<<endl;
	return string(Max[maxIndex],getBase(maxIndex));
}
long Sequence::Match(string point){
	long len=point.size();
	long start=0;
	long times=0;
	while((start=s.find(point,start))!=string::npos){
		start+=len;
		times++;
	}
	return times;
}
void Sequence::Filter(Sequence::Table* tmp){
	
	for(int i=0;i<4;i++){
		tmp->Sons[i]=new Table(tmp->Heads[i]);
		tmp->matchs[i]=Match(tmp->Heads[i]);
		//cout<<tmp->Heads[i]<<" "<<tmp->matchs[i]<<endl;
	}
	for(int i=0;i<4;i++)
		if(tmp->matchs[i]>=2){
			if(tmp->Heads[i].size()>BestString.size()){
				cout<<tmp->Heads[i]<<endl;
				BestString=tmp->Heads[i];
			}
		}
		else{
			delete tmp->Sons[i];
			tmp->Sons[i]=0;
		}
	for(int i=0;i<4;i++)
		if(tmp->Sons[i]){
			Filter(tmp->Sons[i]);
			delete tmp->Sons[i];
		}
}
string Sequence::longestRepeated(){
	int size=s.size();
	string* tmp=new string[3*size/4];
	for(int i=0;i<3*size/4;i++){
		tmp[i]=string(s,i,size/4);
		int t=Match(tmp[i]);
		if(t>1)
			cout<<t<<endl;
	}
}
