#include <iostream>
using namespace std;

int main()
{
	long long sum, N, half;

	cin >> N;
	while (N)
	{
		half = N/2;
		//sum = N*N-1 - (1+(N-half-1))*(N-half-1)/2;	// square area - triangle area
		sum = N*N-1 - (N-half)*(N-half-1)/2;

		for (int i=2; i<=half; i++)
			sum -= N%i;

		cout << sum << endl;
		cin >> N;
	}

	return 0;
}
