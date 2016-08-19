#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

struct ppair
{
	int x,y;
	int num;
};
struct edge
{
	ppair a,b;
	int w;
};

int n;
int tnum=1;
int par[210];
int ans=0;
vector <ppair> P;
vector <edge> E;

int dis(ppair a,ppair b)
{
	int d=0;
	if(a.x > b.x)
		d += (a.x - b.x)*(a.x - b.x);
	else
		d += (b.x - a.x)*(b.x - a.x);
	if(a.y > b.y)
		d += (a.y - b.y)*(a.y - b.y);
	else
		d += (b.y - a.y)*(b.y - a.y);
		
	return d;
}
bool sss(edge a,edge b)
{
	if(a.w<b.w)
		return true;
	return false;
}
int find(int x)
{
	if(par[x]==x)
		return x;
	par[x] = find(par[x]);
	return par[x];
}
void setu(int x,int y)
{
	int px = find(x);
	int py = find(y);
	if(px==py)
		return;
	par[px] = py;
}
void init()
{
	P.clear();
	E.clear();
	for(int i=0;i<210;i++)
		par[i] = i;
	ans = 1e9;
}

int main()
{
	while(cin >> n && n)
	{
		init();
		
		for(int i=0;i<n;i++)
		{
			ppair pp;
			cin >> pp.x >> pp.y;
			pp.num = i;
			P.push_back(pp);
		}
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				edge t;
				t.a = P[i];
				t.b = P[j];
				t.w = dis(t.a,t.b);
				E.push_back(t);
			}
		sort(E.begin(),E.end(),sss);
		int siz = E.size();
		for(int i=0;i<siz;i++)
		{
			int na=E[i].a.num;
			int nb=E[i].b.num;
			int nw=E[i].w;
			
			cout << na << " " << nb << " " << nw << endl;
			
			if(find(na) != find(nb))
				setu(na,nb);
			ans = min(ans,nw);
		}
		cout << "Scenario #" << tnum++ << endl;
		cout << "Frog Distance = " << fixed << setprecision(3) << double(sqrt(ans)) << endl;
		cout << endl;
	}
}
