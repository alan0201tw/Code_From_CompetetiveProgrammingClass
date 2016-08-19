#include <iostream>
#include <queue>

using namespace std;

queue <int> card;

int solve (int c)
{
	int check=0;
	cout << "Discarded cards:";
	for(int i=1;i<=c;i++)
		card.push(i);
	while(card.size()>=2)
	{
		if(check==0)
		{
		cout << " " << card.front();
		check = 1;
		}
		else
		cout << ", " << card.front();
		
		card.pop();
		
		if(card.size()>=2)
		{
		card.push(card.front());
		card.pop();
		}
	}
	cout << endl;
	if(card.size()==1)
		cout << "Remaining card: " << card.front() << endl;
		
	while(!card.empty())
		card.pop();
	
}

int main()
{
	int n;
	while(cin >> n && n)
		solve(n);

}
