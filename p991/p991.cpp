#include <iostream>
using namespace std;
#define maxN 10
int Pair[maxN+1]; // for DP

int main()
{
	int N, cnt = 0;

	Pair[0] = Pair[1] = 1;
	for (int i=2; i<=maxN; i++)
	{
		Pair[i] = 0;
		for (int i2=0; i2<i; i2++)
		{
			// two of them form a pair, divide the group into two parts
			// sum up all combinations
			Pair[i] += Pair[i2]*Pair[i-i2-1];
		}
	}

	while (cin >> N)
	{
		if(cnt) cout << endl;
		cout << Pair[N] << endl;
		cnt++;
	}
	return 0;
}
