#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, c;
vector<ll> x;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;

    ll temp;
    for(ll i=0;i<n;i++)
    {
        cin >> temp;
        x.push_back(temp);
    }
    sort(x.begin(), x.end());

    ll max_dist = x.back() - x.front(), min_dist = 1, result;
    while(min_dist <= max_dist)
    {
        ll s = 0;
        ll mid = (min_dist + max_dist) / 2;

        ll last_pos = x.front();
        ll cnt = 1;
        for(ll i=1;i<x.size();i++)
        {
            if(cnt >= c) break;
            if(x[i] - last_pos < mid) continue;
            else
            {
                last_pos = x[i];
                cnt++;
            }
        }

        if(cnt >= c)
        {
            result = mid;
            min_dist = mid + 1;
        }
        else //(cnt < c)
        {
            max_dist = mid - 1;
        }
    }

    cout << result << "\n";

    return 0;
}