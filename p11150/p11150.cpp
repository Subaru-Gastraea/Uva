#include <iostream>
using namespace std;

int main()
{
	int N = 0, newbtl = 0, lft = 0, tot = 0, max = 0;
	
	while (cin >> N)
	{
		tot = max = N;
		while (tot >= 3)
		{
			newbtl = tot / 3;
			lft = tot % 3;
			tot = newbtl + lft;
			max += newbtl;
		}
		
		if (tot == 2)
		{
			max++;
		}
		
		cout << max << endl;
	}

	return 0;
}