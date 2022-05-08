#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> gas_station;
    for(int i=0;i<n;i++)
    {
        int a, b;
        cin >> a >> b;
        gas_station.push_back(make_pair(a, b));
    }
    sort(gas_station.begin(), gas_station.end());

    int l, p;
    cin >> l >> p;

    priority_queue<int> fuel;
    int idx = 0;
    int s = 0;
    while(l > p)
    {
        while(idx < n && gas_station[idx].first <= p)
        {
            fuel.push(gas_station[idx].second);
            idx++;
        }

        if(fuel.empty()) break;
        p += fuel.top();
        s++;
        fuel.pop();
    }

    if(p >= l) cout << s << "\n";
    else cout << -1 << "\n";

    return 0;
}