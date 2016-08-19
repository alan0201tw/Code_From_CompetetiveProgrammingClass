#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		char in[95];
		
		scanf("%s",in);
		
		long long int lup=0,rup=1,lbot=1,rbot=0;
		
		for(int i=0;in[i];i++)
		{
			if(in[i] == 'L')
			{
				rup += lup;
				rbot += lbot;
			}
			else
			{
				lup += rup;
				lbot += rbot;
			}
		}
		cout << lup+rup << "/" << lbot+rbot << endl;
	}
}
