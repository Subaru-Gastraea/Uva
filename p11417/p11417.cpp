#include <iostream>
using namespace std;

int GCD(int x, int y);

int main()
{
	int G = 0, N = 0;
	
	cin >> N;
	while (N != 0)
	{
		for (int i = 1; i < N; i++)
		{
			for (int j = i+1; j <= N; j++)
			{
				G += GCD(i, j);
			}
		}
		
		cout << G << endl;
		G = 0;
	
		cin >> N;
	}

	return 0;
}

int GCD(int x, int y)
{
	int r = 0;
	
	while (x != 0)
	{
		r = y % x;
		y = x;
		x = r;
	}
	
	return y;
}