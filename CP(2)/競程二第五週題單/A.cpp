#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
using namespace std;

struct point
{
	int x,y;
};

point vec[2010];

double line(point a,point b,point c)
{
	if((a.x - b.x) * (c.y - b.y) != (c.x - b.x) * (a.y - b.y))
		return true;
	return false;
}

int main()
{
	int n;
	cin >> n;

	for(int i=0;i<n;i++)
	{
		point in;
		scanf("%d%d",&in.x,&in.y);
		
		vec[i] = in;
	}
	
	int ans = 0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(line(vec[i],vec[j],vec[k]))
					ans++;
			}
		}
	}
	
	cout << ans << endl;
}
