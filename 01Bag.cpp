#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std; 


int main(){
	
	int v[100009]; //value
	int c[100009]; //cost
	double f[100009];

	int N=0;
	int M=0; // nb and total space

	cin >> N >> M;

	for(int i = 0; i < N; ++i){
		cin >> c[i] >> v[i];
	}
	
	for (int j = 0; j < M; ++j)
	{
		f[j]=0;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = M; j >= c[i]; --j)
		{
			f[j]=max(f[j] , f[j-c[i]]+v[i]);
		}
	}

	cout << f[M];
	cin>>N;
	return 0;
}