#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

double price (int p,int a,int b,int c,int d,int k)
{
	//cout << p * (sin(a * k + b) + cos(c * k + d) + 2) << endl;
	return p * (sin(a * k + b) + cos(c * k + d) + 2);
}

int main()
{
	long long int p,a,b,c,d,k;
	
	while(cin >> p >> a >> b >> c >> d >> k)
	{
		long double biggest = price(p,a,b,c,d,1);
		long double out = 0;
		
		for(int i = 1;i<=k;i++)
		{
			if(biggest - price(p,a,b,c,d,i) > out)
				out = biggest - price(p,a,b,c,d,i);
			if(price(p,a,b,c,d,i) > biggest)
				biggest = price(p,a,b,c,d,i);
			
		}
		
					
		cout << fixed << setprecision(6) << out << endl;
		
	}
	
}
