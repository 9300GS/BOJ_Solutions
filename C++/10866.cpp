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
    deque<int> deque;
    string command_str;

    enum command_int
    { 
        command_push_front, 
        command_push_back,
        command_pop_front,
        command_pop_back, 
        command_size, 
        command_empty, 
        command_front,
        command_back
    };
    map<string, command_int> command;

    command["push_front"] = command_push_front;
    command["push_back"] = command_push_back;
    command["pop_front"] = command_pop_front;
    command["pop_back"] = command_pop_back;
    command["size"] = command_size;
    command["empty"] = command_empty;
    command["front"] = command_front;
    command["back"] = command_back;

    cin >> n;

    for(int i=0;i<n;i++)
    {
        cin >> command_str;
        int num;
        switch (command[command_str])
        {
        case command_push_front:
            cin >> num;
            deque.push_front(num);
            break;
        case command_push_back:
            cin >> num;
            deque.push_back(num);
            break;
        case command_pop_front:
            if(!deque.empty())
            {
                cout << deque.front() << "\n";
                deque.pop_front();
            }
            else
            {
                cout << -1 << "\n";
            }
            break;
        case command_pop_back:
            if(!deque.empty())
            {
                cout << deque.back() << "\n";
                deque.pop_back();
            }
            else
            {
                cout << -1 << "\n";
            }
            break;
        case command_size:
            cout << deque.size() << "\n";
            break;
        case command_empty:
            if(deque.empty())
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
            break;
        case command_front:
            if(!deque.empty())
            {
                cout << deque.front() << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
            break;
        case command_back:
            if(!deque.empty())
            {
                cout << deque.back() << "\n";
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