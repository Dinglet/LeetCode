/*
Median of Two Sorted Arrays
https://leetcode.com/problems/median-of-two-sorted-arrays/description/

This code was developed base on a discussion.
url: https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2499/Share-my-simple-O(log(m+n))-solution-for-your-reference
*/
class Solution
{
public:
    int getKthLargest(int *num1, int size1, int *num2, int size2, int k)
    {
        // Make size1 >= size2
        if(size1 < size2)
            return getKthLargest(num2, size2, num1, size1, k);
        if(size2 == 0)
            return num1[k-1];
        if(k==1)
            return min(num1[0], num2[0]);

        // Get rid of k-1 smallest numbers gradually
        int i=min(size1, k/2), j=min(size2, k/2);
        if(num1[i-1] < num2[j-1])
            return getKthLargest(num1+i, size1-i, num2, size2, k-i);
        else
            return getKthLargest(num1, size1, num2+j, size2-j, k-j);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int totalSize = nums1.size() + nums2.size();
        int medianLeft = getKthLargest(nums1.data(), nums1.size(), nums2.data(), nums2.size(), (totalSize+1)/2),
            medianRight = getKthLargest(nums1.data(), nums1.size(), nums2.data(), nums2.size(), (totalSize+2)/2);
        return (medianLeft+medianRight)/2.0;
    }
};
