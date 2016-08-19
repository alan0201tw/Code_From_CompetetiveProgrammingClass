#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	long long int l;
	
	while(cin >> n >> l)
	{
		long double dis = 0;
		long double ar[n];
		for(int i=0;i<n;i++)
			cin >> ar[i];
			
		sort(ar,ar+n);
			
		if(ar[0] != 0)
			dis = ar[0];
		
		for(int k=0;k<n-1;k++)
		{
			if((ar[k+1] - ar[k])/2 > dis)
				dis = (ar[k+1] - ar[k])/2;
		}
		
		if(l - ar[n-1] > dis)
		 dis = l - ar[n-1];
		
		cout << fixed << setprecision(9) << dis << endl;
	}
	
	
	
}
