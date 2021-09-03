#include <iostream>
#include <iomanip>
using namespace std;
#define MAX_M (300*10) // represent dollar with 10c

int main()
{
	long long Money[MAX_M+1];
	// represent with 10c
	// ignore 5c because it doesn't affect the result
	int Currency[11] = {-1,1,2,5,10,20,50,100,200,500,1000};
	double amount;

	for (int i=0; i<MAX_M+1; i++)
	{
		Money[i] = 1; // all made up with 5c
	}
	for (int kind=1; kind<11; kind++)
	{
		for (int M=Currency[kind]; M<MAX_M+1; M++)
		{
			// there are two possible ways to made up M
			// Use this "kind" of currency or not use
			Money[M] += Money[M-Currency[kind]];
		}
	}

	cin >> amount;
	cout << fixed << setprecision(2);
	while(amount)
	{
		cout << setw(6) << amount;
		cout << setw(17) << Money[int(amount*10)] << endl;
		cin >> amount;
	}

	return 0;
}
