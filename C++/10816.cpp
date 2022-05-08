#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, temp;
    vector<int> hand;

    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> temp;
        hand.push_back(temp);
    }
    sort(hand.begin(), hand.end());
    
    cin >> m;
    for(int i=0;i<m;i++)
    {
        cin >> temp;
        cout << upper_bound(hand.begin(), hand.end(), temp) - lower_bound(hand.begin(), hand.end(), temp) << " ";
    }
    cout << "\n";

    return 0;
}