#include <stdio.h>
#include <string.h>

#define MAXN 1005
#define MAXP 100

// store prime exponent mod 3
typedef struct {
    int p[MAXP];
} State;

State states[MAXN];
int freq[MAXN];
int stateCount = 0;

// check if two states are equal
int isEqual(State a, State b) {
    for (int i = 0; i < MAXP; i++) {
        if (a.p[i] != b.p[i]) return 0;
    }
    return 1;
}

// find index of state
int findState(State s) {
    for (int i = 0; i < stateCount; i++) {
        if (isEqual(states[i], s)) return i;
    }
    return -1;
}

// add state if not exists
int getStateIndex(State s) {
    int idx = findState(s);
    if (idx != -1) return idx;

    states[stateCount] = s;
    freq[stateCount] = 0;
    return stateCount++;
}

// factorization mod 3
void factor(int x, State *curr) {
    for (int i = 2; i * i <= x; i++) {
        int count = 0;
        while (x % i == 0) {
            count++;
            x /= i;
        }
        count %= 3;
        if (count)
            curr->p[i] = (curr->p[i] + count) % 3;
    }
    if (x > 1) {
        curr->p[x] = (curr->p[x] + 1) % 3;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    State curr;
    memset(&curr, 0, sizeof(curr));

    long long ans = 0;

    // initial empty state
    int idx = getStateIndex(curr);
    freq[idx] = 1;

    for (int i = 0; i < n; i++) {
        factor(a[i], &curr);

        int id = getStateIndex(curr);

        ans += freq[id];
        freq[id]++;
    }

    printf("%lld\n", ans);

    return 0;
}
