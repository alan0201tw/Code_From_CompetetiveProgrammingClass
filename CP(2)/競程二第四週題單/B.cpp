#include <iostream>

using namespace std;

long long int ans[51] = {};

void get_ans()
{
	ans[1] = 1;
	ans[2] = 5;
	ans[3] = 11;
	
	for(int i=4;i<=50;i++)
	{
		ans[i] = ans[i-1] + 4*ans[i-2] + 2*ans[i-3];
	}
	
}

int main()
{
	get_ans();
	
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		cout << ans[n] << endl;
	}
}
