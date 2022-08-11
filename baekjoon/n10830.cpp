#include <iostream>
#include <fstream>
using namespace std;

int N;
long long B;
int arr[5][5];
int arr1[5][5];
int arr2[5][5];
int result[5][5];

void output() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j]%1000 << " ";
        }
        cout << endl;
    }
}

void cal(int temp1[][5], int temp2[][5], int temp3[][5]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int m = 0; m < N; m++) {
                sum += temp1[i][m] * temp2[m][j];
            }
            temp3[i][j] = sum%1000;
        }
    }
}

void foo(long long n) {
    if (n==1) {
        copy(&arr[0][0], &arr[0][0]+25, &result[0][0]);
        copy(&result[0][0], &result[0][0]+25, &arr1[0][0]);
        return ;
    }
    if (n%2==0) {
        // c^{n/2} 구하기
        foo(n/2);
        // c^{n/2}*c^{n/2} 계산
        cal(arr1, arr1, result);
        copy(&result[0][0], &result[0][0]+25, &arr1[0][0]);
    }
    else {
        // c^{n/2}*c^{n/2}*c 로..
        // c^{n/2} 구하기
        foo((n-1)/2);
        // c^{n/2}*c^{n/2} 계산
        cal(arr1, arr1, arr2);
        // c^{n/2}*c^{n/2}*c 계산하기
        cal(arr2, arr, result);
        copy(&result[0][0], &result[0][0]+25, &arr1[0][0]);
    }
}


int main() {
    // ofstream file;
    // file.open("output.txt", ios_base::out | ios_base::app);
    // cout.rdbuf(file.rdbuf());

    // input
    scanf("%d %llu", &N, &B);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    // C^n = C^{n/2}*C^{n/2}
    foo(B);
    output();
    return 0;
}