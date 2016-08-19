#include <iostream>

using namespace std;

int main()
{
    string in;
    
    while(cin >> in)
    {
    	int mark = 0;
        int ab[in.size()] = {0},ba[in.size()] = {0};
        
        
        for(int i = 0;i<in.size();i++)
        {
            if(in[i] == 'A' && in[i+1] == 'B')
                ab[i] = 1;
            if(in[i] == 'B' && in[i+1] == 'A')
            	ba[i] = 1;
        }
        for(int k = 0;k<in.size();k++)
        {
        	if(mark == 1)
        		break;
        	
        	if(ab[k] == 1)
        		for(int j = k+2;j<in.size();j++)
        			if(ba[j] == 1)
        				{
        					cout << "YES\n";
        					mark = 1;
        					break;
        				}
        	
        	if(mark == 1)
        		break;
        	
        	else if(ba[k] == 1)
        		for(int j = k+2;j<in.size();j++)
        			if(ab[j] == 1)
        				{
        					cout << "YES\n";
        					mark = 1;
        					break;
        				}
        }
        if(mark == 0)
        	cout << "NO\n";
    }
    
}
