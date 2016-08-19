#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	bool flag = false;
	while(cin >> n)
	{
		int a[n];
		int b[n]; // all move to i=0;
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
			b[i] = a[i] + i;
		}
			
		sort(b,b+n);
		
		for(int k=0;k<n;k++)
			if(b[k] == b[k+1])
				flag = true;
			
		if(flag == true)
			cout << ":(\n";
		else
			for(int g=0;g<n;g++)
			{
				if(g<n-1)
					cout << b[g] - g << " ";
				else
					cout << b[g] - g << "\n";
			}
		
		flag = false;
		
	}
	
}
