#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXREG 100
#define MAX_V (2*MAXREG+2)
#define INF 1000000000

int res[MAX_V][MAX_V], mf, f, s, t;
vector<int> p;

void augment(int v, int minEdge)
{
	if (v == s)
	{
		f = minEdge;
		return;
	}
	else if (p[v] != -1)
	{
		augment(p[v], min(minEdge, res[p[v]][v])); // recursive
		res[p[v]][v] -= f;
		res[v][p[v]] += f;	// for restore if needed
	}
}

int main()
{
	int N, M, B, D;
	while (cin >> N)
	{
		s = 0, t = MAX_V-1;
		memset(res, 0, sizeof(res));
		for (int reg=1, cap; reg<=N; reg++)
		{
			cin >> cap;
			res[reg][reg+MAXREG] = res[reg+MAXREG][reg] = cap;	// split each regulator, assign between Vin and Vout
		}
		cin >> M;
		for (int link=0, i, j; link<M; link++)
		{
			cin >> i >> j;
			cin >> res[i+MAXREG][j];	// Vout = Vin + MAXREG
		}
		cin >> B >> D;
		for (int entry=0, reg; entry<B; entry++)
		{
			cin >> reg;
			res[s][reg] = INF;
		}
		for (int out=0, reg; out<D; out++)
		{
			cin >> reg;
			res[reg+MAXREG][t] = INF;
		}

		mf = 0;
		while (true)
		{
			f = 0;
			vector<int> dist(MAX_V, INF);
			dist[s] = 0;
			queue<int> q;
			q.push(s);
			p.assign(MAX_V, -1);

			while (!q.empty())
			{
				int u = q.front();
				q.pop();
				if (u == t)
					break;
				for (int v=0; v<MAX_V; v++)
				{
					if (res[u][v] > 0 && dist[v] == INF)
					{
						dist[v] = dist[u]+1;
						q.push(v);
						p[v] = u;
					}
				}
			}
			augment(t, INF);
			if (f == 0)
				break;
			mf += f;
		}
		cout << mf << endl;
	}

	return 0;
}
