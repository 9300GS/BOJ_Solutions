#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<ll> dist;
    vector<ll> price;
    for(ll i=0;i<n-1;i++)
    {
        ll d;
        cin >> d;
        dist.push_back(d);
    }
    for(ll i=0;i<n;i++)
    {
        ll p;
        cin >> p;
        price.push_back(p);
    }

    ll s = 0;
    ll min_price = price[0];
    for(ll i=0;i<n-1;i++)
    {
        min_price = min(min_price, price[i]);
        s += min_price * dist[i];
    }

    cout << s << "\n";

    return 0;
}