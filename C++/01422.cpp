#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

bool comp(const string &a, const string &b)
{
    return (a+b > b+a);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    cin >> k >> n;

    vector<string> nn;

    ll max_nn = 0;
    for(int i=0;i<k;i++)
    {
        ll input;
        cin >> input;
        max_nn = max(max_nn, input);
        nn.push_back(to_string(input));
    }
    sort(nn.begin(), nn.end(), comp);

    bool max_out = false;
    for(int i=0;i<k;i++)
    {
        if(nn[i] == to_string(max_nn) && !max_out)
        {
            for(int j=0;j<n-k+1;j++)
            {
                cout << nn[i];
            }
            max_out = true;
        }
        else cout << nn[i];
    }
    
    cout << "\n";

    return 0;
}