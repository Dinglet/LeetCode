using System;
using System.Collections;
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        int index = 0;
        Hashtable ht = new Hashtable();
        for(index = 0; index<nums.Length; index+=1)
        {
            int couple = target-nums[index];
            if(ht.ContainsKey(couple))
            {
                return new int[]{(int)ht[couple], index};
            }
            if(!ht.ContainsKey(nums[index]))
                ht.Add(nums[index], index);
        }
        return null;
    }
}
