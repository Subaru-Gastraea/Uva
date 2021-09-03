#include <iostream>
using namespace std;

const int BIGNUM = 1600;

class Num{
	public:
		Num();
		Num(int val);
		Num(const Num &Num1);
		~Num();

		int getnum(int i) {return num[i];}
		int getN() {return N;}
		void operator=(const Num &Num1);
		void operator*=(const Num &Num1);
		void operator/=(int d);
	private:
		void carry();
		int *num;
		int N;
};

Num* ansTb[1001] = {nullptr};

void cntAns(int Ndnum)
{
	if (!ansTb[Ndnum])
	{
		if (Ndnum == 1)
			ansTb[Ndnum] = new Num(1);
		else
		// generating function
		// (2n)! / (n+1)(n!)(n!)
		{
			Num mul(1);
			int mul2 = Ndnum/2, div = Ndnum-mul2;

			for (int i=2*Ndnum-1; i>=Ndnum+2; i-=2)
				mul *= i;
		
			for (int i=2; i<=div; i++)
			{
				int temp = i;
				while (temp%2 == 0)
				{
					temp /= 2;
					mul2--;
				}
				if (temp > 1)
					mul /= temp;
			}
			
			for (int i=0; i<mul2; i++)
				mul *= 2;

			ansTb[Ndnum] = new Num(mul);
		}
	}
}

int main()
{		
	int i;
	while (cin >> i)
	{
		cntAns(i);
		for (int p = (*ansTb[i]).getN(); p>0; p--)
			cout << (*ansTb[i]).getnum(p-1);
		cout << endl;
	}

	for (int d=0; d<=1000; d++)
		if (ansTb[d])
			delete ansTb[d];
	return 0;
}

Num::Num() : N(0)
{
	num = new int[BIGNUM]{0};
}

Num::Num(int val)
{
	N = 0;
	num = new int[BIGNUM]{0};

	while (val > 0)
	{
		num[N] = val%10;
		N++;
		val /= 10;
	}
}

Num::Num(const Num &Num1) : N(Num1.N)
{
	num = new int[BIGNUM]{0};
	for (int i=0; i<Num1.N; i++)
		num[i] = Num1.num[i];
}

Num::~Num()
{
	if (num)
		delete[] num;
}


void Num::operator=(const Num &Num1)
{
	N = Num1.N;
	for (int i=0; i<N; i++)
		num[i] = Num1.num[i];
}

void Num::operator*=(const Num &Num1)
{
	Num mul;
	for (int num1_i=0; num1_i < Num1.N; num1_i++)
	{
		for (int this_i=0; this_i < N; this_i++)
		{
			mul.num[this_i + num1_i] += 
				(*this).num[this_i] * Num1.num[num1_i];
		}
		mul.N = num1_i + N;
	}
	mul.carry();
	(*this) = mul;
}

void Num::operator/=(int d)
{
	Num div;
	int pos = N, temp = 0;

	while (pos >= 0)
	{
		if (temp < d)
		{
			if(--pos >= 0)
				temp = temp*10 + num[pos];
		}
		else
		{
			div.num[pos] = temp/d;
			if (!div.N)
				div.N = pos+1;
			temp %= d;
		}
	}
	(*this) = div;
}

void Num::carry()
{
	int c = 0, i = 0;
	for (i=0; i<N; i++)
	{
		num[i] += c;
		c = num[i]/10;
		num[i] %= 10;
	}

	while (c > 0)
	{
		num[i] = c%10;
		i++;
		c/=10;
	}
	N = i;
}
