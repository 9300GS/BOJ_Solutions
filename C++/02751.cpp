#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, temp;
    vector<int> list;
    
    cin >> n;

    for (int i=0; i<n; i++)
    {
        cin >> temp;
        list.push_back(temp);
    }

    sort(list.begin(), list.end());

    for (int i=0; i<n; i++)
    {
        cout << list[i] << "\n";
    }
    
    return 0;
}