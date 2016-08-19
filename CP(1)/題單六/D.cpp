#include <iostream>

using namespace std;

int par[30010],son[30010],deep[30010];

int find(int n)
{
	if(par[n] == n)
		return n;
	int temp = par[n];
	par[n] = find(par[n]);
	deep[n] += deep[temp];
	return par[n];
}

int main()
{
	int p;
	cin >> p;
	
	for(int i=0;i<30010;i++)
	{
		par[i] = i;
		son[i] = 1;
		deep[i] = 0;
	}
	
	
	while(p--)
	{
		char c;
		int a,b;
		
		cin >> c;
		if(c=='M')
		{
			cin >> a >> b;
			int pa = find(a);
			int pb = find(b);
			
			if(pa!=pb)
			{
				par[pb] = pa;
				deep[pb] = son[pa];
				son[pa] += son[pb];
			}
		}
		else if(c=='C')
		{
			cin >> a;
			cout << son[find(a)]-deep[a]-1 << endl;
		}
	}
	
}
