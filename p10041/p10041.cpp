#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
bool comp(const int &a, const int &b)
{
	return (a<b);
}

int main()
{
	int N, R, *St;
	cin >> N;
	while (N--)
	{
		int sum = 0;
		cin >> R;
		St = new int[R];
		
		for (int i=0; i<R; i++)
			cin >> St[i];
			
		sort(St, St+R, comp);
		
		for (int i=0; i<R; i++)
			sum += abs(St[i]-St[R/2]);
			
		cout << sum << endl;
		delete[] St;
	}
	return 0;
}