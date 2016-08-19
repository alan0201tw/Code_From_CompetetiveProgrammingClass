#include <iostream>
#include <queue>

using namespace std;

int stx,sty,ex,ey;
int m,n;
char forest[105][105];
int step[105][105];

int zvecx[8] = {-2,-2,-1,-1,1,1,2,2};
int zvecy[8] = {-1,1,-2,2,-2,2,-1,1};

int kvecx[8] = {-1,-1,-1,0,0,1,1,1};
int kvecy[8] = {-1,0,1,-1,1,-1,0,1};

void bfs()
{
	queue <int> qx,qy;
	
	for(int i=0;i<105;i++)
		for(int j=0;j<105;j++)
			step[i][j] = -1;
	
	step[stx][sty] = 0;
	qx.push(stx);
	qy.push(sty);
	
	while(!qx.empty())
	{
		int posx = qx.front();
		int posy = qy.front();
		qx.pop();qy.pop();
		if(posx == ex && posy == ey) return ;
		
		for(int k=0;k<8;k++)
		{
			int px = posx + kvecx[k];
			int py = posy + kvecy[k];
			
			if(px>=0 && px<m && py>=0 && py<n && step[px][py]==-1 && forest[px][py]!='Z' && forest[px][py]!='W')
			{
				step[px][py] = step[posx][posy]+1;
				qx.push(px);
				qy.push(py);
			}
		}
	}
}

int main()
{
	int task;
	cin >> task;
	while(task--)
	{
		cin >> m >> n;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				cin >> forest[i][j];
				if(forest[i][j] == 'A')
				{
					stx = i;
					sty = j;
				}
				else if(forest[i][j] == 'B')
				{
					ex = i;
					ey = j;
				}
			}
		
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				if(forest[i][j] == 'Z')
					for(int k=0;k<8;k++)
					{
						int zx = i+zvecx[k];
						int zy = j+zvecy[k];
						if(zx>=0 && zx < m && zy>=0 && zy < n && forest[zx][zy] == '.')
							forest[zx][zy] = 'W';
					}
			}

		bfs();

		if(step[ex][ey]!=-1)
			cout << "Minimal possible length of a trip is " << step[ex][ey] << endl;
		else
			cout << "King Peter, you can't go now!" << endl;
	}
}
