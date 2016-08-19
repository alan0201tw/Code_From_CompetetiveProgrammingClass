#include <iostream>

using namespace std;

int path[105][105];

int main()
{
	int task;
	cin >> task;
	int casenum=1;
	while(task--)
	{
		for(int i=0;i<101;i++)
		{
			for(int j=0;j<101;j++)
				path[i][j] = 1e9;
			path[i][i] = 0;	
		}
		
		int n,r;
		int st,end;
		cin >> n;
		cin >> r;
		while(r--)
		{
			int a,b;
			cin >> a >> b;
			path[a][b] = path[b][a] = 1;
		}
		cin >> st >> end;
		
		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(path[i][j] > path[i][k] + path[k][j])
						path[i][j] = path[i][k] + path[k][j];
		
		int ans = 0;
		for(int k=0;k<n;k++)
			if(ans < path[st][k] + path[k][end])
				ans = path[st][k] + path[k][end];
		
		cout << "Case " << casenum << ": " << ans << endl;
		casenum++;
	}
	
}
