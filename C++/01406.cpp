#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string text_init;
    string command_str;

    enum command_int
    { 
        command_L,
        command_D,
        command_B,
        command_P,
    };
    map<string, command_int> command;

    command["L"] = command_L;
    command["D"] = command_D;
    command["B"] = command_B;
    command["P"] = command_P;

    cin >> text_init; 
    cin >> n;

    list<char> text;
    for(int i=0;i<text_init.length();i++)
    {
        text.push_back(text_init[i]);
    }

    list<char>::iterator cursor = text.end();

    for(int i=0;i<n;i++)
    {
        cin >> command_str;
        int num;
        switch (command[command_str])
        {
        case command_L:
            if(cursor != text.begin()) cursor--;
            break;
        case command_D:
            if(cursor != text.end()) cursor++;
            break;
        case command_B:
            if(cursor != text.begin())
            {
                if(cursor != text.end())
                {
                    cursor--;
                    cursor = text.erase(cursor);
                }
                else
                {
                    text.pop_back();
                    cursor = text.end();
                }
            }
            break;
        case command_P:
            char c;
            cin >> c;
            cursor = text.insert(cursor, c);
            cursor++;
            break;
        }
    }

    int size = text.size();
    for(int i=0;i<size;i++)
    {
        cout << text.front();
        text.pop_front();
    }
    cout << "\n";

    return 0;
}