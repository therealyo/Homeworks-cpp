#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

void createToupper(vector<string>& words);
void printSentense(vector<string>& words);
void toWords(vector<string>& words, string row);

int main()
{
	cout << "Input row: ";
	string row;
	getline(cin, row);

	vector<string> words(0);
	toWords(words, row);
	createToupper(words);
	printSentense(words);

	return 0;
}


void createToupper(vector<string>& words)
{
	for (int index1 = 0; index1 < words.size(); ++index1)
	{
		if (index1 != words.size()-1)
		{
			if ((words[index1] == "die") | (words[index1] == "der") | (words[index1] == "das"))
			{
				char firstLetter = (char)toupper(words[index1 + 1][0]);
				words[index1+1][0] = firstLetter;
			}
		}
	}
}

void printSentense(vector<string>& words)
{
	for (int index = 0; index < words.size(); ++index)
	{
		cout << words[index] << " ";
	}
	cout << endl;
}

void toWords(vector<string>& words, string row)
{
	auto pos1 = row.find(" ");
	int step = 1;
	for (int index = pos1 + 1; index < row.length(); ++index)
	{
		if ((char)row[index] != ' ')
		{
			step = index - pos1;
			break;
		}
	}
	if (pos1 != string::npos)
	{
		words.push_back(row.substr(0, pos1));
	}
	auto pos2 = row.find(" ");
	if (pos2 != string::npos)
	{
		toWords(words, row.substr(pos1 + step));
	}
	else
	{
		words.push_back(row.substr(pos1 + step));
	}
}