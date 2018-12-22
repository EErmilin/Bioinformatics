#include <string>
#include <iostream>
using namespace std;

int main()
{
	string nPattern, rPattern;
	int i;
	cin >> nPattern;
	for (i = 0; i < nPattern.length(); i++)
	{
		switch (nPattern[i])
		{
		case 'A':
			rPattern = 'T' + rPattern;
			break;
		case 'C':
			rPattern = 'G' + rPattern;
			break;
		case 'G':
			rPattern = 'C' + rPattern;
			break;
		case 'T':
			rPattern = 'A' + rPattern;
			break;
		}
	}
	cout << rPattern << endl;
	return 0;
}