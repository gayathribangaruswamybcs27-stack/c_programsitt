#include <stdio.h>

#define MOD 1000000007
#define MAX 100005

long long power2[MAX];

int main() {
    int t;
    scanf("%d", &t);

    // Precompute powers of 2
    power2[0] = 1;
    for (int i = 1; i < MAX; i++) {
        power2[i] = (power2[i-1] * 2) % MOD;
    }

    while (t--) {
        int n;
        scanf("%d", &n);

        long long A[n];
        for (int i = 0; i < n; i++) {
            scanf("%lld", &A[i]);
        }

        long long prefix = 0;
        long long ans = 0;

        for (int j = 0; j < n; j++) {
            long long contrib = (A[j] * prefix) % MOD;
            contrib = (contrib * power2[n - j - 1]) % MOD;

            ans = (ans + contrib) % MOD;

            prefix = (prefix + (A[j] * power2[j]) % MOD) % MOD;
        }

        printf("%lld\n", ans);
    }

    return 0;
}
