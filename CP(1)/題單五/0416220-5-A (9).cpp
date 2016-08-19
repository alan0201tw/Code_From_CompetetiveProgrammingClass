#include <iostream>

using namespace std;

int visited[105][105] = {0};
char oil[105][105];

int vector1[8] = {-1,-1,-1,0,0,1,1,1};
int vector2[8] = {-1,0,1,-1,1,-1,0,1};

void dfs(int i,int j)
{
	if(oil[i][j] == 0 ||oil[i][j] == '*' || visited[i][j] == 1)
		return;
	
	visited[i][j] = 1;
	
	for(int k=0;k<8;k++)
		if(i+vector1[k]>=0 && j+vector2[k]>=0)
			dfs(i+vector1[k],j+vector2[k]);	
}

int main()
{
	int m,n;
	while(cin>>m>>n && m&&n)
	{
		for(int i=0;i<105;i++)
			for(int j=0;j<105;j++)
			{
				oil[i][j] = 0;
				visited[i][j] = 0;
			}
			
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				cin >> oil[i][j];
				
		int ans = 0;
		
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				if(visited[i][j] == 0 && oil[i][j] == '@')
				{
					dfs(i,j);
					ans++;
				}
			}
		
		cout << ans << endl;
	}
	
}
