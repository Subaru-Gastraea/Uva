#include <iostream>
#include <bitset>
using namespace std;
const int N = 100;

void longest(int cs, int s, bitset<N> path[N]);

int main()
{
	int n, cnt = 0, s, p, q;

	cin >> n;
	while (n)
	{
		cnt++;
		bitset<N> path[N];
		for (int i=0; i<N; i++)
			path[i].reset();	// set all bits to 0

		cin >> s;
		cin >> p >> q;
		while (p)
		{
			path[p-1].set(q-1);	// path[p-1][q-1] = 1
			cin >> p >> q;
		}

		longest(cnt, s, path);
		cin >> n;
	}
	return 0;
}

void longest(int cs, int s, bitset<N> path[N])
{
	int i = 1, min, minQ, len = 0;
	bitset<N> qu, nextQu;
	qu.reset();
	nextQu.reset();
	qu |= path[s-1];

	while (!qu.none())	// if not all bits set to 0
	{
		while (!qu[0])
		{
			i++;
			qu >>= 1;
		}
		minQ = i;
		nextQu |= path[i-1];
		i++;
		qu >>= 1;

		while (!qu.none())
		{
			while (!qu[0])
			{
				i++;
				qu >>= 1;
			}
			nextQu |= path[i-1];
			i++;
			qu >>= 1;	
		}

		len++;
		qu = nextQu;
		nextQu.reset();
		i = 1;
		min = minQ;	// store min of last layer
	}
	cout << "Case " << cs << ": ";
	cout << "The longest path from " << s << " has length "
		 << len << ", finishing at " << min << '.' << endl << endl;
}
