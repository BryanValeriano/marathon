#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int magic_sort(vector<int> &row)
{
    int inv = 0;
    if(row.size() == 1) return 0;

    vector<int>u1;
    vector<int>u2;

    for(int i = 0; i < row.size()/2; i++)
        u1.pb(row[i]);
    for(int i = row.size()/2; i < row.size(); i++)
        u2.pb(row[i]);

    inv += magic_sort(u1);
    inv += magic_sort(u2);

    u1.pb(INF); 
    u2.pb(INF);
    int ini1 = 0;
    int ini2 = 0;

    for(int i = 0; i < row.size(); i++)
    {
        if(u1[ini1] <= u2[ini2])
        {
            row[i] = u1[ini1];
            ini1++;
        }
        else
        {
            row[i] = u2[ini2];
            ini2++;
            inv += u1.size() - ini1 - 1;
        }
    }
    return inv;
}
    
 
int main()
{
    int n;
    cin >> n;
    vector<int> row(n);
    for(int i = 0; i < n; i++)
        cin >> row[i];
    cout << magic_sort(row) << endl;

    return 0;
}

