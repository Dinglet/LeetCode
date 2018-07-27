char* reverseString(char* s) {
    int len_s = strlen(s);
    char *reversed_string = malloc((len_s+1)*sizeof(char)), *p_reversed;
    
    p_reversed = reversed_string + len_s;
    *p_reversed-- = '\0';
    while(len_s--)
    {
        *p_reversed-- = *s++;
    }
    return reversed_string;
}
