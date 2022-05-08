#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    queue<int> queue;

    cin >> n;
    cin >> k;

    for(int i=1;i<=n;i++)
    {
        queue.push(i);
    }

    cout <<"<";
    while(queue.size() > 1)
    {
        for(int c=0;c<k-1;c++)
        {
            int out = queue.front();
            queue.pop();
            queue.push(out);
        }
        cout << queue.front() << ", ";
        queue.pop();
    }
    cout << queue.front() << ">\n";

    return 0;
}