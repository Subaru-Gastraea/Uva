#include <iostream>
#include <set>
using namespace std;
#define MAX_N 10001
#define MAX_K 100

int main()
{
	int M, N, K, num[MAX_N], rm;
	set<int> newR;
	cin >> M;
	while(M--)
	{
		cin >> N >> K;
		bool remain[K] = {false};
		for (int i=1; i<=N; i++)
		{
			cin >> num[i];
		}

		rm = num[1] % K;
		if (rm<0)
			rm += K;
		remain[rm] = true;
		for (int i=2, rm1, rm2; i<=N; i++)
		{
			newR.clear();
			for (int R=0; R<K; R++)
			{
				if (remain[R])
				{
					rm1 = (R+num[i])%K;
					if (rm1<0)
						rm1 += K;
					rm2 = (R-num[i])%K;
					if (rm2<0)
						rm2 += K;
					newR.insert(rm1);
					newR.insert(rm2);
				}
				remain[R] = false; // clear
			}
			// replace old remain with newR
			for (const int& R: newR)
				remain[R] = true;
		}

		if (remain[0])
			cout << "Divisible" << endl;
		else
			cout << "Not divisible" << endl;
	}

	return 0;
}
