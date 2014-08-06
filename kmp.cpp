#include <iostream>
#include <cstring>

using namespace std; 


int main(){
	
	int NEXT[1000009]={0};
	
	char ori[1000009];
	char par[10009];

	int loopnb=0;
	cin >> loopnb;

	for(int i=0;i<loopnb;++i){
		cin >> par;
		cin >> ori;
	
		// construct NEXT array for partern
		int p=1,q=0;
		int parlen=strlen(par);
		while(p<parlen){
			if (par[p]!=par[q]){
				if(q==0){
					p++;
				}
				else{
					q=NEXT[q-1];
				}
			}
			else{
				q++;
				NEXT[p]=q;
				p++;
			}
		}

		// search nb of partern in the origin string
		int orilen=strlen(ori);
		p=q=0;
		int time=0;
		while(p<orilen){
			if(ori[p]!=par[q]){
				if(q==0){
					p++;
				}
				else{
					q=NEXT[q-1];
				}
			}
			else{
				q++;
				p++;
				if(q==parlen){
					q=NEXT[q-1];
					time++;
				}
			}
		}

		cout << time << endl;
	}
	
	return 0;
}