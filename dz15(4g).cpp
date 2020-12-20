#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int LengthOfTheLongestSubarray(const vector<int> nums)
{
    int length = 1;
    int max_length = 1;

    for(int i = 0; i < nums.size(); ++i)
    {
        if (nums[i + 1] > nums[i])
        {
            length++;
            if(max_length < length)
            {
                max_length = length;
            }
        }
        else
        {
            length = 1;
        }
        
    }

    return max_length;
}


int main()
{
    vector<int> numbers;
    ifstream fl("test.txt");

    while(fl)
    {
        int num;
        fl >> num;
        numbers.push_back(num);
    }

    cout << LengthOfTheLongestSubarray(numbers);

    return 0;
}