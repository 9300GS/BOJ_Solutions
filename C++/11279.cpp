#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<int> max_heap;
    for(int i=0;i<n;i++)
    {
        int input;
        cin >> input;

        if(input == 0)
        {
            if(!max_heap.empty())
            {
                cout << max_heap.top() << "\n";
                max_heap.pop();
            }
            else cout << "0\n";
        }
        else
        {
            max_heap.push(input);
        }
    }

    return 0;
}