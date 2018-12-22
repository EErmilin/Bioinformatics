#include <string>
#include <iostream>
using namespace std;

int main()
{
	string text, output;
	int k, i, j;
	int count = 0;
	int max = -1;
	cin >> text;
	cin >> k;
	for (i = 0; i < text.length() - k + 1; i++)
	{
		count = 0;
		for (j = i + 1; j < text.length() - k + 1; j++)
		{
			if (text.substr(i, k) == text.substr(j, k))
				count++;
		}
		if (count > max)
		{
			output = text.substr(i, k);
			max = count;
		}
		else if (count == max)
			output = text.substr(i, k) + " " + output;
	}
	cout << output;
	return 0;
}