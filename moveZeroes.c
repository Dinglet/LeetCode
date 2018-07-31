int *next_nonzero(int *p_current, int *p_end);
void moveZeroes(int* nums, int numsSize)
{
    int *nums_end = nums + numsSize;
    int *p_leftmost_zero, *p_fist_nonzero_after_leftmost_zero;
    
    // Setup the pointer
    p_leftmost_zero = nums;
    while(p_leftmost_zero<nums_end && *p_leftmost_zero)
    {
        ++p_leftmost_zero;
    }
    if(!(p_leftmost_zero<nums_end))
        return;
    
    // Setup the pointer
    p_fist_nonzero_after_leftmost_zero = p_leftmost_zero + 1;
    while(p_fist_nonzero_after_leftmost_zero<nums_end && *p_fist_nonzero_after_leftmost_zero == 0)
    {
        ++p_fist_nonzero_after_leftmost_zero;
    }
    if(!(p_fist_nonzero_after_leftmost_zero<nums_end))
        return;
    
    do
    {
        *p_leftmost_zero = *p_fist_nonzero_after_leftmost_zero;
        *p_fist_nonzero_after_leftmost_zero = 0;
        
        ++p_leftmost_zero;
        p_fist_nonzero_after_leftmost_zero = next_nonzero(p_fist_nonzero_after_leftmost_zero, nums_end);
    }while(p_fist_nonzero_after_leftmost_zero);
    return;
}

int *next_nonzero(int *p_current, int *p_end)
{
    while(p_current<p_end && *p_current == 0)
    {
        ++p_current;
    }
    if(!(p_current<p_end))
        return NULL;
    return p_current;
}
