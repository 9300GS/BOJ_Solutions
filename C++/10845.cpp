#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    queue<int> queue;
    string command_str;

    enum command_int
    { 
        command_push, 
        command_pop, 
        command_size, 
        command_empty, 
        command_front,
        command_back
    };
    map<string, command_int> command;

    command["push"] = command_push;
    command["pop"] = command_pop;
    command["size"] = command_size;
    command["empty"] = command_empty;
    command["front"] = command_front;
    command["back"] = command_back;

    cin >> n;

    for(int i=0;i<n;i++)
    {
        cin >> command_str;
        switch (command[command_str])
        {
        case command_push:
            int num;
            cin >> num;
            queue.push(num);
            break;
        case command_pop:
            if(!queue.empty())
            {
                cout << queue.front() << "\n";
                queue.pop();
            }
            else
            {
                cout << -1 << "\n";
            }
            break;
        case command_size:
            cout << queue.size() << "\n";
            break;
        case command_empty:
            if(queue.empty())
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
            break;
        case command_front:
            if(!queue.empty())
            {
                cout << queue.front() << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
            break;
        case command_back:
            if(!queue.empty())
            {
                cout << queue.back() << "\n";
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