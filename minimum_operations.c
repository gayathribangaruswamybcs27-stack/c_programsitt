#include <stdio.h>

int main() {
    int t;
    scanf("%d",&t);

    while(t--) {
        int n;
        scanf("%d",&n);

        long long a, sum = 0;
        long long need = 0;

        for(int i=0;i<n;i++) {
            scanf("%lld",&a);
            sum += a;

            if(a < 0) {
                long long req = (-a + 1) / 2; // ceil(-a/2)
                need += req;
            }
        }

        if(sum > 0) {
            printf("-1\n");
            continue;
        }

        long long k = -sum;

        if(need <= k)
            printf("%lld\n",k);
        else
            printf("-1\n");
    }

    return 0;
}
