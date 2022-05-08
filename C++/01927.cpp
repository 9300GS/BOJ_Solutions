#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<int> min_heap;
    for(int i=0;i<n;i++)
    {
        int input;
        cin >> input;

        if(input == 0)
        {
            if(!min_heap.empty())
            {
                cout << min_heap.top() * (-1) << "\n";
                min_heap.pop();
            }
            else cout << "0\n";
        }
        else
        {
            min_heap.push(input * (-1));
        }
    }

    return 0;
}