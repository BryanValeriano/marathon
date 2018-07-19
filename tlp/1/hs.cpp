#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);

    for(int i = 5; i >= 1; i--)
    {
        for(int j = 0; j < i;j++)
        {
            cout << '#';
        }
        cout << endl;
    }
    
    return 0;
}

