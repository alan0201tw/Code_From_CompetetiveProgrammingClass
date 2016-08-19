#include <iostream>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

struct state
{
	string s;
	int steps;
};

string strswap(string s,int a,int b,int c)
{
	char cc = s[a];
	s[a] = s[b];
	s[b] = s[c];
	s[c] = cc;
	return s;
}

map <string,string> mss;

int main()
{
	queue<state> q;
	q.push(state{"123456789",0});
	string tem;
	
	while(!q.empty())
	{
		state now = q.front();
		q.pop();
		
		tem = strswap(now.s,0,1,2);
        if ( mss[tem] == "" )
		{
            mss[tem] = "H1"+mss[now.s];
            q.push(state{tem,now.steps+1});
        }
        tem = strswap(now.s,3,4,5);
        if ( mss[tem] == "" )
		{
            mss[tem] = "H2"+mss[now.s];
            q.push(state{tem,now.steps+1});
        }
		tem = strswap(now.s,6,7,8);
        if ( mss[tem] == "" )
		{
            mss[tem] = "H3"+mss[now.s];
            q.push(state{tem,now.steps+1});
        }
		tem = strswap(now.s,6,3,0);
        if ( mss[tem] == "" )
		{
            mss[tem] = "V1"+mss[now.s];
            q.push(state{tem,now.steps+1});
        }
		tem = strswap(now.s,7,4,1);
        if ( mss[tem] == "" )
		{
            mss[tem] = "V2"+mss[now.s];
            q.push(state{tem,now.steps+1});
        }
		tem = strswap(now.s,8,5,2);
        if ( mss[tem] == "" )
		{
            mss[tem] = "V3"+mss[now.s];
            q.push(state{tem,now.steps+1});
        }
	}
	
	//above is done before input
	
	int n;
	char c;
	string s;
	while(cin >> c && c!='0')
	{
		s=c;
		for(int i=0;i<8;i++)
		{
			cin >> c;
			s += c;
		}
	
		if(s == "123456789")
			cout << "0" << endl;
		else if (mss[s] == "")
			cout << "Not solvable" << endl;
    	else
    		cout << mss[s].size()/2 << " " << mss[s] << endl;
	}
}
