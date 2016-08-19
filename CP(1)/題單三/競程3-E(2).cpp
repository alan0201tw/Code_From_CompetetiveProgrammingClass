#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int  main()
{
	int t,n,m;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		
		int a[m];
		
		for(int i=0;i<m;i++)
			cin >> a[i];
			
		sort(a,a+m);
		
		int l=0,r=(a[m-1]-a[0]+1)*2;
		int need = 1;
		int mid;
		
		while(r>l)
		{
			mid = (l+r)/2;
			int start = a[0];
			need = 1;
			
			for(int k=1;k<m;k++)
			{
				if(a[k] > start+mid)
				{
					start = a[k];
					need ++;
				}
			}
			if(need > n)
				l = mid+1;
			else
				r = mid;
		}
		
		cout <<fixed<<setprecision(1) <<  (double)r/2.0 << endl;
		
	}
	
}
