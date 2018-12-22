#include <string>
#include <iostream>
#include <map>
using namespace std;

int main()
{
	int mass;
	cin >> mass;
	int aminoMass[18] = { 57, 71, 87, 97, 99, 101, 103, 113, 114, 115, 128, 129, 131, 137, 147, 156, 163, 186 };
	map<int, long> count = { { 0, 1 } };
	for (int i = 57; i <= mass; i++)
	{
		count[i] = 0;
		for (int j = 0; j < 18; j++)
		{
			if (count.find(i - aminoMass[j]) != count.end())
				count[i] += count[i - aminoMass[j]];
		}
	}

	std::cout << count[mass];
	return 0;
}