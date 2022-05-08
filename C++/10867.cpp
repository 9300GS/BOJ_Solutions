#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<int> list;

    cin >> n;

    for(int i=0;i<n;i++)
    {
        int temp;
        cin >> temp;
        list.push_back(temp);
    }

    sort(list.begin(), list.end());
    vector<int>::iterator it = unique(list.begin(), list.end());
    list.erase(it, list.end());

    for(int i=0;i<list.size();i++)
    {
        cout << list[i] << " ";
    }
    cout << "\n";
    
    return 0;
}