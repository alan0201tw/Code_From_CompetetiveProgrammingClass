#include <iostream>
#include <string>
using namespace std;

void cont (string a , int arr[])
{
	for(int i=0;i<a.size();i++)
		arr[a[i] - 'a'] ++ ;
}

int main()
{
	string a,b,c;
	while(cin >> a >> b >> c)
	{
		int ca[26]={0},cb[26]={0},cc[26]={0};
		
		cont(a,ca);
		cont(b,cb);
		cont(c,cc);
		
		int allforb = 1e9;
		
		for(int i=0;i<26;i++)
			if(cb[i] > 0)
				allforb = min(allforb , ca[i] / cb[i]);
				
		int i = {1e9} , ansb=0 , ansc=0;
				
		for(int k=0;k<=allforb;k++)
		{
			for(int j=0;j<26;j++)
				if(cc[j] > 0)
					i = min(i , (ca[j] - cb[j]*k)/cc[j]);
					
			if(i + k > ansb+ansc)
				{
					ansb = k;
					ansc = i;
				}
			
		}
				
		for(int numb=0;numb<ansb;numb++)
			cout << b;
		for(int numc=0;numc<ansc;numc++)
			cout << c;
		for(int numa=0;numa<26;numa++)
			while(ca[numa] - cb[numa]*ansb - cc[numa]*ansc)
			{
				cout << char(numa + 'a');
				ca[numa] --;
			}
		
		cout << endl;
		
	}
	
	
}
