#include <iostream>

using namespace std;

bool adj[110][110];
int ref[110];
int n,m;
void topo ()
{
	for(int i=1;i<=n;i++)
		ref[i] = 0;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(adj[i][j])
				ref[j]++;
	
	for(int i=1;i<=n;i++)
	{
		int s=1;
		while(s<=n && ref[s]!=0)
			s++;
		
		if(s == n+1)
			break;
		
		ref[s] = -1;
		
		if(i<n)
			cout << s << " ";
		else
			cout << s << endl;
			
		for(int t=1;t<=n;t++)
			if(adj[s][t])
				ref[t]--;
	}
	return;
}

int main()
{
	while(cin >> n >> m)
	{
		if(n==0 && m==0)
			break;
		
		for(int i=0;i<110;i++)
			for(int j=0;j<110;j++)
				adj[i][j] = false;
		
		while(m--)
		{
			int t1,t2;
			cin >> t1 >> t2;
			
			adj[t1][t2] = true;
		}
		
		topo();
		
	}
	
}
