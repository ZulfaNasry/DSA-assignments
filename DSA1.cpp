            //Boyer-moore Algorithm using c++
#include <bits/stdc++.h>
#include <fstream>  //for file handling
using namespace std;

int match=0; //count the number of matches

void BadChar( string str, int size, int badchar[256]){  //find bad char for next move
	int i;
	for (i = 0; i < 256; i++){
		badchar [i] = -1;
	}
	for (i = 0; i < size; i++){
		badchar[(int)str[i]]- i;
	}
}
int search(string txtline, string P, string T){ //search the string
	int m= P.size();  //size of pattern
	int n= T.size();  //size of text
	
	int badchar[256];
	BadChar(P, m, badchar);
	int s = 0;  //shift
	
	while(s <= (n-m)){
		int j = m - 1;
		while(j>=0 && P [j] == T[s + j]){
			j--;
		}
		if (j<0){
			
			cout << txtline << endl;  //print the line from a text
			match++;
			return 0;
		}else{
			int t= j-badchar[T[s+j]];
			if(t>=1){
				s=s+t;
			}else{
				s=s+1;
			}
			}
		}
	}
	
	
	
	
	int main(){
		string txt1,txt2;
		string txt3="";
		cout<<"enter a search string: ";
		cin>>txt2;
		ifstream file("modules.txt");
		while(getline(file,txt1)){
			txt3=txt1;
			search(txt3,txt2,txt1);
		}
		cout<<endl<<"Number of matches : "<< match ;
	}
