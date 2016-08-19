#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

stack <int> ans;
stack <int> width;
stack <int> index;

int main()
{
	int n;
	while(cin >> n)
	{
		int bear[n+1];
		int l[n],r[n];
		for(int i=0;i<n;i++)
			cin >> bear[i];
		bear[n] = 0 ;
		for(int i=0;i<=n;i++)
		{
			int w=0;
			while(!ans.empty() && bear[i] < ans.top())
			{
				r[index.top()] = w;
				w+=width.top()+1;
				ans.pop();
				width.pop();
				index.pop();
			}
			index.push(i);
			width.push(w);
			ans.push(bear[i]);
		}
		reverse(bear,bear+n);
		for(int i=0;i<=n;i++)
		{
			int w=0;
			while(!ans.empty() && bear[i] < ans.top())
			{
				l[index.top()] = w;
				w+=width.top()+1;
				ans.pop();
				width.pop();
				index.pop();
			}
			index.push(n-i-1);
			width.push(w);
			ans.push(bear[i]);
		}
		
		reverse(bear,bear+n);
		
		int ans[n] = {0};
		
		for(int i=0;i<n;i++)
		{
			ans[l[i]+r[i]] = max(bear[i],ans[l[i]+r[i]]);
		}

		int maxx = 0;
		
		/*for(int i=0;i<n;i++)
			cout << l[i] << " ";
			
		cout << endl;
		
		for(int i=0;i<n;i++)
			cout << r[i] << " ";
			
		cout << endl;*/
		
		for(int i=n-1;i>=0;i--)
		{
			maxx = max(maxx,ans[i]);
			ans[i] = maxx;
		}
		for(int i=0;i<n;i++)
			if(i)
				cout << " " << ans[i] ;
			else
				cout << ans[i];
				
		cout << endl;
		
		
	}
	
}
