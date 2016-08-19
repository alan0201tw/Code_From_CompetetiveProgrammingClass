#include <iostream>

using namespace std;

bool alpha[26][26];
int ref[26];
string in[105];
char ans[26] ;
bool noans = false;
int siz=0;

void topo ()
{
	for(int i=0;i<26;i++)
		ref[i] = 0;
	
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			if(alpha[i][j])
				ref[j]++;
	
	for(int i=0;i<26;i++)
	{
		int s=0;
		while(s<26 && ref[s]!=0)
			s++;
		
		if(s == 26)
			break;
		
		ref[s] = -1;
		
		ans[siz++] = s+'a';
			
		for(int t=0;t<26;t++)
			if(alpha[s][t])
				ref[t]--;
	}
	return;
}

int main()
{
	int n;
	cin >> n;
	
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			alpha[i][j] = false;

	for(int i=0;i<n;i++)
		cin >> in[i];

	for(int i=1;i<n;i++)
	{
		int siz=in[i-1].size();
		int sizz=in[i].size();
		int sizzz=min(siz,sizz);
		bool sub = false;
		int sk=-1;
		
		for(int k=0;k<sizzz;k++)
		{
			if(in[i-1][k] != in[i][k])
				break;
			else if(k==sizzz-1)
			{
				sub = true;
				if(siz > sizz)
					noans = true;
				break;
			}
			sk = k;
		}
		//cout << in[i-1][sk+1] << " " << in[i][sk+1] << endl;
		if(!sub)
			alpha[in[i-1][sk+1]-'a'][in[i][sk+1]-'a'] = true;
	}
	
	topo();
	
	if(siz<26 || noans)
		cout << "Impossible";
	else
		for(int i=0;i<26;i++)
			cout << ans[i];
	
	cout << endl;
}
