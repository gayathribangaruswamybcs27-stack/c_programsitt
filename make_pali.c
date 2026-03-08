#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        char s[100005];
        int freq[26] = {0};

        scanf("%d", &n);
        scanf("%s", s);

        for(int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }

        int odd = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] % 2 != 0)
                odd++;
        }

        int cost = 0;
        if(odd > 1)
            cost = odd - 1;

        printf("%d\n", cost);
    }

    return 0;
}
