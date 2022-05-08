#include <iostream>

using namespace std;

int max_score[301];
int step_score[301];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    max_score[0] = step_score[0] = 0;
    for(int i=1;i<=n;i++)
    {
        cin >> step_score[i];
    }
    max_score[1] = step_score[1];
    max_score[2] = step_score[1] + step_score[2];
    
    for(int i=3;i<=n;i++)
    {
        max_score[i] = max(max_score[i-2]+step_score[i],
                    max_score[i-3] + step_score[i-1] + step_score[i]);
    }
    
    cout << max_score[n] << "\n";

    return 0;
}