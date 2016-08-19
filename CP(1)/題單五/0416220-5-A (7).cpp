#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	long long int sum = 0;
	
	long long int d[n+1][n+1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin >> d[i][j];
	
	int k;
	cin >> k;
	while(k--)
	{
		int a,b,c;
		cin >> a >> b >> c;
		
		if(c < d[a][b])
		{
			d[a][b] = c;
			d[b][a] = c;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(d[i][a] + d[a][b] + d[b][j] < d[i][j])
					{
						d[i][j] = d[i][a] + d[a][b] + d[b][j];
						d[j][i] = d[i][j];
					}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				sum += d[i][j];
				
		cout << sum/2 << " ";
		sum = 0;
	}
	cout << endl;
}
