#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll n, m;
vector<ll> woods;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    ll temp;
    ll max_len = 0, min_len = 0;
    for(ll i=0;i<n;i++)
    {
        cin >> temp;
        woods.push_back(temp);
        max_len = max(max_len, temp);
    }

    ll result;
    while(min_len <= max_len)
    {
        ll s = 0;
        ll mid_len = (min_len + max_len) / 2;
        for(ll i=0;i<woods.size();i++)
        {
            s += max(woods[i] - mid_len, (ll)0);
        }

        if(s >= m)
        {
            result = mid_len;
            min_len = mid_len + 1;
        }
        else //(s < m)
        {
            max_len = mid_len - 1;
        }
    }

    cout << result << "\n";

    return 0;
}