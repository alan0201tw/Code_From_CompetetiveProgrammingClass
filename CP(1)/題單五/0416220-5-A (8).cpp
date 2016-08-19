#include <iostream>

using namespace std;

bool visited[210];
long long int circle[210];
long long int ss[210];
long long int n;
long long int f[210];
long long int maxv=0;
long long int lcm;

void clea()
{
	for(int i=1;i<=200;i++)
	{
		visited[i] = false;
		ss[i] = 0;
	}
}

long long int dfs(long long int at,long long int stepp)
{
	if(visited[at])
	{
		maxv = max(maxv,ss[at]);
		return stepp - ss[at];
	}
	
	visited[at] = true;
	ss[at] = stepp;
	dfs(f[at],stepp+1);
}

long long int gcd(long long int a,long long int b)
{  
    return b == 0 ? a : gcd(b,a % b);  
}  

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> f[i];
		circle[i] = 0;
	}
	
	for(int k=1;k<=n;k++)
	{
		clea();
		circle[k] = dfs(f[k],0);
	}
	lcm = circle[1];
	for(int i=2; i<=n; i++)
	{
        lcm = lcm / gcd(lcm,circle[i]) * circle[i];
    }
    long long int temp = maxv/lcm;
    if(maxv % lcm || maxv == 0 || (maxv && lcm==1) || maxv==lcm || (maxv!=lcm && maxv%lcm==0))
		temp ++;
    long long int ans = temp * lcm;
	
	cout << ans << endl;
}
