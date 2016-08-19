#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int a[n][n];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> a[i][j];

	int value[n];
	int valuecop[n];
	int ans = -2e9;
	
	for(int up = 0;up<n;up++)
	{
		for(int la=0;la<n;la++)
			value[la] = 0;
		
		for(int bot = up;bot<n;bot++)
		{
			for(int t=0;t<n;t++)
			{
				value[t] += a[bot][t];
				valuecop[t] = value[t];
			}
			for(int right=0;right<n;right++)
			{
				if(right>0)
					valuecop[right] = max(valuecop[right],valuecop[right-1] + valuecop[right]);
					
				ans = max(valuecop[right],ans);
			}
			
		}
	}
	cout << ans << endl;
	
	
}
