#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n;

    vector<ll> budgets;
    ll min_bud = 0, max_bud = 0;
    for(ll i=0;i<n;i++)
    {
        ll input;
        cin >> input;
        budgets.push_back(input);

        max_bud = max(max_bud, input);
    }

    cin >> m;

    ll s = 0;
    while(min_bud <= max_bud)
    {
        ll mid = (min_bud + max_bud) / 2;
        ll sum = 0;
        for(ll i=0;i<n;i++)
        {
            sum += min(budgets[i], mid);
        }

        if(sum <= m)
        {
            s = mid;
            min_bud = mid + 1;
        }
        else
        {
            max_bud = mid - 1;
        }
    }

    cout << s << "\n";

    return 0;
}