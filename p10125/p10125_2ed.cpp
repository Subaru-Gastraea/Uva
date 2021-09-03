#include <iostream>
#include <map>
#include <vector>
#include <utility>
using namespace std;

int main()
{
	int n, d, i, j;
	int *S;
	map<int, vector<pair<int,int>>> S1;
	pair<int,int> ij;
	vector<pair<int,int>> vec;

	cin >> n;
	while (n)
	{
		S1.clear();
		d = -536870913;	// d initial to the smallest number - 1
		S = new int[n];

		for (i=0; i<n; i++)
			cin >> S[i];

		for (i=0; i<n-1; i++)
		{
			for (j=i+1; j<n; j++)
			{
				ij = make_pair(i,j);
				S1[S[i] + S[j]].push_back(ij);
			}
		}
		
		for (i=0; i<n-1; i++)
		{
			for (j=i+1; j<n; j++)
			{
				if (S[i] > d)
				{
					vec = S1[S[i]-S[j]];
					for (const auto &pair : vec)
					{
						// c!=a && c!=b && d!=a && d!=b
						if ((i!=pair.first) && (i!=pair.second) && (j!=pair.first) && (j!=pair.second))
						{
							d = S[i];
							break;
						}
					}
				}

				if (S[j] > d)
				{
					vec = S1[S[j]-S[i]];
					for (const auto &pair : vec)
					{
						if ((i!=pair.first) && (i!=pair.second) && (j!=pair.first) && (j!=pair.second))
						{
							d = S[j];
							break;
						}
					}
				}

			}
		}

		if (d == -536870913)
			cout << "no solution" << endl;
		else
			cout << d << endl;
		
		delete[] S;

		cin >> n;
	}

	return 0;
}
