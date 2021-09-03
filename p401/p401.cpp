#include <iostream>
#include <string>
using namespace std;

bool IsPal(string input);
bool IsMir(string input);

int main()
{
	string input;
	
	while ( getline(cin, input) )
	{
		cout << input;
	
		if ( IsPal(input) )
		{
			if ( IsMir(input) )
				cout << " -- is a mirrored palindrome.\n\n";
			else
				cout << " -- is a regular palindrome.\n\n";
		}
		else if ( IsMir(input) )
			cout << " -- is a mirrored string.\n\n";
		else
			cout << " -- is not a palindrome.\n\n";
	}

	return 0;
}

bool IsPal(string input)
{
	int head = 0, tail = input.length()-1;
	
	while(head <= tail)
	{
		if (input[head] != input[tail]) return false;
		head++;
		tail--;
	}
	
	return true;
}

bool IsMir(string input)
{
	int head = 0, tail = input.length()-1, i = 0;
	char ch[8] = {'E', 'J', 'L', 'S', 'Z', '2', '3', '5'};
	char R[8] = {'3', 'L', 'J', '2', '5', 'S', 'E', 'Z'};
	char selfR[13] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y', '1', '8'};
	
	while(head <= tail)
	{
		if (input[head] != input[tail])
		{
			for (i = 0; i < 8; i++)
			{
				if ( ((input[head] == ch[i]) && (input[tail] == R[i])) ||
						((input[head] == R[i]) && (input[tail] == ch[i])) )
					break;	
			}
			
			if (i >= 8) return false;
		}
		else
		{
			for (i = 0; i < 13; i++)
				if ( input[head] == selfR[i] ) break;
				
			if (i >= 13) return false;
		}
		
		head++;
		tail--;
	}
	
	return true;
}