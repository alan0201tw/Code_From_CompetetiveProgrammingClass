#include <iostream>

using namespace std;

struct point
{
	double x,y;
};

int main()
{
	int n;
	while(cin >> n && n)
	{
		point p[n];
		
		for(int i=0;i<n;i++)
			cin >> p[i].x >> p[i].y;
		
		point q;
		cin >> q.x >> q.y;
		int cnt = 0;
		
		for(int i = 0,j = n-1; i < n; j = i++)
		{
			if(p[i].y > q.y != p[j].y > q.y && q.x < (p[j].x-p[i].x)*(q.y-p[i].y)/(p[j].y-p[i].y)+p[i].x)
				cnt++;
        }
		if(cnt % 2 == 1)
			cout << 'T' << endl;
		else
			cout << 'F' << endl;
	}
}
