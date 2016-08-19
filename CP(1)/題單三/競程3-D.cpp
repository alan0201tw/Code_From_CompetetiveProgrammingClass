#include <iostream>

using namespace std;

int bs (int q,int a[],int n)
{
	int l=0,r=n-1;
	
	while(l <= r)
	{
		int mid = (l+r)/2;
		
		if(a[mid] >= q && (a[mid-1] < q || mid==0))
			return mid+1;
		else if ( a[mid] < q)
			l = mid+1;
		else
			r = mid-1;
	}
	return -1;
}

int main()
{
	int n;
	while(cin >> n)
	{
		int a[n];
		int sum = 0;
		int t;
		
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
			t = a[i];
			a[i] += sum;
			sum += t;
		}
		int m;
		cin >> m;
		while(m--)
		{
			int q;
			cin >> q;
			
			cout << bs(q,a,n) << endl;
			
		}
		
	}
	
}
