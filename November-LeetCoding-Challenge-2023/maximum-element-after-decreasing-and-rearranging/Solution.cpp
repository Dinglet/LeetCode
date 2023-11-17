#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr)
    {
        // assume 1 <= arr[i] for all i
        vector<int> counts(arr.size() + 1, 0);
        for (int a : arr)
        {
            counts[min(a, (int)arr.size())]++;
        }

        int ans = 1;
        for (int n = 2; n <= arr.size(); n++)
        {
            ans = min(ans + counts[n], n);
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    // arr = [100,1,1000]
    // Output: 3
    vector<int> arr1 = {100, 1, 1000};
    cout << s.maximumElementAfterDecrementingAndRearranging(arr1) << endl;

    return 0;
}
