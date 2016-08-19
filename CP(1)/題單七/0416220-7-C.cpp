#include <iostream>

using namespace std;

int d[1010];
int a[2010],b[2010],w[2010];
int n,m;

bool BF(int s)
{
	for(int i=0;i<n;i++)
		d[i] = 1e9;
	
	d[s] = 0;
	for(int k=0;k<n-1;k++)
		for(int p=0;p<m;p++)
		{
			if(d[a[p]] + w[p] < d[b[p]])
				d[b[p]] = d[a[p]] + w[p];
		}
	bool re = true;
	for(int p=0;p<m;p++)
	{
		if(d[a[p]] + w[p] < d[b[p]])
			re = false;
	}
	return re;
}

int main()
{
	int task;
	cin >> task;
	while(task--)
	{
		cin >> n >> m;
		
		for(int i=0;i<m;i++)
			cin >> a[i] >> b[i] >> w[i];
		
		if(BF(0) == false)
			cout << "possible\n";
		else
			cout << "not possible\n";
	}
	
}
