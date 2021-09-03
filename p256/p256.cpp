#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		for (int i = 0, num = 0; num < pow(10,n); i++, num = pow(i,2))
		{
			int sum = 0;
			sum = num/int(pow(10,n/2)) + num%int(pow(10,n/2));
			if (sum == i)
				cout << setw(n) << setfill('0') << num << endl;
		}
	}

	return 0;
}
