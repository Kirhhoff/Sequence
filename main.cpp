#include"Sequence.h"


int main(){
	Sequence tmp("dna.txt");
	cout<<"A: "<<tmp.numberOf('A')<<endl;
	cout<<"C: "<<tmp.numberOf('C')<<endl;
	cout<<"T: "<<tmp.numberOf('T')<<endl;
	cout<<"G: "<<tmp.numberOf('G')<<endl;
	cout<<"Sum: "<<tmp.length()<<endl;
	tmp.longestConsecutive();
	tmp.longestRepeated();
}
