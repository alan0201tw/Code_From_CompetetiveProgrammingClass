#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	int n,w;
	
	scanf("%d%d",&n,&w);
	
		int a[2*n];
		for(int i=0;i<2*n;i++)
			scanf("%d",&a[i]);
		
		sort(a,a+2*n);
		
		float gb = (float)a[0];
		float bb = (float)a[n]/2.0;
		
		if(gb >= bb)
		{
			bb = bb*3*n;
			if(bb > w)
				printf("%f\n",(float)w);
			else
				printf("%f\n",bb);
		}
		else
		{
			gb = gb*3*n;
			if(gb > w)
				printf("%f\n",(float)w);
			else
				printf("%f\n",gb);
		}
	
}
