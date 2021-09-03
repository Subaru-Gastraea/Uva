#include <iostream>
#include <string>
using namespace std;

bool comp(const string &find, const string &str);

int main()
{
	int Ruls = 0, cur = 0, fdLen = 0;
	string find[10], repl[10], str;

	cin >> Ruls;
	while (Ruls)
	{
		cin.ignore(10, '\n');
		for (int i=0; i<Ruls; i++)
		{
			getline(cin, find[i]);
			getline(cin, repl[i]);
		}
		getline(cin, str);

		for (int i=0; i<Ruls; i++)
		{
			cur = 0;
			fdLen = find[i].length();
			while (cur <= int(str.length())-fdLen)	// str.length() returns unsigned int
			{
				if ( comp(find[i], str.substr(cur, fdLen)) )
				{
					str.erase(cur, fdLen);
					str.insert(cur, repl[i]);

					cur -= (fdLen-1);
					if (cur < 0) cur = 0;
				}
				else
					cur++;
			}
		}
		cout << str << endl;

		cin >> Ruls;
	}
	return 0;
}

bool comp(const string &find, const string &str)
{
	int L = str.length();
	for (int ch=0; ch<L; ch++)
	{
		if (find[ch] != str[ch])
			return false;
	}
	return true;
}
