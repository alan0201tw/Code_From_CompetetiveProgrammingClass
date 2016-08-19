#include <iostream>
#include <stack>

using namespace std;

stack <int> in;

int main()
{
	int n;
	int check=1;
	while(cin >> n)
	{
		if(check == 0 && n == 0)
		{
			cout << endl;
			break;
		}
		else if(check == 0)
			cout << endl;
		
		int out[n];
		
		while(cin >> check)
		{
			if(check == 0)
				break;
			else
				out[0] = check;
		
		for(int i=1;i<n;i++)
			cin >> out[i];
			
		int r = 0;
		
		for(int k=1;k<=n;k++)
		{
			in.push(k);
			while(!in.empty() && in.top() == out[r])
			{
				r++;
				in.pop();
				
				if(r == n)
					break;
			}
			
		}
		if(r == n)
			cout << "Yes\n";
		else
			cout << "No\n";
		
		while(!in.empty())
			in.pop();
		}
	}
	
	
}
