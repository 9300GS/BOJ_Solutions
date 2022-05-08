#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, temp;
    int *hand;
    
    cin >> n;
    hand = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> hand[i];
    }
    
    sort(hand, hand+n);
    
    cin >> m;
    for(int i=0;i<m;i++)
    {
        int out = 0;
        cin >> temp;
        if(binary_search(hand, hand+n, temp))
        {
            out = 1;
        }
        cout << out << " ";
    }

    delete[] hand;

    return 0;
}