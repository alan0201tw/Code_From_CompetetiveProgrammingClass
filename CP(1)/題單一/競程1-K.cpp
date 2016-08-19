#include <iostream>

using namespace std;

char bulb[10][10];
int turn[10][10] = {0};

int solve ()
{
	int ans = 0;
	
	for(int k=0;k<10;k++)
		for(int g=0;g<10;g++)
		{
			if(bulb[k][g] == 'O')
				break;
			else if (k==9 && g==9)
				return ans;
		}
	
	for(int x=0;x<10;x++)
		for(int y=0;y<10;y++)
		{
			if(turn[x][y] == 0)
			{
				
				
				
				
			}
			
			
			
			
		}
	
	
	
}



int main()
{
	string name;
	
	while(cin >> name)
	{
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				cin >> bulb[i][j];
				
		
		
		
		
	}
	
	
	
	
}
