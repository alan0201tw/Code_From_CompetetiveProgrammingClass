#include <iostream>
#include <string>

using namespace std;

string w,t;
int F[10005];

void get_F()
{
	F[0] = -1;
	for(int i=1;i<w.size();i++)
	{
		if(w[i] == w[F[i-1] + 1])
			F[i] = F[i-1] + 1;
		else
			F[i] = -1;
	}
}

int kmp()
{
	int ans = 0;
	int k = -1;
	for(int i=0;i<t.size();i++)
	{
		while(k >= 0 && t[i] != w[k+1])
			k = F[k];
		if(t[i] == w[k+1])
			k++;
		if(k == w.size()-1)
		{
			ans++;
			k = F[k];
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	while(n--)
	{
		cin >> w >> t;
		get_F();
		cout << kmp() << endl;
	}
}
