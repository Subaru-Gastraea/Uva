#include <iostream>
#include <vector>
using namespace std;

void set_brch(vector<int> *brch, int n);
void fleaPR(vector<int> *brch, int n);
bool fleaJP(vector<int> *brch, int *path, int dist, int goal);
void prtMeet(int pt);
void prtJFor(int ptA, int ptB);
int main()
{
	int nodes, fleas;
	vector<int> *branches;

	cin >> nodes;
	while (nodes)
	{
		branches = new vector<int>[nodes+1];
		set_brch(branches, nodes);

		cin >> fleas;
		for (int f=0; f<fleas; f++)
		{
			fleaPR(branches, nodes);
		}

		delete[] branches;
		cin >> nodes;
	}

	return 0;
}
void set_brch(vector<int> *brch, int n)
{
	int ndKey, ndNext;
	for (int i=0; i<n-1; i++)	// n nodes have n-1 branches
	{
		cin >> ndKey >> ndNext;
		brch[ndKey].push_back(ndNext);
		brch[ndNext].push_back(ndKey);
	}
}
void fleaPR(vector<int> *brch, int n)
{
	int start, goal;
	int path[n];

	cin >> start >> goal;
	if (start == goal)
		prtMeet(start);
	else
	{
		path[0] = start;
		fleaJP(brch, path, 1, goal);
	}
}
bool fleaJP(vector<int> *brch, int *path, int dist, int goal)
{
	// current = path[dist-1]
	for (int b=0; b < brch[path[dist-1]].size(); b++)
	{
		if (dist>1 && brch[path[dist-1]][b] == path[dist-2])	// cannot jump back
			continue;

		if (brch[path[dist-1]][b] == goal)
		{
			if (dist%2 == 0)
				prtMeet(path[dist/2]);
			else
			{
				path[dist] = goal;
				prtJFor(path[dist/2], path[dist/2+1]);
			}
			return true;
		}
			
		path[dist] = brch[path[dist-1]][b];
		if ( fleaJP(brch, path, dist+1, goal) )
			return true;
	}

	return false;
}
void prtMeet(int pt)
{
	cout << "The fleas meet at " << pt << '.' << endl;
}
void prtJFor(int ptA, int ptB)
{
	if (ptA < ptB)
		cout << "The fleas jump forever between " << ptA << " and " << ptB << '.' << endl;
	else
		cout << "The fleas jump forever between " << ptB << " and " << ptA << '.' << endl;
}
