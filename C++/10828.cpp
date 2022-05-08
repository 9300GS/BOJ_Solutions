#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    stack<int> stack;
    string command_str;

    enum command_int
    { 
        command_push, 
        command_pop, 
        command_size, 
        command_empty, 
        command_top 
    };
    map<string, command_int> command;

    command["push"] = command_push;
    command["pop"] = command_pop;
    command["size"] = command_size;
    command["empty"] = command_empty;
    command["top"] = command_top;

    cin >> n;

    for(int i=0;i<n;i++)
    {
        cin >> command_str;
        switch (command[command_str])
        {
        case command_push:
            int num;
            cin >> num;
            stack.push(num);
            break;
        case command_pop:
            if(!stack.empty())
            {
                cout << stack.top() << "\n";
                stack.pop();
            }
            else
            {
                cout << -1 << "\n";
            }
            break;
        case command_size:
            cout << stack.size() << "\n";
            break;
        case command_empty:
            if(stack.empty())
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
            break;
        case command_top:
            if(!stack.empty())
            {
                cout << stack.top() << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
            break;
        }
    }

    return 0;
}