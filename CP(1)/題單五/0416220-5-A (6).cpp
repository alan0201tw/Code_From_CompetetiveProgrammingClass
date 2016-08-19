#include <iostream>
#include <vector>
#include <queue>
#define N 100100
using namespace std;
struct node {
	int v , w ;
	bool operator < (const node x) const {
		return w > x.w ;
	}
} ;
vector <int> w[N];
vector <int> path[N];
long long int d[N];
int parent[N];
int n,m;

void dij (int st)
{
	for(int i=0;i<=n;i++)
		d[i] = 1e12 ;

	priority_queue<node> Q ;
	d[st] = 0;
	parent[st] = st;
	Q.push(node{st,0}) ;
	while(!Q.empty())
	{
		//puts("AAA") ;
		int a ;
		a = Q.top().v ;
		Q.pop() ;
		for(int q=0;q<path[a].size();q++)
			if(d[a] + w[a][q] < d[path[a][q]])
			{
				d[path[a][q]] = d[a] + w[a][q];
				parent[path[a][q]] = a;
				Q.push(node{path[a][q],d[path[a][q]]}) ;
			}
	}
}

void find_path (int x)
{
	if(x!=parent[x])
		find_path(parent[x]);
	cout << x << " ";
}

int main()
{
	cin >> n >> m;
	while(m--)
	{
		int a,b,cos;
		cin >> a >> b >> cos;
		w[a].push_back(cos);	//a->path[a][x] 's cos
		w[b].push_back(cos);
		path[a].push_back(b);	//a able to get to path[a][x]
		path[b].push_back(a);
	}
	
	dij(1);
	
	if(d[n]!=1e12)
		find_path(n);
	else
		cout << -1;
	cout << endl;
}
