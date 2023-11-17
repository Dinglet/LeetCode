#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int countHomogenous(string s)
    {
        // for each substring of consecutive characters,
        // the number of homogenous substrings is (n * (n + 1) / 2)
        uint64_t sum = 0;
        uint64_t count = 0;

        const char *p = s.c_str();
        while (*p)
        {
            count = 0;
            while (*p == *(p + count))
            {
                sum += ++count;
            }
            

            // modulo 1000000007
            while (sum >= 1000000007)
            {
                sum -= 1000000007;
            }

            p += count;
        }
        
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    string s = "abbcccaa";
    cout << Solution().countHomogenous(s) << endl;
    return 0;
}
