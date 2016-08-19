#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void dectobin (int dec , int bin[])
{
	int l=0;
	while(dec)
	{
		bin[l] = dec%2;
		dec = dec/2;
		l++;
	}
}

int main()
{	
	//int pick[15] = {0};
	//dectobin(0,pick);
	//for(int p=0;p<15;p++)
	//	cout << pick[p] << " ";
	
	int n,l,r,x;
	while(cin >> n >> l >> r >> x)
	{
		int sup=1;
		for(int s=0;s<n;s++)
			sup *= 2;
		
		int a[n];
		for(int i=0;i<n;i++)
			cin >> a[i];
			
		int sum = 0,biggest = 0,least=1e9,ans=0;
		
		int pick[15] = {0};
		for(int k=0;k<sup;k++)
		{
			dectobin(k,pick);
			for(int h=0;h<15;h++)
			{
				if(pick[h] == 1)
				{
					pick[h] = 2;
					sum += a[h];
					
					if(a[h] > biggest)
						biggest = a[h];
					if(a[h] < least)
						least = a[h];
				}
			}
			if(sum <= r && sum >= l && biggest - least >= x)
				ans ++;
			sum = 0;biggest=0;least=1e9;
		}
		cout << ans << endl;
	}
}
