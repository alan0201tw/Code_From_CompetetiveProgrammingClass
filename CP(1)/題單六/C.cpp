#include <iostream>
#include <stdio.h>

using namespace std;

int par[20000];

int enemy (int n)
{
	return 10000 + n;
}

int find(int a)
{
	if(par[a] == a)
		return a;
	par[a] = find(par[a]);
	return par[a];
}

void setunion(int a,int b)
{
	int pa = find(a);
	int pb = find(b);
	if(pa == pb)
		return;
	par[pa] = pb;
}

int main()
{
	int n;
	cin >> n;
	int com,a,b;
	
	for(int i=0;i<20000;i++)
		par[i] = i;
	
	while(cin >> com >> a >> b && com)
	{
		int pa = find(a);
		int pb = find(b);
		
		if(com == 1)
		{
			if(pa==pb || find(enemy(a)) == find(enemy(b)) || (pa!=find(enemy(b)) && pb!=find(enemy(a))))
			{
				setunion(a,b);
				setunion(enemy(a),enemy(b));
			}
			else
				cout << -1 << endl;
		}
		if(com == 2)
		{
			if(((find(enemy(a))==pb) || find(enemy(b))==pa ) || (pa!=pb && find(enemy(a)) != pb && find(enemy(b)) != pa))
			{
				setunion(enemy(a),b);
				setunion(a,enemy(b));
			}
			else
				cout << -1 << endl;
		}
		if(com == 3)
		{
			if(pa==pb || find(enemy(a)) == find(enemy(b)))
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		if(com == 4)
		{
			if(find(enemy(a))==pb || find(enemy(b))==pa )
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		
	}
}
