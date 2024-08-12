#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 9

int T, N, num, ans = 0, sum = 0;
int arr[MAX_N];
bool arr_used[MAX_N];
int Exp[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
int Factorial[10] = { 0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

void init() {
	for (int i = 0; i < MAX_N; ++i) {
		arr_used[i] = false;
	}
	ans = 0;
	sum = 0;
}


void bt1(int idx, int left_sum, int right_sum) {
	if (idx >= N) {
		ans += 1;
		return;
	}

	if (left_sum >= sum - left_sum) {
		ans += (Exp[N-idx]* Factorial[N-idx]);
		return;
	}

	for (int i = 0; i < N; ++i) {
		if (!arr_used[i]) {
			arr_used[i] = true;
			bt1(idx + 1, left_sum+arr[i], right_sum);
			if (left_sum >= right_sum + arr[i]) bt1(idx + 1, left_sum, right_sum + arr[i]);
			arr_used[i] = false;
		}
	}
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		init();
		cin >> N;
		for (int i = 0; i < N; ++i) {
			cin >> arr[i];
			sum += arr[i];
		}
		bt1(0, 0, 0);
		cout << "#" << t << " " << ans << '\n';
	}



	return 0;
}
