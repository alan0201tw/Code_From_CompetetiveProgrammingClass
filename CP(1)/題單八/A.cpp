#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge
{
	int a,b,w;
};

vector <edge> all;
int n,t,m;
int par[1000001];

void init()
{
	for(int i=0;i<1000001;i++)
		par[i] = i;
	all.clear();
}
bool sss(edge a,edge b)
{
	if(a.w > b.w)
		return false;
	return true;
}
int find(int n)
{
	if(par[n] == n)
		return n;
	par[n] = find(par[n]);
	return par[n];
}
void setu(int x,int y)
{
	int px = find(x);
	int py = find(y);
	
	if(px==py)
		return;
	par[px] = py;
}
int main()
{
	bool f=true;
	while(cin>>n)
	{
		if(f==false)
			cout << endl;
		else
			f = false;
		
		init();
		edge in;
		int ori_cost=0;
		for(int i=0;i<n-1;i++)
		{
			cin >> in.a >> in.b >> in.w;
			ori_cost += in.w;
		}
		cin >> t;
		for(int i=0;i<t;i++)
		{
			cin >> in.a >> in.b >> in.w;
			all.push_back(in);
		}
		cin >> m;
		for(int i=0;i<m;i++)
		{
			cin >> in.a >> in.b >> in.w;
			all.push_back(in);
		}
		sort(all.begin(),all.end(),sss);
		int new_cost=0;
		int siz = all.size();
		for(int i=0;i<siz;i++)
		{
			int na=all[i].a;
			int nb=all[i].b;
			int nw=all[i].w;
			if(find(na) != find(nb))
			{
				setu(na,nb);
				new_cost+=nw;
			}
		}
		cout << ori_cost << endl << new_cost << endl;
	}
}
