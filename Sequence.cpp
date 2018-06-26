#include"Sequence.h"

char Base[]="ACTG";
Sequence::Table::Table(string baseString,int com){
	common=com;
	cMatchs=0;
	for(int i=0;i<4;i++)
		Heads[i]=baseString+Base[i];
}

Sequence::Sequence(string filename):last(0),Ancestor(new Table("",0)){
	for(int i=0;i<4;i++){
		Num[i]=0;
		Start[i]=0;
		Max[i]=0;
		Ancestor->Sons[i]=new Table(Ancestor->Heads[i],1);
		Ancestor->Sons[i]->cStarts=new int[MAX];
	}
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
}

int getIndex(char base){
	switch(base){
			case 'A':return 0;
			case 'C':return 1;
			case 'T':return 2;
			case 'G':return 3;
	}
}

void Sequence::getX(char base){
	static int tmpStart[4]={};
	static int tmpMax[4]={};
	static int index=0;
	
	if(base=='p'){
		for(int i=0;i<4;i++)
			if(tmpMax[i]>Max[i])
				Max[i]=tmpMax[i];
		return;
	}
	index=getIndex(base);
	Num[index]++;
	Ancestor->Sons[index]->cStarts[Ancestor->Sons[index]->cMatchs++]=s.size();
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
	int maxMax=0;
	long minStart=9999999;
	for(int i=0;i<4;i++)
		if(Max[i]>maxMax){
			maxIndex=i;
			maxMax=Max[i];
		}
	for(int i=0;i<4;i++)
		if(Max[i]==maxMax&&Start[i]<minStart)
			maxIndex=i;
	return string(Max[maxIndex],Base[maxIndex]);
}

void Sequence::Filter(Sequence::Table* tmp){{
	int mIndex;
	for(int i=0;i<4;i++){
		tmp->Sons[i]=new Table(tmp->Heads[i],tmp->common+1);
		tmp->Sons[i]->cStarts=new int[tmp->cMatchs];
	}
	for(int i=0;i<tmp->cMatchs;i++){
		mIndex=getIndex(s[tmp->cStarts[i]+tmp->common]);
		tmp->Sons[mIndex]->cStarts[tmp->Sons[mIndex]->cMatchs++]=tmp->cStarts[i];
	}
}
	for(int i=0;i<4;i++){
		Table*& Stmp=tmp->Sons[i];
		if(Stmp->cMatchs>1){
			if(Stmp->common>BestString.size())
				BestString=tmp->Heads[i];
			Filter(Stmp);
		}
		delete Stmp;
	}
	delete tmp->cStarts;
}
string Sequence::longestRepeated(){
	for(int i=0;i<4;i++)
		Filter(Ancestor->Sons[i]);
	return BestString;
}
