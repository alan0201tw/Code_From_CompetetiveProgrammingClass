#include <iostream>
#include <string>

using namespace std;

string goal;
int n;

bool dfs(int d,int maxd,string now)
{
    if(d==maxd)
        return now==goal;

    int h=0;
    for(int i=0;i<n-1;++i)
        if(now[i+1]-now[i]!=1)
            h++;
    if(3*d+h>3*maxd)
        return false;

    for(int i=0;i<n;++i){
        for(int j=i;j<n;++j){
            for(int k=0;k<i;++k){
                string p=now.substr(0,k);
                string q=now.substr(i,j-i+1);
                string r=now.substr(k,i-k);
                string t=now.substr(j+1,n-j);
                if(dfs(d+1,maxd,p+q+r+t))
                    return true;
            }
        }
    }
    return false;
}

int main()
{
	int cas=0;
	while(cin >> n && n)
	{
		goal = "";
		for(int i=1;i<=n;i++)
			goal += char('0'+i);
		string st = "";
		int a;
		for(int i=0;i<n;++i)
		{
            cin >> a;
            st += char('0'+a);
        }
        for(int maxd=0;;++maxd)
		{
            if(dfs(0,maxd,st))
			{
                cout << "Case " << ++cas << ": " << maxd << endl;
                break;
            }
        }
		
	}
	
}
