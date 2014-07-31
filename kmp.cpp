#include <iostream>
#include <string>

using namespace std; 


int main(){
	
	int NEXT[10009]={0}; 
	int p=1,q=0;

	char ori[1000009];
	char par[10009];

	//cin >> ori;
	cout << "Enter partern"<< endl;
	cin >> par;

	cout << "go!"<<endl;

	int len=6;

	while(q<=len){
		if (par[p]!=par[q]){
			q=NEXT[q];
		}
		else{
			p++;
			q++;
			NEXT[p]=q;
		}
	}
	
	NEXT[0]=-1;
	
	for (int i = 0; i < len; ++i)
	{
		cout << NEXT[i];
	}

	string s;
	cout << "The end";
	cin >> s;
	return 0;
}