#include <iostream>
#include <string.h>

using namespace std;

char in[110010];
char s[220020];
int p[220020];
int n;

void pre()
{
	s[0] = '$';
	s[1] = '#';
	int len = strlen(in);
	
	for(int i=0;i<len;i++)
	{
		s[i*2+2] = in[i];
		s[i*2+3] = '#';
	}
	n = len*2+2;
	s[n] = 0;
}

void pk()
{
	int rs=0;
	int id=0;
	
	for(int i=1;i<n;i++)
	{
		if(rs > i)
			p[i] = min(p[id*2-i],rs-i);
		else
			p[i] = 1;
		
		while(s[i-p[i]] == s[i+p[i]])
			p[i]++;
			
		if(p[i] + i > rs)
		{
			rs = p[i]+i;
			id = i;
		}
	}
}

int main()
{
	while(scanf("%s",in) != EOF)
	{
		pre();
		pk();
		int ans = 0;
		
		for(int i=2;i<n;i++)
			if(p[i] > ans)
				ans = p[i];
		
		cout << ans-1 << endl;
	}
}
