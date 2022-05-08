#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> jewel;
    vector<int> bag;

    for(int i=0;i<n;i++)
    {
        int m, v;
        cin >> m >> v;
        jewel.push_back(make_pair(m,v));
    }
    sort(jewel.begin(), jewel.end());

    for(int i=0;i<k;i++)
    {
        int c;
        cin >> c;
        bag.push_back(c);
    }
    sort(bag.begin(), bag.end());

    priority_queue<int> value;
    int idx = 0;
    long long s = 0;
    for(int i=0;i<k;i++)
    {
        while(idx < n && jewel[idx].first <= bag[i])
        {
            value.push(jewel[idx].second);
            idx++;
        }

        if(!value.empty())
        {
            s += (long long)value.top();
            value.pop();
        }
    }

    cout << s << "\n";

    return 0;
}