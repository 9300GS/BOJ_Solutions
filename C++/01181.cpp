#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool dictionary(const string &a, const string &b);

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<string> list;

    cin >> n;

    for(int i=0;i<n;i++)
    {
        string temp;
        cin >> temp;
        list.push_back(temp);
    }

    sort(list.begin(), list.end(), dictionary);
    vector<string>::iterator it = unique(list.begin(), list.end());
    list.erase(it, list.end());

    for(int i=0;i<list.size();i++)
    {
        cout << list[i] << "\n";
    }

    return 0;
}

bool dictionary(const string &a, const string &b)
{
    if(a.size() != b.size())
    {
        return a.size() < b.size();
    }
    else
    {
        return a < b;
    }
}