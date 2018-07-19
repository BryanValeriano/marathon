#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    map<string,string>gems;
    gems["purple"]="Power"; 
    gems["green"]="Time"; 
    gems["blue"]="Space"; 
    gems["orange"]="Soul"; 
    gems["red"]="Reality"; 
    gems["yellow"]="Mind"; 
    
    int n; cin >> n;
    string aux;
    for(int i = 0; i < n; i++)
    {
        cin >> aux;
        gems[aux].clear();
    }

    cout << 6 - n << endl;

    for(map<string,string>::iterator it = gems.begin(); it != gems.end(); ++it)
    {
        if(it->second != "") cout << it->second << endl;
    }

    
    
    return 0;
}

