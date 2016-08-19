#include<iostream>

using namespace std;

int vecx[4] = {-1,0,0,1};
int vecy[4] = {0,-1,1,0};

int H,W;
int sx,sy;
int ans;
char arr[21][21];
bool visited[21][21];

void dfs(int i,int j)
{
	visited[i][j] = true;
	
	for(int k=0;k<4;k++)
	{
		int xx = i+vecx[k];
		int yy = j+vecy[k];
		
		if(xx>=0 && yy>=0 && xx<H && yy<W && !visited[xx][yy] && (arr[xx][yy] == '.' || arr[xx][yy] == '@'))
			dfs(xx,yy);
	}
}

void ini()
{
	for(int i=0;i<21;i++)
		for(int j=0;j<21;j++)
			visited[i][j] = false;
	ans = 0;
}

int main()
{
	while(cin >> W >> H && H && W)
	{
		ini();
		for(int i=0;i<H;i++)
			for(int j=0;j<W;j++)
			{
				cin >> arr[i][j];
				if(arr[i][j] == '@')
				{
					sx = i;
					sy = j;
				}
			}
		dfs(sx,sy);
		
		for(int i=0;i<H;i++)
			for(int j=0;j<W;j++)
				if(visited[i][j])
					ans++;
		
		cout << ans << endl;
	}
	
}
