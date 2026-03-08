#include <stdio.h>

int main() {
    int t;
    scanf("%d",&t);

    while(t--) {
        int n;
        scanf("%d",&n);

        long long sum = 0, x;
        long long minOdd = 1000000000;

        for(int i=0;i<n;i++) {
            scanf("%lld",&x);
            sum += x;

            if(x % 2 == 1 && x < minOdd)
                minOdd = x;
        }

        if(sum % 2 == 1)
            printf("%lld\n",sum);
        else {
            if(minOdd == 1000000000)
                printf("-1\n");
            else
                printf("%lld\n",sum - minOdd);
        }
    }

    return 0;
}
