#include <iostream>
#include <vector>
using namespace std;
int lpf[2000005];
int phi[2000005];
int dphi[2000005];
vector<int> prime;

void LPF_TB()	// build least prime factor table
{
	prime.clear();
	for (int i=2; i<2000005; i++)
	{
		if (!lpf[i])
		{
			prime.push_back(i);
			lpf[i] = i;
		}
		for (int p=0; i*prime[p]<2000005; p++)
		{
			lpf[i*prime[p]] = (prime[p]<lpf[i]) ? prime[p] : lpf[i];
			if (i%prime[p] == 0)
				break;
		}
	}
}

void phiTB()	// build phi and dphi table
{
	phi[0] = phi[1] = 0;
	dphi[1] = 0;
	for (int A=2, B; A<2000005; A++)
	{
		if (lpf[A] == A) // A is a prime
			phi[A] = A-1; // by definition
		else
		{
			B = A/lpf[A];	// A = B*lpf[A]
			if (B%lpf[A] != 0)
				// phi[B*lpf[A]] = phi[B]*phi[lpf[A]]
				// phi[lpf[A]] = lpf[A]-1
				phi[A] = phi[B]*(lpf[A]-1);
			else
				// phi[B*lpf[A]] = phi[B] * phi[lpf[A]] * GCD(B,lpf[A]) / phi(GCD(B,lpf[A]))
				// GCD(B,lpf[A]) = lpf[A]
				phi[A] = phi[B]*lpf[A];
		}
		dphi[A] = dphi[phi[A]] + 1;
	}
}

int main()
{
	LPF_TB();
	phiTB();

	int N, m, n;
	cin >> N;
	while (N--)
	{
		int sum = 0;
		cin >> m >> n;
		for (int i=m; i<=n; i++)
			sum += dphi[i];
		cout << sum << endl;
	}
	return 0;
}
