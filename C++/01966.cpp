#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int c, n, m;

    cin >> c;

    for(int i=0;i<c;i++)
    {
        cin >> n >> m;
        queue<pair<int, int>> docs;
        vector<int> priority;
        for(int j=0;j<n;j++)
        {
            int p;
            cin >> p;
            docs.push(make_pair(p,j));
            priority.push_back(p);
        }

        sort(priority.begin(), priority.end());

        int counter = 0;
        while(true)
        {
            counter++;
            int best_priority = priority.back();
            priority.pop_back();

            pair<int, int> doc;
            while(true)
            {
                doc = docs.front();
                docs.pop();
                if(doc.first == best_priority) break;
                docs.push(doc);
            }

            if(doc.second == m)
            {
                cout << counter << "\n";
                break;
            }
        }
    }
    
    return 0;
}