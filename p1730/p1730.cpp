#include <iostream>
using namespace std;

int main()
{
	int N, times, next;
	long long sum;

	cin >> N;
	while (N)
	{
		sum = N-1;
		for (int i=2; i<=N; i=next)
		{
			times = N/i;
			next = N/times + 1;

			sum += (long long)(i+(next-1))*(next-i)/2 * times;
		}
		cout << sum << endl;

		cin >> N;
	}

	return 0;
}
