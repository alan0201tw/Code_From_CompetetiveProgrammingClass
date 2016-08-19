#include <iostream>

using namespace std;

struct bee
{
	long long int f,m;
};

bee find(long long int f,long long int m)
{
	long long int mm = f+m;
	long long int ff = m+1;
	
	bee b;
	b.f = ff;
	b.m = mm;
	
	return b;
}


int main()
{
	long long int n;
	long long int F=1,M=0;
	bee b;
	
	while(cin >> n && n != -1)
	{
		while(n--)
		{
			b = find(F,M);
			F = b.f;
			M = b.m;
		}
		
		cout << M << " " << F+M << endl;
		F=1;M=0; 
	}
	
}
