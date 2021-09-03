#include <iostream>
using namespace std;

int main()
{
	unsigned int a, b;
	cin >> a >> b;
	while (a!=0 || b!=0)
	{
		unsigned int num = 0;
		bool c = 0;
		while (a!=0 || b!=0)
		{
			c = ((a%10)+(b%10)+c)/10;
			num += c;
			a/=10;
			b/=10;
		}
		if (num == 0)
			cout << "No carry operation." << endl;
		else if (num == 1)
			cout << "1 carry operation." << endl;
		else
			cout << num << " carry operations." << endl;
		cin >> a >> b;
	}
	return 0;
}