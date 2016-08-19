#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int task;
	cin >> task;
	while(task--)
	{
		int N,M;
		cin >> N >> M;
		
		int belong[N+1];
		int sum[N+1];
		
		for(int i=1;i<=N;i++)
		{
			belong[i]=i;
			sum[i]=0;
		}
		while(M--)
		{
			int a,b;
			cin >> a >> b;
			
			int temp = belong[a];
			
			for(int k=1;k<=N;k++)
				if(belong[k]==temp)
					belong[k] = belong[b];
		}
		
		int maxsum=0;
		
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				if(belong[i]==belong[j])
					sum[belong[i]]++;
		
		for(int i=1;i<=N;i++)
			maxsum = max(maxsum,sum[i]);
			
		cout << sqrt(maxsum) << endl;
	}
}
