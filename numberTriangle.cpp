#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 

int getindex(int i,int j){
	return i*(i+1)/2+j-1;
}

int getBest(int i,int j,int* best,int *prize, int maxlevel){
	if (best[getindex(i,j)]!=-1)
	{
		return best[getindex(i,j)];
	}
	else if (j == maxlevel-1)
	{
		return prize[getindex(i,j)];
	}
	else
	{
		return best[getindex(i,j)] = prize[getindex(i,j)] + max(best[getindex(i+1,j)],best[getindex(i+1,j+1)]);
	}
}

int main()
{
	int levelnb = 0;
	cin >> levelnb;

	int prize[50500] = {0};
	int best[50500]={-1};

	for (int i = 0; i < levelnb*(levelnb+1)/2; ++i)
	{
		cin >> prize[i];
	}

	cout << getBest(0,0,best,prize,levelnb);

	cin >> levelnb;
	return 0;
}