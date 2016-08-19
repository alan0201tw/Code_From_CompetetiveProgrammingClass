#include <iostream>

using namespace std;

int vecx[4] = {-1,0,0,1};
int vecy[4] = {0,-1,1,0};

int T;
int N;
char grid[101][101];
bool visit[101][101];
int count;
int kase=1;

void ini()
{
	count=0;
	for(int i=0;i<101;i++)
		for(int j=0;j<101;j++)
			visit[i][j] = false;	
}

void dfs_one(int i,int j)
{
	visit[i][j] = true;
	for(int k=0;k<4;k++)
	{
		int xx = i+vecx[k];
		int yy = j+vecy[k];
		
		if(xx>=0 && yy>=0 && xx<N && yy<N && !visit[xx][yy] && (grid[xx][yy] == '@' || grid[xx][yy] == 'x'))
			dfs_one(xx,yy);
	}
}

int main()
{
	cin >> T;
	while(T--)
	{
		ini();
		cin >> N;
		
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				cin >> grid[i][j];
		
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
			{
				if(grid[i][j] == 'x' && !visit[i][j])
				{
					dfs_one(i,j);
					count++;
				}
			}
		cout << "Case " << kase << ": " << count << endl;
		kase++;
	}
	
}
