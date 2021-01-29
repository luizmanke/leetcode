#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char * string) {

    int hash_table[128];
    memset(hash_table, 0xFF, sizeof(hash_table));
    int max_length=0, current_length=0, i=0, offset=0;

    while (*string != 0) {

        if (hash_table[*string] - offset < 0) {  // unseen character
            current_length++;
        } else {  // repeated character
            current_length = current_length - hash_table[*string] + offset;
            offset = hash_table[*string] + 1;
        }

        hash_table[*string] = i;
        if (current_length > max_length) max_length = current_length;
        string++;
        i++;
    }

    return max_length;
}

int main() {
    char * string = "aabc";
    int length = lengthOfLongestSubstring(string);
    printf("length: %d", length);
    return 0;
}
