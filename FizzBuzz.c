/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    const char *FIZZ_STR = "Fizz", *BUZZ_STR = "Buzz", *FIZZBUZZ_STR = "FizzBuzz";
    const int FIZZ_SIZE = sizeof(FIZZ_STR), BUZZ_SIZE = sizeof(BUZZ_STR), FIZZBUZZ_SIZE = sizeof(FIZZBUZZ_STR);
    int i=0, remainder=0;
    *returnSize = n;
    char **returnArray = (char**) malloc(n*sizeof(char*));
    while(n--)
    {
        switch(++remainder)
        {
            case 3:
            case 6:
            case 9:
            case 12:
                returnArray[i] = (char*) malloc(FIZZ_SIZE);
                memcpy(returnArray[i], FIZZ_STR, FIZZ_SIZE);
                break;
            case 5:
            case 10:
                returnArray[i] = (char*) malloc(BUZZ_SIZE);
                memcpy(returnArray[i], BUZZ_STR, BUZZ_SIZE);
                break;
            case 15:
                returnArray[i] = (char*) malloc(FIZZBUZZ_SIZE);
                memcpy(returnArray[i], FIZZBUZZ_STR, FIZZBUZZ_SIZE);
                remainder = 0;
                break;
            default:
                returnArray[i] = (char*) malloc(11);
                sprintf(returnArray[i],"%d",i+1);
                break;
        }
        ++i;
    }
    return returnArray;
}
