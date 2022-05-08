#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<pair<int, int>> abs_min_heap;
    for(int i=0;i<n;i++)
    {
        int input;
        cin >> input;

        if(input == 0)
        {
            if(!abs_min_heap.empty())
            {
                cout << abs_min_heap.top().second*(-1) << "\n";
                abs_min_heap.pop();
            }
            else cout << "0\n";
        }
        else
        {
            abs_min_heap.push(make_pair(abs(input)*(-1), input*(-1)));
        }
    }

    return 0;
}