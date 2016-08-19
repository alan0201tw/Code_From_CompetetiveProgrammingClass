#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct lock
{
	char d[4];
	int num;
};
struct path
{
	lock a,b;
	int w;
};

vector <lock> all;
vector <path> p;
int par[510];

int cal_roll(lock a,lock b)
{
	int sum=0;
	for(int i=0;i<4;i++)
	{
		int t;
		int aa = a.d[i]-'0';
		int bb = b.d[i]-'0';
		if(aa > bb)
			t = aa - bb;
		else
			t = bb - aa;
		if(t>5)
			t = 10-t;
		sum += t;
	}
	return sum;
}
bool sss(path a,path b)
{
	if(a.w >= b.w)
		return false;
	return true;
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
	for(int i=0;i<510;i++)
		par[i] = i;
	p.clear();
	all.clear();
}
int main()
{
	int task;
	cin >> task;
	while(task--)
	{
		init();	
		int n;
		cin >> n;
		lock in;
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<4;k++)
				cin >> in.d[k];
			in.num = i;
			all.push_back(in);
		}
		
		lock com;
		int siz = all.size();
		for(int k=0;k<4;k++)
			com.d[k] = '0';
		int plus=50;
		for(int i=0;i<siz;i++)
			plus=min(plus,cal_roll(com,all[i]));
			
		for(int i=0;i<siz;i++)
			for(int j=i+1;j<siz;j++)
			{
				path temp;
				temp.a = all[i];
				temp.b = all[j];
				temp.w = cal_roll(temp.a,temp.b);
				p.push_back(temp);
			}
		sort(p.begin(),p.end(),sss);
		siz = p.size();
		int ans=0;
		for(int i=0;i<siz;i++)
		{
			int na=p[i].a.num;
			int nb=p[i].b.num;
			int nw=p[i].w;
			if(find(na) != find(nb))
			{
				setu(na,nb);
				ans+=nw;
			}
		}
		cout << ans+plus << endl;
	}
}
