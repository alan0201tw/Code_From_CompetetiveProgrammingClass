#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;long long int m;
	while(cin >> n >> m)
	{
		int array[n];
		long long left,right;
		
		left = 0;right = n-1;
		
		long long int com=1;
		
		for(int i=1;i<=n;i++)
		{
			if((com << (n-i-1)) >= m)
				array[left++] = i;
			else
			{
				array[right--] = i;
				m -= (com << (n-i-1));
			}
		}
		for(int k=0;k<n;k++) {
			if(k) cout << ' ' ;
			cout << array[k] ;
		}
			
		cout << endl;
		
	}
	
	
	
}
