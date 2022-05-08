#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, target;
    int* list;

    cin >> n;
    list = new int[n];
    for(int i=0; i<n; i++)
    {
        cin >> list[i];
    }
    sort(list, list + n);
    
    cin >> m;
    for(int i=0; i<m; i++)
    {
        cin >> target;
        if(binary_search(list, list + n, target))
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }

    delete[] list;
    return 0;
}