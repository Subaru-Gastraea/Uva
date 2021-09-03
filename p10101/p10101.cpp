#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	long long num, temp;
	int Case = 0;
	string text[4] = {" kuti"," shata"," hajar"," lakh"};
						
	while (cin >> num)
	{
		int numarr[9]={0}, i=0;

		Case++;
		cout << setw(4) << Case << '.';

		if (num < 100)
			cout << ' ' << num;
		else
		{
			temp = num;
			while (temp)
			{
				if (i==1 || i==5)
				{
					numarr[i] = temp%10;
					temp/=10;
				}
				else
				{
					numarr[i] = temp%100;
					temp/=100;
				}	
				i++;
			}
		
			for (i=8; i>=0; i--)
			{
				if (numarr[i])
				{
					cout << ' ' << numarr[i];
					if (i) cout << text[i%4];
				}
				else if (i==4 && num>=10000000)
					cout << " kuti";
			}	
		}
		cout << endl;
	}
	return 0;
}
