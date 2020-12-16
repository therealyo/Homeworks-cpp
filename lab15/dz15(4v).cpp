#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int FindBiggestEven(const vector<int> nums)
{
    int res = 0;
    bool found = false;

    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] % 2 == 0)
        {
            if(!found) 
            {
                res = nums[i];
                found = true;
            }
            else 
            {
                if(nums[i] > res) {res = nums[i];}
            }
                
        }
    }
    
    return res;
}

int FindSmallestOdd(const vector<int> nums)
{
    int res = 0;
    bool found = false;

    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] % 2 == 1)
        {
            if(!found) 
            {
                res = nums[i];
                found = true;
            }
            else 
            {
                if(nums[i] < res) 
                {
                    res = nums[i];
                }
            }
                
        }
    }

    return res;
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

    cout << FindBiggestEven(numbers) -  FindSmallestOdd(numbers) << endl;
    
    return 0;
}