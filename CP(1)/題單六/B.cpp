#include <iostream>
#include <stdio.h>

using namespace std;

int par[100010];
int opp[100010];

int findpar(int x)
{
	if(par[x]==x)
		return x;
	par[x] = findpar(par[x]);
	return par[x];
}

void setunion(int x,int y)
{
	int px = findpar(x);
	int py = findpar(y);
	
	if(px==py)
		return;
	par[px] = py;
}

int main()
{
	int task;
	scanf("%d",&task);
	while(task--)
	{
		for(int i=0;i<100010;i++)
		{
			par[i] = i;
			opp[i] = 0;
		}
		int n,m;
		scanf("%d %d",&n,&m);
		while(m--)
		{
			char c;
			int a,b;
			scanf("\n%c %d %d",&c,&a,&b);
			
			if(c=='D')
			{
				if(opp[a]==0)
					opp[a] = b;
				else
					setunion(opp[a],b);
				if(opp[b]==0)
					opp[b] = a;
				else
					setunion(opp[b],a);
			}
			else
			{
				bool finish = false;
				int pa = findpar(a);
				int pb = findpar(b);
				if (pa != pb)
				{
					if ((opp[a] != 0 && findpar(opp[a]) == pb) || (opp[b] != 0 && findpar(opp[b]) == pa))
						printf("In different gangs.\n");
					else
						printf("Not sure yet.\n");
				}
				else
					printf("In the same gang.\n");
			}
		}
	}
}
