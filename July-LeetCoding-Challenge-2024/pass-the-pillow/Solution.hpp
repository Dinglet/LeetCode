class Solution
{
public:
    /**
     * Constraints:
     * - '2 <= n <= 1000'
     * - '1 <= time <= 1000'
     */
    int passThePillow(int n, int time)
    {
        // (1 -> ... -> n -> ... -> 1) takes 2 * (n-1) seconds
        time %= 2 * (n - 1);

        if (time <= n - 1)
            return 1 + time;
        // else
        time -= n - 1;
        return n - time;
    }
};