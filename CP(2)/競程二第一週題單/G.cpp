#include <iostream>

using namespace std;

int n,m,w;

struct state
{
	int ball[4][4];
	int hole[4][4];
	
	state()
	{
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
			{
				ball[i][j] = 0;
				hole[i][j] = 0;
			}
	}
};

int main()
{
	while(cin >> n >> m >> w && n && m && w)
	{
		
		
	}
	
}
