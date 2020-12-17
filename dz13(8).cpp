#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ifstream file1("f.txt");
	string str, strAll;

	for (file1 >> str; !file1.eof(); file1 >> str)
	{
		strAll += str + " ";
	}

	int len = strAll.length();
	
	string newStr;
	for (int index1 = 0; index1 < len; ++index1)
	{
		int counter = 0;
		for (int index2 = 0; index2 < index1; ++index2)
		{
			if (strAll[index1] != strAll[index2])
			{
				counter += 1;
			}
		}
		if (counter == index1)
		{
			newStr += strAll[index1];
		}
	}

	ofstream file2("g.txt");
	file2 << newStr;
	file2.close();

	return 0;
}