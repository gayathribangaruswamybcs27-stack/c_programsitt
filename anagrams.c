#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpChar(const void *a,const void *b)
{
    return (*(char*)a - *(char*)b);
}

char* sortString(char *s)
{
    char *temp = strdup(s);
    qsort(temp, strlen(temp), sizeof(char), cmpChar);
    return temp;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    char ***result = malloc(strsSize * sizeof(char**));
    *returnColumnSizes = malloc(strsSize * sizeof(int));

    char **keys = malloc(strsSize * sizeof(char*));
    int groupCount = 0;

    for(int i=0;i<strsSize;i++)
    {
        char *key = sortString(strs[i]);
        int found = -1;

        for(int j=0;j<groupCount;j++)
        {
            if(strcmp(keys[j], key) == 0)
            {
                found = j;
                break;
            }
        }

        if(found == -1)
        {
            keys[groupCount] = key;
            result[groupCount] = malloc(strsSize * sizeof(char*));
            result[groupCount][0] = strs[i];
            (*returnColumnSizes)[groupCount] = 1;
            groupCount++;
        }
        else
        {
            int col = (*returnColumnSizes)[found];
            result[found][col] = strs[i];
            (*returnColumnSizes)[found]++;
            free(key);
        }
    }

    *returnSize = groupCount;
    return result;
}
