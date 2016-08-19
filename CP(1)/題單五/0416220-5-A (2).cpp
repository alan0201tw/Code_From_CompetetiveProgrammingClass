#include <iostream>

using namespace std;

int arr[2010] = {0};
int an;

void dfs(int ind)
{
	an++;
	if(arr[ind] == -1)
		return;
	dfs(arr[ind]);
}

int main()
{
	int n;
	while(cin >> n)
	{
		an=0;
		int ans=0;
		for(int i=1;i<=n;i++)
			cin >> arr[i];
		
		for(int k=1;k<=n;k++)
		{
			dfs(k);
			ans = max(ans,an);
			an=0;
		}
		cout << ans << endl;
		
	}
	
}
