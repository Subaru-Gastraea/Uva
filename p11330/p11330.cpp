#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int cs, n, L, R, *pair, *gp_head, *hd_group, group, gpNum, gpKEY, hd_gp, gp_hd;
	cin >> cs;
	while (cs--)
	{
		cin >> n;
		pair = new int[10005]{0};
		gp_head = new int[10005]{0};
		hd_group = new int[10005]{0};
		gpNum = group = 0;

		for (int i=1; i<=n; i++)
		{
			cin >> L >> R;	// Left and Right shoes
			if (L == R)	// unit group
			{
				group--;
				continue;
			}

			if (pair[L] == 0)
			{
				group--; // create new group, # of groups "abs(group)" increase
				gpNum--;
				gp_head[abs(gpNum)] = L;
				hd_group[L] = gpKEY = gpNum;
			}
			else	// pair[L] < 0
				gpKEY = pair[L];
			pair[L] = R;

			if (pair[R] == 0)
				pair[R] = gpKEY;	// mark it with negative num gpKEY
							// means it's in one of the groups
							// That is, there is the other shoe want to exchange with it
			else	// pair[R] > 0
			{
				hd_gp = hd_group[R];
				gp_hd = gp_head[abs(gpKEY)];	
				if (gpKEY != hd_gp)
				{	
					group++;	// merge two different group
					hd_group[gp_hd] = hd_gp;
					gp_head[abs(hd_gp)] = gp_hd;
				}
			}
		}
		cout << (n-abs(group)) << endl;

		delete[] pair;
		delete[] gp_head;
		delete[] hd_group;
	}

	return 0;
}
