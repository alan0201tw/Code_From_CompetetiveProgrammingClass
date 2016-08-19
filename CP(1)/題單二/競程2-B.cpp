#include <iostream>
#include <queue>
using namespace std;

queue <int> arr[1005];
queue <int> tq;
int table [1000005];

int main()
{
	int t;int scen=1;
	while(cin >> t && t)
	{
		cout << "Scenario #" << scen++ << endl;
		
		int n;

		for(int team=0;team<t;team++)
		{
			cin >> n;
			int get;
			while(n--)
			{
				cin >> get;
				table[get] = team;
			}
		}
		
		
		string com;
		while(cin >> com && com != "STOP")
		{
			if(com == "ENQUEUE")
			{
				int in;
				cin >> in;
				
				if(arr[table[in]].empty())
					tq.push(table[in]);
				
				arr[table[in]].push(in);
				
			}
			else //DeQueue
			{
				int n=tq.front();
				int out = arr[n].front();
				
				arr[n].pop();
				
				cout << out << endl;
				
				if(arr[n].empty())
					tq.pop();
				
			}

		}
		
		while(!tq.empty()) tq.pop();
		
		for(int ii=0;ii<t;ii++)
			while(!arr[ii].empty())
				arr[ii].pop();
		
		cout << endl;
	}
	
}
