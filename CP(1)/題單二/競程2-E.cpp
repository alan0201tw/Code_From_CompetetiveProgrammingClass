#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char pre[30] = {0} , in[30] = {0};
int siz;
int rnum = -1;

void solve (int s,int e)
{
	if(s>e)
		return;
	
	rnum++;
	
	for(int k=0;k<siz;k++)
		if(pre[rnum] == in[k])
		{
			solve(s,k-1);
			solve(k+1,e);
			
			cout << in[k];
			return;
		}
}

int main()
{	
	while(scanf("%s%s",pre,in) != EOF)
	{
		siz = strlen(pre);
		
		solve(0,siz-1);
		cout << endl;
		
		rnum = -1;
		memset(pre,0,siz);
		memset(in,0,siz);
	}
}
