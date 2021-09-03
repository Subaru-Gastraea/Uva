#include <iostream>
#include <string>
using namespace std;
int TB[100];

int sumN(int n)
{
	int s = 0, mulN;
	for (int i=1; i<=n; i++)
	{
		mulN = 1;
		for (int cnt=1; cnt<=i; cnt++) // last digit of pow(i,i)
		{
			mulN *= i;
			mulN %= 10;
		}
		s += mulN;
		s %= 10;
	}
	return s;
}

int main()
{
	string BigN;
	int len, num;
	for (int i=1; i<100; i++)
	{
		TB[i] = sumN(i);
	}

	cin >> BigN;
	while (BigN != "0")
	{
		len = BigN.length();
		num = BigN[len-1]-'0';
		if (len != 1)
			num += (BigN[len-2]-'0')*10;
		cout << TB[num] << endl;

		cin >> BigN;
	}

	return 0;
}
