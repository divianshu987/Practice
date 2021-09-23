#include<bits/stdc++.h>
using namespace std;
#define int long long
void code() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int32_t main() {
    code();
    int n;
    cin >> n;
    int start_time, end_time;
    int time_period[24] = {0};
    while (cin >> start_time) {
        cin >> end_time;
        time_period[start_time]++;
        time_period[end_time]--;
    }
    int count = 0;
    for (int i = 0; i < 24; ++i) {
        count += time_period[i];
        time_period[i] = n - count;
    }
    int optimal_time = -1;
    int max_people = n + 1;
    for (int i = 0; i < 24; ++i) {
        if (max_people > time_period[i]) {
            optimal_time = i;
            max_people = time_period[i];
        }
    }
    max_people = n - max_people;
    cout << "We should host our event between " << optimal_time << ":00 and " << optimal_time + 1 << ":00" << '\n';
    return 0;
}
