#include <iostream>
#include <cstring>
#include <cmath>

using namespace std; 

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
		return getPalindromeAtIndex(index,left-1,right+1,len+2,str);
	}
}


int foo(char* str){
	
	int f[20000]={1};

	int j=0;
	int len=strlen(str);
	
	int max=0;
	int idx=0;
	
	for (int i = 1; i < len; ++i)
	{
		int minEstimate=1;
		if(2*j-i>=0){
			minEstimate = min(f[2*j-i],f[j]-2*(i-j));
		}
		f[i] = getPalindromeAtIndex(i,i-minEstimate/2-1,i+minEstimate/2+1,minEstimate,str);
		
		// compare right bord
		if (j+f[j]/2 < i+f[i]/2){
			j=i;
		}
		
		if (f[i]>max)
		{
			idx=i;
			max=f[i];
		}
	}

	return (f[idx]-1)/2;
}

int main(){
	
	int loop=0;
	
	cin >> loop;

	char str[10009];
		
	for (int i = 0; i < loop; ++i)
	{
		cin >> str;
		
		int len = strlen(str);
		
		//insert special '-'
		char res[20000];
		for (int i = 0; i < len; ++i)
		{
			res[2*i]='-';
			res[2*i+1]=str[i];
		}
		res[2*len]='-';
		res[2*len+1]='\0';
		
		//calculate
		len = foo(res);

		cout << len << endl;
	}

	return 0;
}