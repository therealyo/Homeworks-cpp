#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lengthOfSentence(vector<string>& array)
{
	int len_of_sentence = 0;
	for (int index = 0; index < array.size(); ++index)
	{
		len_of_sentence += array[index].length();
	}
	return len_of_sentence;
}

void findPercent(string word, vector<string>& array, int lenSent)
{
	int lenWord = word.length();
	int countSymbol = 0;
	for (int index1 = 0; index1 < lenWord; ++index1)
	{
		countSymbol = 0;
		for (int index2 = 0; index2 < array.size(); ++index2)
		{
			for (int index3 = 0; index3 < array[index2].length(); ++index3)
			{
				if (word[index1] == array[index2][index3])
				{
					++countSymbol;
				}
			}
		}
		float symbolPercent = (float)countSymbol / lenSent * 100;
		cout << word[index1] << ": " << symbolPercent << "%" << endl;
	}
}

void toWords(vector<string>& array, string sentence)
{
	auto pos1 = sentence.find(" ");
	if (pos1 != string::npos)
	{
		array.push_back(sentence.substr(0, pos1));
	}
	auto pos2 = sentence.find(" ");
	if (pos2 != string::npos)
	{
		toWords(array, sentence.substr(pos1 + 1));
	}
	else
	{
		array.push_back(sentence.substr(pos1 + 1));
	}
}

int main()
{
	cout << "Input sentence: ";
	string sentence;
	getline(cin, sentence);

	vector<string> words(0);

	toWords(words, sentence);
	int lenSent = lengthOfSentence(words);
	for (int index = 0; index < words.size(); ++index)
	{
		cout << endl << "For word: \"" << words[index] << "\"" << endl;
		findPercent(words[index], words, lenSent);
	}

	return 0;
}
