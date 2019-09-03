#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int isright(int tr[3], int tr2[3], int position, int val)
{
    tr[position] += val;
    set<int> trset;
    set<int> trset2;

    for(int i = 0; i < 3; i++)
    {
        trset.insert(tr[i]);
        trset2.insert(tr2[i]);
    }
 
    if(trset.size() == 2 && trset2.size() == 2) return 1;
    else
    {
        tr[position] -= val;
        return 0;
    }
}
    
void almost(int trin1[3], int trin2[3], set<int>tr1, set<int>tr2)
{
    for(int i = 0; i < 3; i++)
    {
        if(isright(trin1, trin2, i, 1) || isright(trin1, trin2, i, -1))
        {
            cout << "ALMOST" << endl;
            return;
        }
        else if(isright(trin2, trin1, i, 1) || isright(trin2, trin1, i, -1))
        {
            cout << "ALMOST" << endl;
            return;
        }
    }

    cout << "NEITHER" << endl;

}
             

int main()
{
    ios_base::sync_with_stdio(false);

    int trin1[3];
    int trin2[3];

    set <int> tr1;
    set <int> tr2;
    
    for(int i = 0; i < 3; i++)
    {
        cin >> trin1[i];
        tr1.insert(trin1[i]);

        cin >> trin2[i];
        tr2.insert(trin2[i]);
    }
    
    if(tr1.size() == 2 && tr2.size() == 2) cout << "RIGHT" << endl;
    else if(tr1.size() == 3 && tr2.size() == 3) cout << "NEITHER" << endl;
    else almost(trin1, trin2, tr1, tr2);

    return 0;
}

