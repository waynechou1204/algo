#include <iostream>
#include <cstring>
#include <cmath>

using namespace std; 

char* insertSpecialChar(char* str){
	int len = strlen(str);
	char* res = new char((len*2+1)*sizeof(char));
	for (int i = 0; i < len; ++i)
	{
		res[2*i]='-';
		if(i!=len+1){
			res[2*i+1]=str[i];
		}
	}
	return res;
}

int getPalindromeAtIndex(int index,int left,int right,int len,char* str){
	if (left<0 || right==strlen(str))
	{
		return len;
	}
	if (str[left]!=str[right])
	{
		return len;
	}
	else{
		return getPalindromeAtIndex(index,left-1,right+1,len+1,str);
	}
}

int getRightBord(int* f,int j){
	return j+f[j]/2;
}

int foo(char* str){
	
	int f[20000]={1};

	int j=1;

	for (int i = 1; i < strlen(str); ++i)
	{
		int minEstimate = min(f[2*j-i],f[j]-2*(i-j));
		f[i] = getPalindromeAtIndex(i,i-minEstimate/2-1,i+minEstimate/2+1,minEstimate,str);
		if (j<=getRightBord(f,i)){
			j=i;
		}
	}

	int max=0;
	j=0;
	for (int i = 0; i < strlen(str); ++i)
	{
		if (f[i]>max)
		{
			j=i;
			max=f[i];
		}
	}

	return (f[j]-1)/2;
}

int main(){
	
	int loop=0;
	
	cin >> loop;

	char str[1000009];
		
	for (int i = 0; i < loop; ++i)
	{
		cin >> str;
		char* longstr = insertSpecialChar(str);
		int len = foo(longstr);

		cout << foo(longstr);
	}

	cin>>loop;
	return 0;
}