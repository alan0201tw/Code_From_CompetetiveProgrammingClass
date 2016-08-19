#include <iostream>

using namespace std;

int n;
bool adj[110][110];
bool ans[110];
int num;

void DFS (int st)
{
	for(int i=1;i<=n;i++)
		if(adj[st][i] && ans[i]==false)
		{
			num++;
			ans[i]=true;
			
			DFS(i);
		}
	return;
}


int main()
{
	while(cin>>n&&n)
	{
		for(int i=0;i<110;i++)
			for(int j=0;j<110;j++)
				adj[i][j] = false;
			
		num=0;
		
		int b,c;
		
		while(cin >> b && b)
			while(cin >> c && c)
				adj[b][c] = true;
		
		int ts;
		cin >> ts;
		while(ts--)
		{
			for(int i=0;i<110;i++)
				ans[i] = false;
			num = 0;
			
			int q;
			cin >> q;
			
			DFS(q);
			
			cout << n-num;
			
			bool fir=false;
			
			for(int i=1;i<=n;i++)
				if(!ans[i])
					cout << " " << i;
				
			cout << endl;
		}
	}
}
