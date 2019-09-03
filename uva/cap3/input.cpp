#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);


    cout << "25 75" << endl;
    for(int i = 0; i <= 25; i++)
    {
        for (int j = 0; j < 3; j++) 
            cout << i << " " << random()%25 << endl;    
    }
    return 0;
}

