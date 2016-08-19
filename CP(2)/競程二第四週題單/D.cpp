#include <iostream>

using namespace std;

int x,y,temp,ans;
int GCD(int p,int q){
    if(!q){
        x = 1;
        y = 0;
        return p;
    }else{
        ans = GCD(q,p%q);
        temp = x;
        x = y;
        y = temp - (p/q)*y;
        return ans;
    }
}

int main()
{
	int A,B;
	while(cin >> A >> B)
	{
		cout << x << " " << y << " " << GCD(A,B) << endl;
	}
}
