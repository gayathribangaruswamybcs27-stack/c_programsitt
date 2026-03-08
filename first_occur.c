#include <stdio.h>
#include <string.h>

int strStr(char *haystack, char *needle) {
    int n = strlen(haystack);
    int m = strlen(needle);

    if (m == 0) return 0; 

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        for (; j < m; j++) {
            if (haystack[i + j] != needle[j]) {
                break; // mismatch
            }
        }
        if (j == m) return i; 
    }

    return -1; // not found
}

