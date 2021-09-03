#include <iostream>
using namespace std;

int main()
{
	int N = 0;
	cin >> N;
	while (N != -1)
	{
		int m = 0, fm = 1, tm = 0;
		while (N--)
		{
			tm = m;
			m += fm;
			fm = tm+1;
		}
		cout << m << ' ' << (long(m)+fm) << endl;
		cin >> N;
	}

	return 0;
}
