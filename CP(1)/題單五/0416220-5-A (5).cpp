#include <iostream>
#include <queue>

using namespace std;

int vecx[4] = {-1,0,0,1};
int vecy[4] = {0,-1,1,0};
char forest[1010][1010] = {};
int si,sj,ei,ej;
bool visited[1010][1010] = {};
bool flag = false;
int step[1010][1010] = {};
int r,c;

void bfs (int x,int y)
{
	queue <int> xx,yy;
	xx.push(x);
	yy.push(y);
	visited[x][y] = true;
	
	while(!xx.empty() && !yy.empty())
	{
		int qx = xx.front();
		int qy = yy.front();
		xx.pop();
		yy.pop();
		
		for(int i=0;i<4;i++)
		{
			int x1 = qx+vecx[i],y1 = qy+vecy[i];
							
			if(x1<r && y1<c && x1>=0 && y1>=0 && forest[x1][y1] != 'T' && !visited[x1][y1])
			{
				xx.push(x1);
				yy.push(y1);
				visited[x1][y1] = true;
				step[x1][y1] = step[qx][qy]+1;
			}
		}
	}
	
}



int main()
{
	cin >> r >> c;
	
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		{
			cin >> forest[i][j];
			if(forest[i][j] == 'S')
			{
				si = i;
				sj = j;
			}
			if(forest[i][j] == 'E')
			{
				ei = i;
				ej = j;
			}
		}
	
	bfs(ei,ej);
	int ans = 0;
	//cout << step[si][sj] << endl;
	
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			if(step[i][j] > 0 && step[i][j] <= step[si][sj] && forest[i][j] <= '9' && forest[i][j] >= '0')
				ans += forest[i][j] - '0';
				
	cout << ans << endl;
	
}
