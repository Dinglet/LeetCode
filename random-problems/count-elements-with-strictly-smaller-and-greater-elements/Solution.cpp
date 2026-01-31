// https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/

#include <vector>

using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums) {
        if (nums.size() <= 2)
            return 0;
        int min_element = nums[0], max_element = nums[0];
        int count_min = 1, count_max = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < min_element) {
                // update min
                min_element = nums[i];
                count_min = 1;
            } else if (nums[i] == min_element) {
                count_min++;
            }
            if (nums[i] > max_element) {
                // update max
                max_element = nums[i];
                count_max = 1;
            } else if (nums[i] == max_element) {
                count_max++;
            }
        }
        return min_element == max_element ? 0 : nums.size() - count_min - count_max;
    }
};
