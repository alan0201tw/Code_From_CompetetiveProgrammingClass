#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct st
{
	int leg;
	int energy;
};

st yee[100005];
int sum[100005] = {};
int eee[201] = {};
int n;

int cal (int l,int i)
{
	int cost = 0;
	
	cost += sum[n] - sum[i];
	int	fuck = i-(l*2-1) ;
	//printf("%d %d %d\n",i,l,fuck) ;
	
	if(fuck>0)
		for(int op=1;op<=200;op++)
		{
			if(eee[op] >= fuck)
			{
				cost += fuck * op;
				fuck = 0;
			}
			else
			{
				cost += eee[op] * op;
				fuck -= eee[op];
			}
			if(fuck==0)
				break;
		}
	
	return cost;
}

bool sss (st aa , st bb)
{
	if(aa.leg<bb.leg)
		return true;
	
	return false;
}

int main()
{
	while(cin >> n)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&yee[i].leg);
		for(int j=1;j<=n;j++)
			scanf("%d",&yee[j].energy);
		
		sort(yee+1,yee+n+1,sss);
	
		for(int k=1;k<=n;k++)
			sum[k] = sum[k-1] + yee[k].energy;
			
		int mn = 2e9;
			
		for(int i=1;i<=n;)
		{
			int k;
			for(k=i+1;k<=n;k++)
				if(yee[k].leg != yee[i].leg)
					break;
			
			int cosst = cal(k-i,k-1);
			
			for(;i<k;i++)
				eee[yee[i].energy]++;
			
			mn = min(mn,cosst);
		}
		
		cout << mn << endl;
		
	}
}
