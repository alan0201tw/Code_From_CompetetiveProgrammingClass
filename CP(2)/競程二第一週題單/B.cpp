#include <iostream>
#include <queue>

using namespace std;

int n;
int l,r;
queue <int> a,b;

int main()
{
	cin >> n;
	cin >> l;
	for(int i=0;i<l;i++)
	{
		int tem;
		cin >> tem;
		a.push(tem);
	}
	cin >> r;
	for(int i=0;i<r;i++)
	{
		int tem;
		cin >> tem;
		b.push(tem);
	}
	
	long long int count = 1;
	
	while(count++)
	{
		if(a.front() > b.front())
		{
			a.push(b.front());
			a.push(a.front());
			a.pop();
			b.pop();
		}
		else
		{
			b.push(a.front());
			b.push(b.front());
			b.pop();
			a.pop();
		}
		
		if(a.empty())
		{
			cout << count-1 << " 2\n";
			return 0;
		}
		else if(b.empty())
		{
			cout << count-1 << " 1\n"; 
			return 0;
		}
		if(count >= 1e5)
		{
			cout << -1 << endl;
			return 0 ;
		}
	}
}
