#include <iostream>
#include <set>
#include <iterator>

int main()
{
	int K, M, N, GETat;
	std::multiset<int> sortL;
	std::multiset<int>::iterator iter;
	std::cin >> K;

	while (K--)
	{
		sortL.clear();
		std::cin >> M >> N;
		int A[M];

		for (int i=0; i<M; i++)
		{
			std::cin >> A[i];
		}

		for (int i=0, addN=0; i<N; i++)
		{
			std::cin >> GETat;
			while (addN < GETat)
			{
				sortL.insert(A[addN]);
				addN++;
			}

			iter = sortL.begin();
			std::advance(iter, i);	// iter += i
			std::cout << *iter << std::endl;
		}

		if(K) std::cout << std::endl;
	}

	return 0;
}
