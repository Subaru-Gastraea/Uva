#include <iostream>
using namespace std;

int main()
{
	int N, M, num, t;
	cin >> N;
	
	for (int i=0; i<N; i++)
	{
		int b1=0, b2=0;
		cin >> M;
		t = M;
		
		while (M > 0)
		{
			b1 += M%2;
			M/=2;
		}
		
		while (t > 0)
		{
			num = t%10;
			while (num > 0)
			{
				b2+=num%2;
				num/=2;
			}
			t/=10;
		}
		
		cout << b1 << ' ' << b2 << endl;
	}

	return 0;
}