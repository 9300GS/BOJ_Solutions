#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num_divs;
    cin >> num_divs;

    vector<int> div(num_divs);

    for(int i=0;i<num_divs;i++)
    {
        cin >> div[i];
    }

    sort(div.begin(), div.end());

    cout << div[0] * div[num_divs-1] << "\n";
    return 0;
}