#include <iostream>
using namespace std;

#define INF 1000000000
#define C_NUM 101

void setSound(int sound[][C_NUM], int S);
void setMin(int sound[][C_NUM], int C);

int main()
{
    int C, S, Q, cs = 0, c1, c2, deci;
    while (cin >> C >> S >> Q)
    {
	if (!(C|S|Q))
		break;

	cs++;
	int sound[C_NUM][C_NUM];
	for (int i=1; i<=C; i++)
	{
	    for (int j=1; j<=C; j++)
		sound[i][j] = INF;
	    sound[i][i] = 0;
	}
	setSound(sound, S);
        setMin(sound, C);

        if (cs > 1) cout << endl;
        cout << "Case #" << cs << endl;

        while (Q--)
	{
            cin >> c1 >> c2;
	    deci = sound[c1][c2];
            if (deci == INF)
                cout << "no path" << endl;
            else
                cout << deci << endl;
        }
    }
}

void setSound(int sound[][C_NUM], int S)
{
    int c1, c2, deci;

    for (int i=0; i<S; i++)
    {
	cin >> c1 >> c2 >> deci;
	sound[c1][c2] = deci;
	sound[c2][c1] = deci;
    }
}

void setMin(int sound[][C_NUM], int C)
{
    int newMax;
    for (int mid = 1; mid <= C; mid++)
        for (int beg = 1; beg <= C; beg++)
            for (int end = 1; end <= C; end++)
	    {
		newMax = (sound[beg][mid] > sound[mid][end]) ?
		    sound[beg][mid] : sound[mid][end];
                if (newMax < sound[beg][end])
		    sound[beg][end] = newMax;
	    }
}
