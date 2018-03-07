class Solution
{
public:
    int reverse(int x)
    {
        char strInput[1+10+1];
        sprintf(strInput,"%+d", x);
        
        int len = strlen(strInput);
        // Loop for swaping
        // Odd "+120" => len=4, max(i)=1
        // Even "-1234" => len=5, max(i)=2
        for(int i=1; i<=(len-1)/2; i+=1)
        {
            strInput[i]^=strInput[len-i]^=strInput[i]^=strInput[len-i];
        }
        long int reversedX = strtol(strInput, NULL, 10);
        if(reversedX > INT_MAX || reversedX < INT_MIN)
            return 0;
        return reversedX;
    }
};
