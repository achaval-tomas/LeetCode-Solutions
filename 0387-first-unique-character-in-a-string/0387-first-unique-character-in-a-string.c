/* Linear RunTime Complexity */
int firstUniqChar(char * s){
    int idxs[26];
    // INTITIALIZE ARRAY OF 26 INDEXES, ONE FOR EACH CHAR.
    for (int i = 0; i<26; ++i)
        idxs[i] = 1;
    
    int len = strlen(s);
    for (int i = 0; i<len; ++i)
        // IF ITS FIRST OCCURRENCE, SET ITS CHAR-UNIQUE INDEX AT 0.
        // IF IT HAS ALREADY BEEN SET TO 0, SET TO -1.
        if (idxs[s[i]%26] > 0)
            idxs[s[i]%26] = 0;
        else if (!idxs[s[i]%26])
            idxs[s[i]%26] = -1;

    // THE FIRST INDEX HOLDING 0 WILL BE THE FIRST NON-REPEATING CHARACTER.
    for (int i = 0; i<len; ++i){
        if (idxs[s[i]%26] == 0)
            return i;
    }

    // IF LOOP DIDN'T BREAK, NOTHING WAS FOUND
    return -1;
}
