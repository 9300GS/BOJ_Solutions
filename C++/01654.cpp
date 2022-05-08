#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll k, n;
    cin >> k >> n;

    vector<ll> len_LAN;
    ll min_len = 1, max_len = 1;
    for(ll i=0;i<k;i++)
    {
        ll input;
        cin >> input;
        len_LAN.push_back(input);

        max_len = max(max_len, input);
    }

    ll s = 0;
    while(min_len <= max_len)
    {
        ll mid = (min_len + max_len) / 2;
        ll cnt = 0;

        for(ll i=0;i<k;i++)
        {
            cnt += len_LAN[i] / mid;
        }

        if(cnt >= n)
        {
            s = mid;
            min_len = mid + 1;
        }
        else
        {
            max_len = mid - 1;
        }
    }

    cout << s << "\n";

    return 0;
}