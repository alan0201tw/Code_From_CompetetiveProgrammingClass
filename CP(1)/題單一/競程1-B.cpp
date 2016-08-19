#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n;
	int count = 0;
	while(cin >> n)
	{
		if(n && count == 1)
			cout << endl;
		else if (n == 0)
			break;
		
		count = 1;
		
		//a/y=n
		int limit = 100000/n + n;
		int check = 0;
		
		for(int y=1000;y<limit;y++)
		{
			int check2[10] = {0};
			long long int a = y*n;
			int ca = a,cy = y;
			int cacy = 0;
			
			while(ca>0)
			{
				check2[ca%10] = 1;
				ca /= 10;
			}
			
			while(cy>0)
			{
				check2[cy%10] = 1;
				cy /= 10;
			}
			
			if(y<10000)
				check2[0] = 1;
				
			
			for(int k = 0;k<10;k++)
			{
				if(check2[k] == 0)
					break;
				if(k == 9)
					cacy = 1;
			}
			
			
			if(a<100000 && cacy == 1)
				{
					check = 1;
					
					if(y >= 10000)
					cout << a << " / " << y << " = " << n << endl;
					else
					cout << a << " / 0" << y << " = " << n << endl;
				}
			
		}
		
		if(check == 0)
			cout << "There are no solutions for " << n << ".\n";
				
	}
}
