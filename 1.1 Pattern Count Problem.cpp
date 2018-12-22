#include <string>
#include <iostream>
using namespace std;

int main() {
	int count = 0;
	int patternPos = 0;
	int pos = 0;
	string pattern;
	string genome;
	cin >> pattern;
	cin >> genome;
	while ((patternPos = genome.find(pattern, pos)) != string::npos)
	{
		count++;
		pos = patternPos + 1;
	}
	cout << count;
}