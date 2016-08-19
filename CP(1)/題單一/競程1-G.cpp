#include <iostream>
#include <string>

using namespace std;

int house[6][6];
string path;

void findway (int nowat);

int main()
{
	for(int i=1;i<6;i++)
		for(int j=1;j<6;j++)
			house[i][j] = 0;
	
	house[1][1] = 2;
	house[2][2] = 2;
	house[3][3] = 2;
	house[4][4] = 2;
	house[5][5] = 2;
	
	house[1][4] = 2;
	house[2][4] = 2;
	house[4][1] = 2;
	house[4][2] = 2;
	path.push_back('1');
	
	findway(1);
	
	return 0;
}

void findway (int nowat)
{
	if(path.size() == 9)
	{
		for(int g=0;g<9;g++)
			cout << path[g];
		
		cout << endl;
		
		return;
	}
	
	for(int t=1;t<6;t++)
	{
		if(house[nowat][t] == 0)
		{
			path.push_back(t+48);
			house[nowat][t] = 1;
			house[t][nowat] = 1;
			
			findway (t);
			
			if(path.size() > 0)
			path.erase(path.size()-1, 1);
			house[nowat][t] = 0;
			house[t][nowat] = 0;
		}
	}
	
}


