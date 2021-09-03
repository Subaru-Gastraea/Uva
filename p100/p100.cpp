#include <iostream>

using namespace std;

int main()
{
	int i = 0, j = 0, ti = 0, tj = 0;

	while (cin >> i >> j)
	{
		int max = 1;
		if (i > j)
		{
			ti = j;
			tj = i;
		}
		else
		{
			ti = i;
			tj = j;
		}

		for (int n = ti; n <= tj; n++)
		{
			int tn = n, cnt = 1;
			while (tn > 1)
			{
				if (tn%2 == 0)
					tn /= 2;
				else
					tn = 3*tn + 1;
				cnt++;
			}

			max = (cnt > max) ? cnt : max;
		}
		cout << i << ' ' << j << ' ' << max << endl;
	}

	return 0;
}
