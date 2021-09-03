#include <iostream>
#include <algorithm>

int main()
{
	int K, M, N, sortEnd, GETat;
	std::cin >> K;

	while (K--)
	{
		std::cin >> M >> N;
		int A[M];

		for (int i=0; i<M; i++)
		{
			std::cin >> A[i];
		}

		sortEnd = 0;
		for (int i=0; i<N; i++)
		{
			std::cin >> GETat;
			if (GETat > sortEnd)
			{
				std::sort(A, A+GETat);
				sortEnd = GETat;
			}
			std::cout << A[i] << std::endl;
		}

		if(K) std::cout << std::endl;
	}

	return 0;
}
