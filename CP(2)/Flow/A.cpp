#include <iostream>
#include <queue>

using namespace std;

int cap[101][101] = {};
int flow[101][101] = {};
int bottleneck[101] = {};
int pre[101] = {};

int bfs(int N,int S,int T)
{
	int re = 0;
	while(1)
	{
		for(int i=0;i<=N;i++)
			bottleneck[i] = 0;
		
		queue <int> q;
		q.push(S);
		bottleneck[S] = 999999999;
		
		while(!q.empty() && bottleneck[T] == 0)
		{
			int cur = q.front();
			q.pop();
			for(int nxt = 1;nxt <= N;nxt++)
			{
				if(bottleneck[nxt] == 0 && cap[cur][nxt] > flow[cur][nxt])
				{
					q.push(nxt);
					pre[nxt] = cur;
					bottleneck[nxt] = min(bottleneck[cur] , cap[cur][nxt] - flow[cur][nxt]);
				}
			}
		}
		
		if(bottleneck[T] == 0)
			break;
		
		for(int cur = T;cur != S;cur = pre[cur])
		{
			flow[pre[cur]][cur] += bottleneck[T];
			flow[cur][pre[cur]] -= bottleneck[T];
		}
		re += bottleneck[T];
	}
	return re;
}

int main()
{
	int N,S,T,C;
	int kase = 1;
	while(cin >> N && N)
	{
		for(int i=0;i<=N;i++)
			for(int j=0;j<=N;j++)
			{
				cap[i][j] = 0;
				flow[i][j] = 0;
			}
		
		cin >> S >> T >> C;
		int a,b,width;
		for(int i=0;i<C;i++)
		{
			cin >> a >> b >> width;
			cap[a][b] = (cap[b][a] += width);	//exist more than a connection between a and b
		}
		int ans = bfs(N,S,T);
		
		cout << "Network " << kase++ << endl;
		cout << "The bandwidth is " << ans << "." << endl << endl;
	}
}
