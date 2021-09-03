#include <iostream>
#include <vector>
using namespace std;

void longest(int cs, int s, vector<int> path[]);

int main()
{
	int N, cnt = 0, s, p, q;

	cin >> N;
	while (N)
	{
		cnt++;
		vector<int> path[N+1];

		cin >> s;
		cin >> p >> q;
		while (p)
		{
			path[p].push_back(q);
			cin >> p >> q;
		}

		longest(cnt, s, path);
		cin >> N;
	}
	return 0;
}

void longest(int cs, int s, vector<int> path[])
{
	int root, minQ = 999, min, qsize, i, i2, len = 0;
	vector<int> queue;
	queue.push_back(s);
	qsize = queue.size();

	while (!queue.empty())
	{
		if (qsize == 0)
		{
			len++;
			min = minQ;
			minQ = 999;	// a large number
			qsize = queue.size();
		}

		root = queue.front();
		queue.erase(queue.begin());
		
		for (i2=0; i2<path[root].size(); i2++)
		{
			if (path[root][i2] < minQ)
				minQ = path[root][i2];
			queue.push_back(path[root][i2]);
		}
		qsize--;
	}
	cout << "Case " << cs << ": ";
	cout << "The longest path from " << s << " has length "
		 << len << ", finishing at " << min << '.' << endl << endl;
}
