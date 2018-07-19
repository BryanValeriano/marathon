#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);

    int j = 2;
    int aux;
    for(int row = 1; row <= 7; row++)
    {
        for(int hN = 1; hN <= 4 - abs(row - 4); hN++)
        {
            cout << '#';
        }
        cout << endl;
    }

    return 0;
}

