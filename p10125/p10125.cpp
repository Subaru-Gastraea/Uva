#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, d, Size, maxj, cnt, cnt1, i, j;
	int *S, *S1, *S2, *iArr, *jArr;

	cin >> n;
	while (n)
	{
		Size = n*(n-1)/2;	// n*(n-1)/2 = (n-1)+(n-2)+...+1
		d = -536870913;	// d initial to the smallest number - 1
		S = new int[n+10];
		S1 = new int[Size+10];
		S2 = new int[Size+10];
		iArr = new int[Size+10];
		jArr = new int[Size+10];

		for (i=0; i<n; i++)
			cin >> S[i];
		sort(&S[0], &S[n]);

		for (i=0, cnt=0; i<n-1; i++)
		{
			for (j=i+1; j<n; j++, cnt++)
			{
				iArr[cnt] = i;
				jArr[cnt] = j;
				S1[cnt] = S[i] + S[j];
				S2[cnt] = S[j] - S[i];
			}
		}
		// S[0] is the smallest element in S
		// maxj initial to -1
		for (cnt=0, maxj=-1; cnt<Size; cnt++)
		{
			for (cnt1=0; cnt1<Size; cnt1++)
			{
				// c!=a && c!=b && d!=a && d!=b
				if (iArr[cnt]!=iArr[cnt1] && iArr[cnt]!=jArr[cnt1] &&
					jArr[cnt]!=iArr[cnt1] && jArr[cnt]!=jArr[cnt1])
				{
					if (S1[cnt1]==S2[cnt] && jArr[cnt]>maxj)
					{
						maxj = jArr[cnt];
						d = S[maxj];
					}
					else if (S1[cnt1]== -1*S2[cnt] && iArr[cnt]>maxj)
					{
						maxj = iArr[cnt];
						d = S[maxj];
					}
				}
			}
		}

		if (d == -536870913)
			cout << "no solution" << endl;
		else
			cout << d << endl;
		
		delete[] S;
		delete[] S1;
		delete[] S2;
		delete[] iArr;
		delete[] jArr;

		cin >> n;
	}

	return 0;
}
