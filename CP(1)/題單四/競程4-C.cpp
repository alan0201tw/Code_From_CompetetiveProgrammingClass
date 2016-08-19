#include <iostream>

using namespace std;

int main()
{
	int T;int kase = 1;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		
		char a[n];
		for(int i=0;i<n;i++)
			cin >> a[i];
			
		int dotc = 0;
		int sum = 0;
			
		for(int k=0;k<n;k++)
		{
			if(a[k] == '.')
				dotc++;
				
			else if(a[k] == '#')
			{
				if(a[k+1] == '#')
				{
					if(dotc % 3)
						sum += dotc/3 + 1;
					else
						sum += dotc/3;
						
					dotc = 0;
				}
				else if(a[k+1] == '.')
				{
					if(dotc % 3 == 1)
					{
						sum += dotc/3 + 1;
						dotc = -1;
					}
					else if(dotc % 3 == 2)
					{
						sum += dotc/3 + 1;
						dotc = 0;
					}
					else
					{
						sum += dotc/3;
						dotc = 0;
					}
				}
			}
		}
		if(dotc % 3)
			sum += dotc/3 + 1;
		else
			sum += dotc/3;
		
		
		cout << "Case " << kase++ <<": " << sum << endl;
		
	}
	
}
