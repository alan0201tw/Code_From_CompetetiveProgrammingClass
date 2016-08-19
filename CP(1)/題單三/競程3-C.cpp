#include <iostream>
#include <algorithm>

using namespace std;

struct pegg{
	int pos;
	int num;
	bool operator < (const pegg x) const {
		return pos < x.pos ;
	}
};


int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		pegg peg[n];
		int numofpeg[n];
		for(int i=0;i<n;i++)
		{
			cin >> peg[i].pos;
			peg[i].num = i;
		}
			
		sort(peg,peg+n);
		
		for(int fuck=0;fuck<n;fuck++)
			numofpeg[peg[fuck].num] = fuck;
		
		while(m--)
		{
			int startpeg,length;
			cin >> startpeg >> length;
			
			startpeg = numofpeg[startpeg-1];
			
			while(1)
			{
				int j = lower_bound(peg+startpeg,peg+n,pegg{peg[startpeg].pos+length,0})-peg;
				
				if((j==n || peg[j].pos > peg[startpeg].pos+length) && j>0)
					j--;
				
				int lleft = length - (peg[j].pos - peg[startpeg].pos);
				
				int jj = lower_bound(peg,peg+j,pegg{peg[j].pos - lleft,0})-peg;
				
				if(jj == n)
					jj--;
					
				//cout << j << " " << jj << endl;
				if(j==startpeg && jj==startpeg)
					break;
				else if(j!=startpeg && jj!=startpeg)
				{
					length -= (peg[j].pos - peg[startpeg].pos) + (peg[j].pos - peg[jj].pos);
					startpeg = jj;
				}
				else if(j==startpeg && jj!=startpeg)
				{
					length -= (peg[startpeg].pos - peg[jj].pos);
					startpeg = jj;
				}
				else if(j!=startpeg && jj==startpeg)
				{
					int x = length/(peg[j].pos - peg[startpeg].pos);
					length %= (peg[j].pos - peg[startpeg].pos);
					
					if(x%2)
						startpeg = j;
				}
				else if(j!=startpeg && jj == j)
				{
					length -= peg[j].pos - peg[startpeg].pos;
					
					startpeg = j;
				}
				
			}
			
			cout << peg[startpeg].num+1 << endl;
			
		}
		
	}
}
