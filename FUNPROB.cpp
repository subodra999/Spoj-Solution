#include<iostream>
int main()
{
int N, M;
while(1) {
    scanf("%d %d", &N, &M);
    if (0 == N && 0 == M) break;

    if (N > M) printf("0.000000\n");
    else {
        double res = (double) (M-N+1) / (M+1);
        printf("%.6f\n", res);
    }   
}   
return 0;
}