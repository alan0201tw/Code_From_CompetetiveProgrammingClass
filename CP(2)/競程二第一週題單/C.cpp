#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

int main()
{
	int n,kk;
	int t[6];
	int floor[101];
	int weight[101][101];
	int dis[101];
	
	while(cin >> n >> kk)
	{
		for (int i = 0; i < 100; i++)
		{
            dis[i] = 1e9;
            for (int j = 0; j < 100; j++)
                weight[i][j] = 1e9;
        }
        
        for(int i=0;i<n;i++)
        	cin >> t[i];
		cin.ignore();
		for (int i = 0; i < n; i++)
		{
            string str;
            getline(cin, str);
            stringstream ss(str);
            int Count = 0;
            while (ss >> floor[Count])
				Count++;

            for (int x = 0; x < Count; x++)
                for (int y = x + 1; y < Count; y++)
				{
                    int f1 = floor[x], f2 = floor[y];
                    if ((f2-f1)*t[i] < weight[f1][f2])
                        weight[f1][f2] = weight[f2][f1] = (f2-f1)*t[i];
                }
        }
		
		queue <int> q;
		bool inqueue[101] = {};
		dis[0] = 0;
		inqueue[0] = true;
		q.push(0);
		while(!q.empty())
		{
			int now = q.front();
			inqueue[now] = false;
			q.pop();
			
			for(int k=0;k<100;k++)
			{
				if(dis[now] + weight[now][k] + 60 < dis[k])
				{
					dis[k] = dis[now] + weight[now][k] + 60;
					if(!inqueue[k])
					{
						q.push(k);
						inqueue[k] = true;
					}
				}
			}
		}
		if(kk==0)
			cout << 0 << endl;
		else if(dis[kk] == 1e9)
			cout <<  "IMPOSSIBLE" << endl;
		else
			cout << dis[kk] - 60 << endl;
		
	}
}
