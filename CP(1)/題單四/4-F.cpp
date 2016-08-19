#include <iostream>

using namespace std;

int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		char in;
		int arr[n][m];
		int a[n][m] = {};
		int ans=0;
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				cin >> in;
				if(in == 'B')
					arr[i][j] = 1;
				else
					arr[i][j] = -1;
			}
		
		for(int i=n-1;i>=0;i--)
			for(int j=m-1;j>=0;j--)
			{
				if(a[i][j] != arr[i][j])
				{
					ans++;
					
					for(int x=0;x<=i;x++)
						for(int y=0;y<=j;y++)
							a[x][y] += arr[i][j] - a[i][j];
				}
			}
		
		cout << ans << endl;
	}
	
}
