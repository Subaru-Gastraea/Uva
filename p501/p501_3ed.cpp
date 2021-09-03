#include <iostream>
#include <queue>

int main()
{
	int K, M, N, GETat, ADDi;
	// GETat: do GET at the # of num be added
	// ADDi: # of added num, A[ADDi] is the next num to be added
	std::cin >> K;

	while (K--)	// K case(s)
	{
		std::priority_queue<int, std::vector<int>, std::less<int>> i_lower;
		// i_lower: contains 'i+1' num, i: GET index
		// top num is what we want to GET
		std::priority_queue<int, std::vector<int>, std::greater<int>> i_upper;
	       	// contains the other num

		std::cin >> M >> N;
		int A[M];

		for (int i=0; i<M; i++)	// M ADD
		{
			std::cin >> A[i];
		}

		ADDi = 0;
		while (N--)	// N GET
		{
			std::cin >> GETat;

			// increase i by 1 before every GET
			if (ADDi == GETat)	// do not add new num
			{
				i_lower.push(i_upper.top());
				i_upper.pop();
			}
			else if (i_upper.empty() || A[ADDi] <= i_upper.top())
			{
				i_lower.push(A[ADDi]);
				ADDi++;
			}
			else
			{
				i_lower.push(i_upper.top());
				i_upper.pop();
				i_upper.push(A[ADDi]);
				ADDi++;
			}

			while (ADDi < GETat)
			{
				if (A[ADDi] >= i_lower.top())
					i_upper.push(A[ADDi]);
				else
				{
					i_upper.push(i_lower.top());
					i_lower.pop();
					i_lower.push(A[ADDi]);
				}
				ADDi++;
			}
			std::cout << i_lower.top() << std::endl;
		}

		if(K) std::cout << std::endl;
	}

	return 0;
}
