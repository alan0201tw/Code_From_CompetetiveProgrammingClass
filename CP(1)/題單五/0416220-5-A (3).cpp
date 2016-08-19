#include <iostream>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	
	int par[n+1][n+1];
	int chi[n+1][n+1];
	int sizpar[n+1];
	int sizchi[n+1];
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			par[i][j] = 0;
			chi[i][j] = 0;	
		}
		sizpar[i]=0;
		sizchi[i]=0;
	}
	
	while(m--)
	{
		int a,b;
		cin >> a >> b;
		par[a][sizpar[a]] = b;	//a->b
		chi[b][sizchi[b]] = a;	//b->a
		
		sizpar[a]++;
		sizchi[b]++;
	}
	
	int ans=0;
	int edsum[n+1][n+1] = {};
	
	for(int s=1;s<=n;s++)
	{
		for(int i=0;i<sizpar[s];i++)
			for(int j=0;j<sizchi[s];j++)
			{
				if(par[s][i] != chi[s][j])
					edsum[par[s][i]][chi[s][j]]++;
			}
			
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans += edsum[i][j]*(edsum[i][j]-1)/2;
	
	cout << ans << endl;
	
	
}
