#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue <int> d1,d2;
	int task;
	cin >> task;
	while(task--)
	{
		int n,m;
		cin >> n >> m;
		int gang[n+1];
		bool first = true;
		
		for(int i=1;i<=n;i++)
			gang[i] = i;
		
		while(m--)
		{
			char c;
			int a,b;
			scanf("%c %d %d",&c,&a,&b);
			if(c=='D')
			{
				if(first)
				{
					gang[a] = 0;
					gang[b] = 1e9;
					first = false;
				}
				else
				{
					if(gang[a]==-1 && (gang[b]==0 || gang[b]==1e9))
						gang[a] = 1e9-gang[b];
					else if(gang[b]==-1 && (gang[a]==0 ||gang[a]==1e9))
						gang[b] = 1e9-gang[a];
					else
					{
						d1.push(a);
						d2.push(b);
						gang[a] = -gang[b];
					}
				}
			}
			else if(c=='A')
			{
				int d1d,d2d;
				while(!d1.empty())
				{
					if(gang[d1.front()] ==0 || gang[d1.front()]==1e9)
						gang[d2.front()] = 1e9-gang[d1.front()];
					else if(gang[d2.front()] == 0 || gang[d2.front()]==1e9)
						gang[d1.front()] = 1e9-gang[d2.front()];
					else
					{
						d1.push(d1.front());
						d2.push(d2.front());
					}
						
					d1.pop();
					d2.pop();
				}
				if(gang[a] == gang[b])
					cout << "In the same gang.\n";
				else if((gang[a] == 1e9-gang[b])|| gang[a] == -gang[b])
					cout << "In different gangs.\n";
				else
					cout << "Not sure yet.\n";
			}
			for(int k=1;k<=n;k++)
				cout << gang[k] << " ";
			cout << endl;
		}
	}
}
