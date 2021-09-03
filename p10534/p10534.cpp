#include <iostream>
#include <algorithm> // lower_bound
using namespace std;
#define maxN 10000

int Li_len[maxN], rLi_len[maxN]; // len of LIS end at i

void LIS(const int seq[], int s, int t)	// range: from s to t(not included)
{
	int len = 1, pos;
	int L[maxN];
	L[0] = seq[s];	// insert first element

	if (s < t)
	{
		Li_len[0] = 1;
		for (int i=s+1; i<t; i++)
		{
			pos = lower_bound(L, L+len, seq[i]) - L;
			L[pos] = seq[i];
			// pos indexed from 0
			// pos+1 means len of updated sequence
			if (pos+1 > len) // if the updated sequence is LIS for now
				len = pos+1;
			
			Li_len[i] = len;
		}
	}
	else
	{
		rLi_len[0] = 1;
		for (int i=s-1; i>t; i--)
		{
			pos = lower_bound(L, L+len, seq[i]) - L;
			L[pos] = seq[i];
			if (pos+1 > len)
				len = pos+1;
			
			rLi_len[i] = len;
		}
	}
}

int main()
{
	int N, seq[maxN], len;
	while(cin >> N)
	{
		for(int i=0; i<N; i++)
			cin >> seq[i];
		LIS(seq, 0, N);
		LIS(seq, N-1, -1);
		
		// find the intersection point
		for (int i=0; i < maxN; i++)
		{
			if (Li_len[i] == rLi_len[i])
			{
				len = Li_len[i];
				break;
			}
		}
			
		cout << 2*len-1 << endl;
	}
}
