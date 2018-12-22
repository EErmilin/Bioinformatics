#include <string>
#include <iostream>
#include <map>
using namespace std;

string transcription(string dna);
string translation(string pattern);
string reserve(string nPattern);
map<string, char> Table = { { "AAA", 'K' },{ "AAC", 'N' },{ "AAG", 'K' },{ "AAU", 'N' },{ "ACA", 'T' },{ "ACC", 'T' },{ "ACG", 'T' },{ "ACU", 'T' },{ "AGA", 'R' },{ "AGC", 'S' },{ "AGG", 'R' },{ "AGU", 'S' },{ "AUA", 'I' },{ "AUC", 'I' },{ "AUG", 'M' },{ "AUU", 'I' },
{ "CAA", 'Q' },{ "CAC", 'H' },{ "CAG", 'Q' },{ "CAU", 'H' },{ "CCA", 'P' },{ "CCC", 'P' },{ "CCG", 'P' },{ "CCU", 'P' },{ "CGA", 'R' },{ "CGC", 'R' },{ "CGG", 'R' },{ "CGU", 'R' },{ "CUA", 'L' },{ "CUC", 'L' },{ "CUG", 'L' },{ "CUU", 'L' },
{ "GAA", 'E' },{ "GAC", 'D' },{ "GAG", 'E' },{ "GAU", 'D' },{ "GCA", 'A' },{ "GCC", 'A' },{ "GCG", 'A' },{ "GCU", 'A' },{ "GGA", 'G' },{ "GGC", 'G' },{ "GGG", 'G' },{ "GGU", 'G' },{ "GUA", 'V' },{ "GUC", 'V' },{ "GUG", 'V' },{ "GUU", 'V' },
{ "UAA", ' ' },{ "UAC", 'Y' },{ "UAG", ' ' },{ "UAU", 'Y' },{ "UCA", 'S' },{ "UCC", 'S' },{ "UCG", 'S' },{ "UCU", 'S' },{ "UGA", ' ' },{ "UGC", 'C' },{ "UGG", 'W' },{ "UGU", 'C' },{ "UUA", 'L' },{ "UUC", 'F' },{ "UUG", 'L' },{ "UUU", 'F' } };


int main()
{
	string text, peptide, Code;
	cin >> text;
	cin >> peptide;
	for (int i = 0; i < text.length() - peptide.length() * 3 + 1; i++)
	{
		string rna = transcription(text.substr(i, peptide.length() * 3));
		string reserveRNA = transcription(reserve(text.substr(i, peptide.length() * 3)));
		if (peptide == translation(rna) || peptide == translation(reserveRNA))
			Code = text.substr(i, peptide.length() * 3) + "\n" + Code ;
	}
	cout << Code;
	return 0;
}

string reserve(string nPattern)
{
	string rPattern;
	int i;
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
	return rPattern;
}

string translation(string pattern)
{
	string peptide;
	for (int i = 0; i < pattern.length(); i += 3)
	{
		peptide += Table.at(pattern.substr(i, 3));
	}

	return peptide;
}

string transcription(string dna)
{
	string rna;
	for (int i = 0; i < dna.length(); i++)
	{
		if (dna[i] == 'T')
			rna.push_back('U');
		else
			rna.push_back(dna[i]);
	}
	return rna;
}
