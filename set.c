#include <stdio.h>
#include <string.h>

#define MAX 105
#define LEN 105

int main() {
    int n;
    scanf("%d", &n);

    char str[MAX][LEN];
    int removed[MAX] = {0};

    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }

    // Check substring relation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && !removed[i]) {
                if (strstr(str[j], str[i]) != NULL) {
                    removed[i] = 1;
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!removed[i]) count++;
    }

    printf("%d\n", count);

    return 0;
}
