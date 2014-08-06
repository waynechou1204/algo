#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 

int getindex(int i,int j){
	return i*(i+1)/2+j;
}

int getBest(int i,int j,int* best,int *prize, int maxlevel){
	int index=getindex(i,j);

	if (best[index]!=0)
	{
		return best[index];
	}
	else if (i == maxlevel-1)
	{
		return prize[index];
	}
	else
	{
		best[index] = prize[index] + max(getBest(i+1,j,best,prize,maxlevel),getBest(i+1,j+1,best,prize,maxlevel));
		return best[index];
	}
}

int main()
{
	int levelnb = 0;
	cin >> levelnb;

	int prize[50500] = {0};
	int best[50500]={0};

	for (int i = 0; i < levelnb*(levelnb+1)/2; ++i)
	{
		cin >> prize[i];
	}

	cout << getBest(0,0,best,prize,levelnb);

	return 0;
}