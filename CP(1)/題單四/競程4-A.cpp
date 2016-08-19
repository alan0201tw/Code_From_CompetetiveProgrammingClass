#include <iostream>

using namespace std;

int main()
{
	int n;
	while(cin >> n && n)
	{
		int a[n];
		for(int i=0;i<n;i++)
			cin >> a[i];
		
		int t[n]={0};
		int out = 0;
		
		t[0] = max(0,a[0]);
		
		for(int k=1;k<n;k++)
		{
			t[k] = max(a[k] , t[k-1]+a[k]);
			out = max(out,t[k]);
		}
		
		if(out)
			cout << "The maximum winning streak is " << out << ".\n";
		else
			cout << "Losing streak.\n";
	}
	
	
}
