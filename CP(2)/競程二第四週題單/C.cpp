#include <iostream>

using namespace std;

/*long long int quick_me(long long int x,long long int y)
{
	if(y == 0)
		return 1;
	if(y == 1)
		return x;
	if(y % 2 == 0)
		return quick_me(x , y/2) * quick_me(x , y/2);
	if(y % 2 == 1)
		return quick_me(x , y/2) * quick_me(x , y/2) * x;
}*/

int main()
{
	string i;
	cin >> i;
	int siz = i.size();
	int k = (i[siz-1] - '0' + (i[siz-2] - '0') * 10);
	
	if(k%4 == 0)
		cout << 4 << endl;
	else
		cout << 0 << endl;
		
}
