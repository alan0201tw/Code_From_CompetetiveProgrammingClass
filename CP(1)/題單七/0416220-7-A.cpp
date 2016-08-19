#include <iostream>
#include <queue>

using namespace std;

int map[1010][1010] = {};	//1 for bomb , 0 for road , 2 for start , 3 for end.
bool visit[1010][1010];
int step[1010][1010];

int vecx[4] = {-1,0,0,1};
int vecy[4] = {0,-1,1,0};

int r,c;
int sx,sy,ex,ey;

void bfs()
{
	queue <int> qx,qy;
	
	for(int i=0;i<1010;i++)
		for(int j=0;j<1010;j++)
		{
			visit[i][j] = false;
			step[i][j] = 0;
		}
		
	visit[sx][sy] = true;
	
	qx.push(sx);
	qy.push(sy);
			
	while(!qx.empty())
	{
		int px=qx.front();
		int py=qy.front();
		qx.pop();
		qy.pop();
				
		for(int p=0;p<4;p++)
			if(!visit[px+vecx[p]][py+vecy[p]] && (map[px+vecx[p]][py+vecy[p]]==0 || map[px+vecx[p]][py+vecy[p]]==3) && px+vecx[p]>=0 && px+vecx[p]<r && py+vecy[p]>=0 && py+vecy[p]<c)
			{
				qx.push(px+vecx[p]);
				qy.push(py+vecy[p]);
				visit[px+vecx[p]][py+vecy[p]] = true;
				
				step[px+vecx[p]][py+vecy[p]] = step[px][py]+1;
				if(visit[ex][ey])
					return;
			}
	}
		 
}

int main()
{
	while(cin >> r >> c && r && c)
	{
		int t;
		cin >> t;
		while(t--)
		{
			int row;
			int bombnum;
			int col;
		
			cin >> row >> bombnum;
			while(bombnum--)
			{
				cin >> col;
				map[row][col] = 1;
			}
		}
		cin >> sx >> sy;
		map[sx][sy] = 2;
		cin >> ex >> ey;
		map[ex][ey] = 3;
	
		bfs();
		cout << step[ex][ey] << endl;
		
		for(int i=0;i<1010;i++)
			for(int j=0;j<1010;j++)
				map[i][j] = 0;
	}
}
