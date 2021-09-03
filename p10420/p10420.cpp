#include <iostream>
#include <string>
#include <map>
using namespace std; 

int main()
{
	map<string, int> ctry;
	string word;
	int line=0;
	cin >> line;
	
	for (int i=0; i<line; i++)
	{
		cin >> word;
		
		ctry[word] += 1;
		cin.ignore(75, '\n');
	}
	for (const auto& [ctyName, nP] : ctry)
	{
		cout << ctyName << ' ' << nP << endl;
	}
	return 0;
}
