#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    while (people.size() > 0) {
        int remain = limit - people[0];
        vector<int>::iterator ub = upper_bound(people.begin()+1, people.end(), remain);
        vector<int>::iterator lb = lower_bound(people.begin()+1, people.end(), remain);
        
        int idx = ub - lb;
        if (idx > 0) {
            people.erase(lb);
            people.erase(people.begin());
        }
        else {
            people.erase(people.begin());
        }
        ++answer;
    }
    
    return answer;
}