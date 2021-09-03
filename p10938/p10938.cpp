#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int nodes, fleas, ndKey, ndNext, start, goal, cur, tryNx;
	vector<int> *branches;
	vector<int> next, path, backTrc;
	cin >> nodes;

	while (nodes)
	{
		branches = new vector<int>[nodes+1];

		for (int i=0; i<nodes-1; i++)	// the number of branches = nodes-1
		{
			cin >> ndKey >> ndNext;
			branches[ndKey].push_back(ndNext);
			branches[ndNext].push_back(ndKey);
		}

		cin >> fleas;
		for (int i=0; i<fleas; i++)
		{
			next.clear();
			path.clear();
			backTrc.clear();

			cin >> start >> goal;
			if (start == goal)
			{
				cout << "The fleas meet at " << start << '.' << endl;
				continue;
			}

			path.push_back(start);
			cur = start;
			for (int i2=0; i2<branches[start].size(); i2++)
			{
				int b_elem = branches[start][i2];
				if (b_elem == goal)
				{
					if (start > b_elem)
						cout << "The fleas jump forever between " << b_elem << " and " << start << '.' << endl;
					else
						cout << "The fleas jump forever between " << start << " and " << b_elem << '.' << endl;
					continue;
				}
				next.push_back(b_elem);
			}

			backTrc.push_back(branches[start].size());

			tryNx = next.back();
			while (tryNx != goal)
			{
				int trySz = branches[tryNx].size();
				backTrc.push_back(trySz);
				path.push_back(tryNx);
				next.pop_back();
				if (trySz > 1)	// not leaf
				{
					for (int i2=0; i2 < trySz; i2++)
					{
						int b = branches[tryNx][i2];
						if (b != cur)
							next.push_back(b);
					}
					cur = tryNx;
				}
				backTrc.back()--;
				while (backTrc.back() == 0)
				{
					backTrc.pop_back();
					path.pop_back();
					cur = path.back();
					backTrc.back()--;
				}

				tryNx = next.back();
			}

			int pSz = path.size();
			if (pSz%2 == 0)
				cout << "The fleas meet at " << path[pSz/2] << '.' << endl;
			else
			{
				int S, L;
				path.push_back(goal);
				if (path[pSz/2] < path[pSz/2+1])
				{
					S = path[pSz/2];
					L = path[pSz/2+1];
				}
				else
				{
					L = path[pSz/2];
					S = path[pSz/2+1];
				}
				cout << "The fleas jump forever between " << S << " and " << L << '.' << endl;
			}
		}
		delete[] branches;

		cin >> nodes;
	}

	return 0;
}
