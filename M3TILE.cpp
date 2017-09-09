#include <iostream>

using namespace std;

int main()
{
    int arr[31];

    arr[0]=1;
    arr[1]=0;
    arr[2]=3;
    arr[3]=0;

    for(int i = 4; i < 31; i++) {
        arr[i] = arr[i-2] * 4 - arr[i-4]; //this is the only line i don't get
    }

    int n;

    while(1) {
        cin >> n;

        if(n == -1) {
            break;
        }

        cout << arr[n] << endl;
    }

    return 0;
}