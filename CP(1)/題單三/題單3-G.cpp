#include <iostream>

using namespace std;

int box[100005];
int boxx[100005];
long long int sum=0;

int solve (int n,int m,long long int sec)
{		
	long long int i=0;
	long long int step;
	
	while(m--)
	{
		step = sec - (i + 1);
		
		while(step)
		{
			if(i>n-1)
				break;
			
			if(box[i] >= step)
			{
				box[i] -= step;
				step = 0;
			}
			else //if (box[i+move] < step)
			{
				step -= box[i];
				box[i] = 0;
				i++;
				step--;
			}
		}
	}
	
	if(box[n-1]==0)
		return 1;
	else
		return 0;
}

int main()
{
	int n,m,key;
	while(cin >> n >> m)
	{
		for(int i=0;i<n;i++)
		{
			cin >> box[i];
			sum += box[i];
			boxx[i] = box[i];
			
			if(box[i])
				key = i+1;
		}
		n = key;
		
		long long int l=0,r=sum+n+100;
		long long int sec;
		
		while(r>l)
		{
			for(int j=0;j<n;j++)
				box[j] = boxx[j];
				
			sec = (l+r)/2;
			
			if(solve(n,m,sec) == 1)
			{
				r = sec;
			}
			else
			{
				l = sec+1;
			}
			
		}
		cout << r << endl;
		
		sum=0;
	}
	
}
