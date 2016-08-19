#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

int arr[100000];
int siz;

int rec (int ind)
{
	int sum = 0;
	int s = ind;
	
	while(arr[s+1] != -arr[ind])
	{
		sum -= arr[s+1];
		
		s = rec(s+1);
		
		if(s == -1 || sum >= -arr[ind])
			return -1;
	}
	return s+1;
	
}

int main()
{
	string gin;
	
	while(getline(cin,gin))
	{
		stack <int> st;
		stringstream in;
		in << gin;
		siz = 0;
		
		while(in>>arr[siz])
			siz ++;
			
		for(int i=0;i<siz;i++)
		{
			if(!st.empty() && arr[i] == -(st.top()) && arr[i] > 0)
			{
				st.pop();
			}
			else
				st.push(arr[i]);
			
		}
		if(st.empty() && rec(0) != -1)
			cout << ":-) Matrioshka!\n";
		else
			cout << ":-( Try again.\n";
		
	}
}
