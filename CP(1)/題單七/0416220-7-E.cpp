#include <iostream>
#include <stdio.h>

using namespace std;

int ori[110][110],pro[110][110];
int n;

int main()
{
	while(cin >> n && n)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				ori[i][j] = pro[i][j] = 1e9;
		
		for(int i=0;i<n;i++)
		{
			int st;
			int inter;
			char c;
			scanf("%d",&st);
			do
			{
				scanf("%d%c",&inter,&c)==2;
				ori[st][inter] = 1;
			}while(c!='\n');
		}
		for(int i=0;i<n;i++)
		{
			int st;
			int inter;
			char c;
			scanf("%d",&st);
			do
			{
				scanf("%d%c",&inter,&c)==2;
				pro[st][inter] = 1;
			}while(c!='\n');
		}
		
		int a,b;
		cin >> a >> b;
		
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
			{
				if(ori[i][k]!=1e9)
				for(int j=1;j<=n;j++)
					ori[i][j] = min(ori[i][j] , ori[i][k] + ori[k][j]);
						
			}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
			{
				if(pro[i][k]!=1e9)
				for(int j=1;j<=n;j++)
					pro[i][j] = min(pro[i][j] , pro[i][k] + pro[k][j]);
						
			}
		bool ans = true;
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j && pro[i][j] > a*ori[i][j]+b)
					ans = false;
		
		if(ans)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}
