#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

string longestWord(vector<string> words)
{
	int maxLen = 0;
	string longWord;
	for (int index = 0; index < words.size(); ++index)
	{
		if (words[index].length() > maxLen)
		{
			longWord = words[index];
			maxLen = words[index].length();
		}
	}
	return longWord;
}

int numOfWords(vector<string> words)
{
	return words.size();
}

string sortGapsAndWords(string row)
{
	vector<string> words(0);
	toWords(words, row);
	string sortRow;
	for (int index = 0; index < words.size(); ++index)
	{
		if (words[index].length() != 1)
		{
			sortRow += words[index];
			if (index != words.size() - 1)
			{
				sortRow += " ";
			}
		}
	}
	return sortRow;
}

string sortGaps(string row)
{
	vector<string> words(0);
	toWords(words, row);
	string sortRow;
	for (int index = 0; index < words.size(); ++index)
	{
		sortRow += words[index];
		if (index != words.size() - 1)
		{
			sortRow += " ";
		}
	}
	return sortRow;
}

string newRow(string row)
{
	string newRow;
	vector<string> words(0);
	toWords(words, row);
	if (words.size() != 1)
	{
		int lenRow = 0;
		for (int index = 0; index < words.size(); ++index)
		{
			lenRow += words[index].length();
		}
		int numGaps = 80 - lenRow;
		vector<string> gaps(words.size() - 1);
		string gap;
		for (int index2 = 0; index2 < numGaps / (words.size() - 1); ++index2)
		{
			gap += " ";
		}

		for (int index = 0; index < numGaps % (words.size() - 1); ++index)
		{
			gaps[index] += ' ';
		}
		int index1 = 0;
		int index2 = 0;
		for (int index = 0; index < (2 * words.size() - 1); ++index)
		{
			if (((index + 1) % 2) == 1)
			{
				newRow += words[index1];
				++index1;
			}
			else
			{
				newRow += gap;
				if (index2 != (numGaps % (words.size() - 1)))
				{
					newRow += " ";
					++index2;
				}
			}
		}
	}
	else
	{
		newRow = row;
	}
	return newRow;
}

void toRows(vector<string>& rows, string str)
{
	auto pos1 = str.find("\n");
	if (pos1 != string::npos)
	{
		rows.push_back(str.substr(0, pos1));
	}
	auto pos2 = str.find("\n");
	if (pos2 != string::npos)
	{
		toRows(rows, str.substr(pos1 + 1));
	}
	else
	{
		rows.push_back(str.substr(pos1 + 1));
	}
}

void toWords(vector<string>& words, string row)
{
	auto pos1 = row.find(" ");
	int step = 1;
	for (int index = pos1+1; index < row.length(); ++index)
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

int main()
{
	cout << "Input row: ";
	string row;
	getline(cin, row);

	vector<string> words(0);
	toWords(words, row);

	string longWord = longestWord(words);
	cout << "The longest word: " << longWord << endl;

	int rowSize = numOfWords(words);
	cout << "Number of words: " << rowSize << endl;

	string sortGapsWords = sortGapsAndWords(row);
	cout << "Row without extra gaps and 1 letter words: " << sortGapsWords << endl;

	string sortOnlyGaps = sortGaps(row);
	cout << "Row without only extra gaps: " << sortOnlyGaps << endl;

	ifstream file1("file.txt");
	string str((std::istreambuf_iterator<char>(file1)), istreambuf_iterator<char>());
	file1.close();

	cout << "File with inserted gaps:" << endl;
	vector<string> rows(0);
	toRows(rows, str);
	for (int index = 0; index < rows.size(); ++index)
	{
		cout << newRow(rows[index]) << endl;
	}
	return 0;
}

