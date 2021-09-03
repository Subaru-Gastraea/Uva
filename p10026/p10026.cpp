#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
typedef tuple<int,int,int> Tri;

bool cmp(const Tri& a, const Tri& b)
{
	int costA, costB;
	costA = get<0>(a)*get<1>(b); // dayA*fineB
	costB = get<0>(b)*get<1>(a); // dayB*fineA
	if (costA == costB)
		return (get<2>(a) < get<2>(b)); // indexA < indexB
	else
		return (costA < costB);
}

int main()
{
	int caseN, N, day, fine;
	cin >> caseN;
	for (int i=0; i<caseN; i++)
	{
		if(i) cout << endl;
		cin >> N;
		Tri jobs[N];

		for (int i2=0; i2<N; i2++)
		{
			cin >> day >> fine;
			jobs[i2] = make_tuple(day,fine,i2+1);
		}

		sort(jobs, jobs+N, cmp);

		for (int i2=0; i2<N; i2++)
		{
			if(i2) cout << ' ';
			cout << get<2>(jobs[i2]);
		}
		cout << endl;
	}

	return 0;
}
