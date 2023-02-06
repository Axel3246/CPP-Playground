#include <iostream>
#include <unordered_map>

using namespace std;
/*
Given a roman numeral, convert it to an integer. WIP
*/

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> T = {{'I', 1},
                                      {'V', 5},
                                      {'X', 10},
                                      {'L', 50},
                                      {'C', 100},
                                      {'D', 500},
                                      {'M', 1000}};

        int sum = T[s.back()];                    // suma antes del loop
        for (int i = s.length() - 2; i >= 0; --i) // -2 por lo de arriba
        {
            if (T[s[i]] < T[s[i + 1]])
            {
                sum -= T[s[i]];
            }
            else
            {
                sum += T[s[i]];
            }
        }

        return sum;
    }
};