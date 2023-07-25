#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define MAX_ALPHA 10
#define MAX_LEN 9

int N, ans = 0;
string word;

int num_of_alpha[26];
vector<int> nums;

bool comp(int i1, int i2) {
    return i1 > i2;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> word;

        for (int j = 0; j < word.size(); ++j) {
            int numIdx = word.size() - j;
            int num = 1;

            for (int w = 1; w < numIdx; ++w) {
                num *= 10;
            }

            num_of_alpha[word[j]-'A'] += num;            
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (num_of_alpha[i] > 0) {
            nums.push_back(num_of_alpha[i]);
        }
    }

    sort(nums.begin(), nums.end(), comp);

    int num = 9;
    for (int i = 0; i < nums.size(); ++i) {
        ans += (nums[i]*num);
        --num;
    }

    cout << ans;

    return 0;
}