#include <iostream>
#define SCALE 76

int main()
{
	int subs[SCALE+1] = {0,1,2,2,3,4}, num;
	for (int n=6; n <= SCALE; n++)
		subs[n] = subs[n-2] + subs[n-3];

	while (std::cin >> num)
		std::cout << subs[num] << std::endl;

	return 0;
}
