#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int min3(int a, int b, int c) {
    int min = a < b ? a : b;
    return min < c ? min : c;
}

int minDistance(char* word1, char* word2) {
    int n = strlen(word1);
    int m = strlen(word2);
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++)
        dp[i] = (int*)malloc((m + 1) * sizeof(int));

    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j; 


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min3(dp[i - 1][j],    // delete
                                     dp[i][j - 1],    // insert
                                     dp[i - 1][j - 1] // replace
                                    );
        }
    }

    int result = dp[n][m];
    for (int i = 0; i <= n; i++) free(dp[i]);
    free(dp);

    return result;
}
