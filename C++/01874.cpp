#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    stack<int> stack;
    vector<int> ans;

    cin >> n;

    int count = 1;
    for(int i=0;i<n;i++)
    {
        int in;
        cin >> in;

        while(in >= count)
        {
            stack.push(count);
            ans.push_back(1);
            count++;
        }

        int out = stack.top();
        stack.pop();
        ans.push_back(0);
        if(in != out)
        {
            cout << "NO\n";
            return 0;
        }
    }

    for(int i=0;i<ans.size();i++)
    {
        if(ans[i] == 1) cout << "+\n";
        else cout << "-\n";
    }

    return 0;
}