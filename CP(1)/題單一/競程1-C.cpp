#include <iostream>

using namespace std;

int main()
{
	int tasknum;
	cin >> tasknum;
	while(tasknum--)
	{
		int chess[21][21];
		int win = 0;
		
		for(int k=0;k<21;k++)
			{
			chess[0][k] = 0;
			chess[k][0] = 0;
			chess[20][k] = 0;
			chess[k][20] = 0;
			}
		
		for(int i=1;i<=19;i++)
			for(int j=1;j<=19;j++)
				cin >> chess[i][j]; //(0,0) (0,1) (0,2)...
		
		for(int i=1;i<=19;i++)
			for(int j=1;j<=19;j++)
			{
				if(chess[i][j] == 1 && chess[i+1][j] == 1 && chess[i+2][j] == 1 && chess[i+3][j] == 1 && chess[i+4][j] == 1 && chess[i-1][j] != 1 && chess[i+5][j] != 1)
				{
					cout << 1 << endl << i << " " << j;
					win = 1;
					break;
				}
				else if(chess[i][j] == 1 && chess[i][j+1] == 1 && chess[i][j+2] == 1 && chess[i][j+3] == 1 && chess[i][j+4] == 1 && chess[i][j-1] != 1 && chess[i][j+5] != 1)
				{
					cout << 1 << endl << i << " " << j;
					win = 1;
					break;
				}
				else if(i >= 5 && chess[i][j] == 1 && chess[i-1][j+1] == 1 && chess[i-2][j+2] == 1 && chess[i-3][j+3] == 1 && chess[i-4][j+4] == 1 && chess[i+1][j-1] != 1&& chess[i-5][j+5] != 1)
				{
					cout << 1 << endl << i << " " << j;
					win = 1;
					break;
				}
				else if(chess[i][j] == 1 && chess[i+1][j+1] == 1 && chess[i+2][j+2] == 1 && chess[i+3][j+3] == 1 && chess[i+4][j+4] == 1 && chess[i-1][j-1] != 1 && chess[i+5][j+5] != 1)
				{
					cout << 1 << endl << i << " " << j;
					win = 1;
					break;
				}
				
				else if(chess[i][j] == 2 && chess[i+1][j] == 2 && chess[i+2][j] == 2 && chess[i+3][j] == 2 && chess[i+4][j] == 2 && chess[i-1][j] != 2 && chess[i+5][j] != 2)
				{
					cout << 2 << endl << i << " " << j;
					win = 1;
					break;
				}
				else if(chess[i][j] == 2 && chess[i][j+1] == 2 && chess[i][j+2] == 2 && chess[i][j+3] == 2 && chess[i][j+4] == 2 && chess[i][j-1] != 2&& chess[i][j+5] != 2)
				{
					cout << 2 << endl << i << " " << j;
					win = 1;
					break;
				}
				else if(i >= 5 && chess[i][j] == 2 && chess[i-1][j+1] == 2 && chess[i-2][j+2] == 2 && chess[i-3][j+3] == 2 && chess[i-4][j+4] == 2 && chess[i+1][j-1] != 2&& chess[i-5][j+5] != 2)
				{
					cout << 2 << endl << i << " " << j;
					win = 1;
					break;
				}
				else if(chess[i][j] == 2 && chess[i+1][j+1] == 2 && chess[i+2][j+2] == 2 && chess[i+3][j+3] == 2 && chess[i+4][j+4] == 2 && chess[i-1][j-1] != 2&& chess[i+5][j+5] != 2)
				{
					cout << 2 << endl << i << " " << j;
					win = 1;
					break;
				}
			}
			if(win == 0)
				cout << 0;
			if(tasknum)
				cout << endl;
	}
	
}

