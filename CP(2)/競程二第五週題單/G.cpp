#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    
    int x=a+b+c;
    int ans=x*x-a*a-c*c-e*e;
    
    cout<<ans<<endl;
    
}
