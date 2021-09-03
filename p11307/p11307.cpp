#include <iostream>
#include <string>
#include <string.h>	// strtok
#include <cstdlib>	// atoi
#include <bitset>
#include <vector>
#include <utility>	// pair
using namespace std;
#define MAXCOLOR 6
#define MAXN 10000
#define INF 1000000000

bitset<MAXN> topNd;

void setChild(vector<int> child[], const string treeDT);
int topIdx();	// return top node's index
void findMin(pair<int,int> root, const vector<int> child[], int minSum[][MAXCOLOR+1]);

int main()
{
	int n;
	string treeDT;

	cin >> n;
	while(n)
	{
		cin.ignore(10, '\n');
		int minSum[n][MAXCOLOR+1]; // the min color sum of the subtree with root in the first index colored as the number in the second index
		vector<int> child[n];
		pair<int,int> root; // first is node index, second is color number
		int min = INF;

		// initial
		for (int i=0; i<n; i++)
			for (int i2=0; i2<MAXCOLOR+1; i2++)
				minSum[i][i2] = -1;

		topNd.reset();
		for (int i=0; i<n; i++)
		{
			getline(cin, treeDT);
			setChild(child, treeDT);
		}

		root.first = topIdx();
		for (int color=1; color<=MAXCOLOR; color++)
		{
			root.second = color;
			findMin(root, child, minSum);
			if (minSum[root.first][color] < min)
				min = minSum[root.first][color];
		}
		cout << min << endl;

		cin >> n;
	}

	return 0;
}

void setChild(vector<int> child[], const string treeDT)
{
	int root, chd, len = treeDT.length();
	char *cstr = new char[len+1], *token;
	treeDT.copy(cstr, len);
	cstr[len] = '\0';

	token = strtok(cstr, " ");
	token[strlen(token)-1] = '\0';	// remove ':'
	root = atoi(token);

	token = strtok(NULL, " ");
	while (token)
	{
		chd = atoi(token);
		child[root].push_back(chd);
		topNd.set(chd);	// for finding the top node
		token = strtok(NULL, " ");
	}
	delete[] cstr;
}

int topIdx()
{
	int topi = 0;
	while(topNd[topi])	// find the first zero
		topi++;
	return topi;
}

void findMin(pair<int,int> root, const vector<int> child[], int minSum[][MAXCOLOR+1])
{
	if (minSum[root.first][root.second] != -1) // have been computed
		return;

	if (child[root.first].empty())	// leaf node
		minSum[root.first][root.second] = root.second;

	int minS = root.second, min;

	for (int chd : child[root.first])	// add all children's minSum to minS
	{
		min = INF;
		for (int chdCor=1; chdCor<=MAXCOLOR; chdCor++)	// try all color
		{
			if (chdCor != root.second)	// adjacent color can't be the same
			{
				findMin(make_pair(chd, chdCor), child, minSum);	// recursive
				if (minSum[chd][chdCor] < min)
					min = minSum[chd][chdCor];
			}
		}
		minS += min;
	}
	minSum[root.first][root.second] = minS;

	return;	
}
