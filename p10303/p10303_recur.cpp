#include <iostream>
using namespace std;

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
		void operator+=(const Num &Num1);

		friend Num operator+(const Num &Num1, const Num &Num2);
		friend Num operator*(const Num &Num1, const Num &Num2);
	private:
		void carry();
		int *num;
		int N;
};

Num* ansTb[1001] = {nullptr};

Num cntAns(int Ndnum)
{
	if (ansTb[Ndnum])
	// directly return the answer if it has been calculated
		return (*ansTb[Ndnum]);
	else
	{
		if (Ndnum == 0 || Ndnum == 1)
		{
			ansTb[Ndnum] = new Num(1);
			return (*ansTb[Ndnum]);
		}

		ansTb[Ndnum] = new Num;
		for (int i=0; i<Ndnum/2; i++)
		{
			(*ansTb[Ndnum]) += 
			cntAns(i)*cntAns(Ndnum-i-1);
		}

		(*ansTb[Ndnum]) *= 2;

		if (Ndnum%2 != 0)
	       		(*ansTb[Ndnum]) += 
			cntAns(Ndnum/2)*cntAns(Ndnum/2);

		return (*ansTb[Ndnum]);
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
	num = new int[1000]{0};
}

Num::Num(int val)
{
	N = 0;
	num = new int[1000]{0};

	while (val > 0)
	{
		num[N] = val%10;
		N++;
		val /= 10;
	}
}

Num::Num(const Num &Num1) : N(Num1.N)
{
	num = new int[1000]{0};
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

Num operator+(const Num &Num1, const Num &Num2)
{
	Num add;
	add.N = (Num1.N > Num2.N) ? Num1.N : Num2.N;
	for (int i=0; i<add.N; i++)
	{
		add.num[i] = Num1.num[i] + Num2.num[i];
	}
	add.carry();
	return add;
}

void Num::operator+=(const Num &Num1)
{
	Num add;
	N = (N > Num1.N) ? N : Num1.N;
	for (int i=0; i<N; i++)
	{
		num[i] += Num1.num[i];
	}
	carry();
}

Num operator*(const Num &Num1, const Num &Num2)
{
	Num mul;
	for (int num2_i=0; num2_i < Num2.N; num2_i++)
	{
		for (int num1_i=0; num1_i < Num1.N; num1_i++)
		{
			mul.num[num1_i + num2_i] += 
				Num1.num[num1_i] * Num2.num[num2_i];
		}
		mul.N = num2_i + Num1.N;
		mul.carry();
	}
	return mul;
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
