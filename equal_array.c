#include <stdio.h>

int main() {
    int t;
    scanf("%d",&t);

    while(t--) {
        int n,m;
        scanf("%d %d",&n,&m);

        long long A[n], B[m];

        for(int i=0;i<n;i++) scanf("%lld",&A[i]);
        for(int i=0;i<m;i++) scanf("%lld",&B[i]);

        int i=0,j=0;
        long long sumA=0,sumB=0;
        int count=0;

        while(i<n || j<m) {

            if(sumA==sumB) {
                if(sumA!=0) count++;
                if(i<n) sumA+=A[i++];
                if(j<m) sumB+=B[j++];
            }
            else if(sumA < sumB) {
                if(i<n) sumA+=A[i++];
                else break;
            }
            else {
                if(j<m) sumB+=B[j++];
                else break;
            }
        }

        if(sumA==sumB) {
            if(sumA!=0) count++;
            printf("%d\n",count);
        }
        else
            printf("-1\n");
    }

    return 0;
}
