#include <iostream>
#include <vector>
using namespace std;
bool primeTB[1005];

int main()
{
	int N, C;
	primeTB[0] = true; // not prime
	for(int i=2;i<1005;i++)
	{
		if(primeTB[i] != true) // i is prime
		{
			for(int j=i*i; j<1005; j+=i)
			{
				primeTB[j] = true;
			}
		}
	}
	while(cin >> N >> C)
	{
		cout << N << " " << C << ":";
		vector<int> primeL;
		for(int i=1; i<=N; i++)
		{
			if(primeTB[i] == false)
				primeL.push_back(i);
		}
		int len = primeL.size(), prtLen = 2*C-len%2, start = len/2-prtLen/2;

		if(prtLen > len)
		{
			for(const int& prime: primeL)
			{
				cout << " " << prime;
			}
		}
		else
		{
			for(int i=start; i<(start+prtLen); i++)
			{
				cout << " " << primeL[i];
			}
		}
		cout << endl << endl;
	}
	return 0;    
}
