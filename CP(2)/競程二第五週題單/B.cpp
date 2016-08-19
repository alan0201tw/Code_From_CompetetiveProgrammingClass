#include <iostream>
#include <cmath>

using namespace std;

struct point
{
	char label;
	int x,y;
};

double area(point a,point b,point c)
{
	return (double)(abs(0.5 * ((c.y - a.y) * (b.x - a.x) - (b.y - a.y) * (c.x - a.x))));
}

point p[16];

int main()
{
	int n;
	while(cin >> n && n)
	{
	for(int i=0;i<n;i++)
		cin >> p[i].label >> p[i].x >> p[i].y;
	
	int max_area = 0;
	char max_3_p[3] = {};
	
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
			{
				bool valid = true;
				
				if(area(p[i],p[j],p[k]) > max_area)
				{
					for(int other = 0;other < n;other++)
					{
						if(other == i || other == j || other == k)
							continue;
						else
						{
							double tmp = area(p[i],p[j],p[other]) + area(p[i],p[k],p[other]) + area(p[k],p[j],p[other]);
							if(area(p[i],p[j],p[k]) == tmp)
							{
								valid = false;
								break;
							}
						}
					}
					
					if(valid)
					{
						max_area = area(p[i],p[j],p[k]);
						max_3_p[0] = i + 'A';
						max_3_p[1] = j + 'A';
						max_3_p[2] = k + 'A';
					}
				}
				
			}
	
	cout << max_3_p[0] << max_3_p[1] << max_3_p[2] << endl;
	}
}
