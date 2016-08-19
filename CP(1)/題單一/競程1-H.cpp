#include <iostream>

using namespace std;

void solve(int x,int y,int l);

int n;
int l;
int su[9][9] = {0};
int s=0,sx,sy,ex,ey;
int flag ;		//

int main()
{
	int first = 1;
	while(cin >> n)
	{
		if(first == 0)
			cout << endl;
		
		first = 0;
		
		l = n*n;
		if(n==1)
			{
				int qww;
				cin >> qww;
				if(qww)
					cout << qww;
				else
					cout << 1 << endl;
			}
		else
		{
		for(int i=0;i<l;i++)
			for(int j=0;j<l;j++)
			{
				cin >> su[i][j];
				
				if(su[i][j] == 0)
				{
					if(s==0)
					{
						sx=i;sy=j;
						s=1;
					}
					ex=i;
					ey=j;
				}
				
			}
		flag = 1 ;						//
		
		solve(sx,sy,l);
		
		if(flag == 1)
			cout << "NO SOLUTION\n";
		
		}
		
		s=0;//initialize
	}
	
	
}

void solve(int x,int y,int l)
{
	if(su[ex][ey])
	{
		for(int a=0;a<l;a++)
			for(int b=0;b<l;b++)
			{
				if(b < l-1)
					cout << su[a][b] << " ";
				if(b == l-1)
					cout << su[a][b] << endl;	//
			}
		
		flag=0 ;			//
		
		return;
	}
	
	if(su[x][y] == 0)		//
		for(int i=1;i<=l;i++) // insert i
		{
			int ch = 0;
		
			for(int tem1 = 0;tem1<l;tem1++)
				if(i == su[x][tem1])
					ch = 1;
			
			for(int tem2 = 0;tem2<l;tem2++)
				if(i == su[tem2][y])
					ch = 1;
					
			for(int tem3 = (x)/n*n ;tem3 < ((x)/n*n)+n; tem3++)		//
				for(int tem4 = (y)/n*n ;tem4 < ((y)/n*n)+n; tem4++)	//
					if(i == su[tem3][tem4])
						ch = 1;
			
			if(ch == 0)
			{
				su[x][y] = i;
				
				if(y == l-1)
					solve(x+1,0,l);
				else
					solve(x,y+1,l);
				if(!flag) return ;			//
				su[x][y] = 0;
			}
		}	
	else
		{
		if(y == l-1)
			solve(x+1,0,l);
		else
			solve(x,y+1,l);
		}
}
