#include <iostream>
#include <algorithm>

using namespace std;

string arr[10010];

bool check (string a, string b)
{
    if (b.size() < a.size())
		return false;
 
    for (int i = 0;i < a.size ();i++)
	{
        if ( a[i] != b[i] )
			return false;
    }
 
    return true;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		for(int i=0;i<n;i++)
			cin >> arr[i];
		sort(arr,arr+n);
		for(int i=0;i<n-1;i++)
		{
			if(check(arr[i],arr[i+1]))
			{
				cout << "NO" << endl;
				break;
			}
			else if(i==n-2)
			{
				cout << "YES" << endl;
				break;
			}
		}
	}
}
