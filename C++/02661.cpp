#include <iostream>
#include <vector>
using namespace std;

void recv(int digit);
bool isGoodSeq(vector<int> seq);

bool end_flag = false;
int n;
vector<int> seq;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    recv(0);

    return 0;
}

void recv(int digit)
{
    if(!isGoodSeq(seq)) return;
    if(digit == n)
    {
        end_flag = true;
        for(int i=0;i<seq.size();i++)
        {
            cout << seq[i];
        }
        cout << "\n";
        return;
    }
    for(int i=1;i<=3;i++)
    {
        seq.push_back(i);

        recv(digit+1);

        if(end_flag) return;
        seq.pop_back();
    }
    return;
}

bool isGoodSeq(vector<int> seq)
{
    for(int i=1;i<=seq.size()/2;i++)
    {
        int bad_flag = -1;
        for(int j=0;i+j<seq.size();j++)
        {
            if(seq[j] == seq[j+i])
            {
                if(bad_flag == -1) bad_flag = j+i;
                if(j+1 == bad_flag) return false;
            }
            else bad_flag = -1;
        }
    }
    return true;
}