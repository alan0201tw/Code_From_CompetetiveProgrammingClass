#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct edge
{
	int u,v,w;
};
int n,m;
vector <edge> vec;

bool BF()
{
	int d[105];
	for(int i=0;i<=n;i++)
		d[i] = 1e9;
	d[n+1] = 0;
	
	for(int i=0;i<=n;i++)
		for(int k=0;k<vec.size();k++)
			if(d[vec[k].v] > d[vec[k].u] + vec[k].w)
				d[vec[k].v] = d[vec[k].u] + vec[k].w;
	
	for(int k=0;k<vec.size();k++)
		if(d[vec[k].v] > d[vec[k].u] + vec[k].w)
			return false;
	return true;
}

int main()
{
	while(scanf("%d",&n)==1 && n)
	{
		cin >> m;
		vec.clear();
		while(m--)
		{
			int u,v,w;
			char oa,ob;
			cin >> u >> v >> oa >> ob >> w;
			if(oa == 'g')
			{
				vec.push_back(edge{u+v,u-1,-(w+1)});
			}
			else
			{
				vec.push_back(edge{u-1,u+v,w-1});
			}
		}
		for(int i=0;i<=n;i++)
			vec.push_back(edge{n+1,i,0});
		
		if(BF())
			cout << "lamentable kingdom\n";
		else
			cout << "successful conspiracy\n";
	}
}
