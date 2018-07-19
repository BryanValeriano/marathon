#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;

int numdig, uns;

int main(){
    ios_base::sync_with_stdio(false);

    int TC;
    int nums;
    cin >> TC;

    while(TC--)
    {
        cin >> numdig >> uns;
        string comb;
        for(int i = 0; i < numdig - uns; i++)
            comb += '0';
        for(int i = 0; i < uns; i++)
            comb += '1';
        do
        {
            cout << comb << endl;
        }while(next_permutation(comb.begin(), comb.end()));
        
        if(TC) cout << endl;
    }
    
    return 0;
}

