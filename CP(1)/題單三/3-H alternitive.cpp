#include <iostream>

using namespace std;

int leg[100005];
int energy[100005];

int stable (int ene)
{
	
	
	
	
	
}

int main()
{
	int n;
	int energysum=0;
	while(cin >> n)
	{
		for(int i=0;i<n;i++)
			cin >> leg[i];
		for(int j=0;j<n;j++)
		{
			cin >> energy[j];
			energysum += energy[j];
		}
		
		int l=0,r=energysum;
		
		while(l<r)
		{
			int mid = (l+r)/2;
			
			if(stable(mid)==1)
				r=mid;
			else
				l=mid+1;
		}
		
		cout << r << endl;
	}
}
