
/*
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        int i;
        vector<int> shuffled;
        for (i = 0; i < n; i++)
        {
            shuffled.push_back(nums[i]);
            shuffled.push_back(nums[n+i]);
        }
        return shuffled;
    }
};