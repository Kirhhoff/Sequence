#include"Sequence.h"
#include<ctime>

int main(){
	Sequence tmp("dna.txt");
	cout<<"A: "<<tmp.numberOf('A')<<endl;
	cout<<"C: "<<tmp.numberOf('C')<<endl;
	cout<<"T: "<<tmp.numberOf('T')<<endl;
	cout<<"G: "<<tmp.numberOf('G')<<endl;
	cout<<"Sum: "<<tmp.length()<<endl;
	cout<<tmp.longestConsecutive()<<endl;
	time_t t1=clock();
	cout<<tmp.longestRepeated()<<endl;
	time_t t2=clock();
	cout<<"Time: "<<(double)(t2-t1)/CLOCKS_PER_SEC<<endl;
}
