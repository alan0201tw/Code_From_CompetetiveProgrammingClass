#include <iostream>

using namespace std;

int bit[100010] = {};
int ori[100010];
int n,k;

int lower_bit(int x)
{
	return x & (-x);
}

void update(int x,int v)
{
	for(;x <= n; x += lower_bit(x))
		bit[x] += v;
}

int sum(int x)
{
	int ans=0;
	for(; x ; x -= lower_bit(x))
		ans += bit[x];
	return ans;
}

void init()
{
	for(int i=0;i<100010;i++)
	{
		ori[i] = 0;
		bit[i] = 0;
	}
}

int main()
{
	while(cin >> n >> k)
	{
		init();
		for(int i=1;i<=n;i++)
		{
			int in;
			cin >> in;
			
			if(in > 0)
				ori[i] = 0;
			else if(in < 0)
				ori[i] = 1;
			else if(in == 0)
				ori[i] = 1e6;
			
			update(i,ori[i]);
		}
		
		for(int j=0;j<k;j++)
		{
			char cmd;
			cin >> cmd;
			
			if(cmd == 'C')
			{
				int x,in;
				cin >> x >> in;
				
				if(in > 0)
					in = 0;
				else if(in < 0)
					in = 1;
				else if(in == 0)
					in = 1e6;
				
				update(x,in-ori[x]);
				ori[x] = in;
			}
			else if(cmd == 'P')
			{
				int a,b;
				cin >> a >> b;
				int tmp = sum(b) - sum(a-1);
				if(tmp >= 1e6)
					cout << 0;
				else if(tmp % 2 == 0)
					cout << '+';
				else
					cout << '-';
			}
		}
		
		cout << endl;
		
	}
}
