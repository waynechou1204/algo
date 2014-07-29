#include <iostream>
#include <string>

using namespace std; 


int main(){
	
	int NEXT[1000009] = {0}; NEXT[0]=-1;
	int p=0,q=0;

	char ori[1000009];
	char par[10009];

	cin >> ori;
	cin >> par;

	int len;

	while(q<=len){
		if (ori[p]!=par[q]){
			q=NEXT[q];
		}
		else{
			p++;
			q++;
			NEXT[p]=q;
		}
	}

	return 0;
}