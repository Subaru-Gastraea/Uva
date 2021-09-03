#include <iostream>
using namespace std;

void MaxMin(long long *MxMn, long long &add, long long &mul);

int main()
{
	int N;
	long long add, mul, MxMn[2];
	cin >> N;
	cin.get();	// ignore '\n'

	while (N--)
	{
		add = 0;
		mul = 1;
		
		MaxMin(MxMn, add, mul);
		cout << "The maximum and minimum are "
			<< (MxMn[0] * mul) << " and "
			<< (MxMn[1] + add) << '.' << endl;
	}

	return 0;
}

void MaxMin(long long *MxMn, long long &add, long long &mul)
{
	int num;
	char ch1, ch2;

	ch1 = cin.get();
	ch2 = cin.get();

	// set number
	if ((ch2 >= '0') && (ch2 <= '9'))
	{
		num = (ch1-'0')*10 + (ch2-'0');
		ch2 = cin.get();
	}
	else
		num = (ch1-'0');

	if (ch2 == '\n')  // end of expression
	{
		MxMn[0] = MxMn[1] = num;
		return;
	}

	MaxMin(MxMn, add, mul);
	if (ch2 == '+')
	{
		MxMn[0] += num;
		add += MxMn[1];
		MxMn[1] = num;
	}
	else
	{
		mul *= MxMn[0];
		MxMn[0] = num;
		MxMn[1] *= num;
	}

	return;
}
