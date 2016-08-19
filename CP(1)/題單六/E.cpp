#include <iostream>
#include <stdio.h>
#include<cstdio>
#include<cstring>
using namespace std;

int a[100001];
bool visit[100001];

int main()
{
	memset(visit,false,sizeof(bool));
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	int kc=0;
	int ans=0;
	
	for(int i=0;i<n;i++)
	{
		if(!visit[a[i]])
		{
			visit[a[i]] = true;
			kc++;
		}
		if(kc==k)
		{
			for(int j=0;j<n;j++)
				visit[j] = 0;
			kc=0;
			ans++;
		}
	}
	printf("%d\n",ans+1);
}
