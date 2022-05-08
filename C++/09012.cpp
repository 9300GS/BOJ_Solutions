#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i=0;i<n;i++)
    {
        string ps;
        stack<int> stack;
        cin >> ps;
        
        bool valid = true;
        for(int j=0;j<ps.size();j++)
        {
            if(ps[j] == '(') stack.push(0);
            else if(stack.size() <= 0)
            {
                valid = false;
                break;
            }
            else
            {
                stack.pop();
            }
        }
        if(stack.size() > 0) valid = false;

        if(valid) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}