#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    pair<int,int>winner;
    winner.first = 0;
    winner.second = 0;

    int TC, tmp1, tmp2, val1, val2;
    int aux1 = 0;
    int aux2 = 0;
    cin >> TC;
    while(TC--)
    {
        cin >> val1 >> val2;

        aux1 += val1;
        aux2 += val2;
        tmp1 = aux1 - aux2;
        tmp2 = aux2 - aux1;

        //cout << tmp1 << " " << tmp2 << endl;

        if(tmp1 > winner.first && tmp1 > tmp2)
        {
            winner.first = tmp1;
            winner.second = 1;
        }
        else if(tmp2 > winner.first)
        {
            winner.first = tmp2;
            winner.second = 2;
        }
    }

    cout << winner.second << " " << winner.first <<  endl;

    return 0;
}

