#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
string row;

int main() {
    ios::sync_with_stdio(false);
    row; cin >> row;
    string flag = "WUB";
    size_t found;
    found = row.find(flag);
    while(found != string::npos) {
        row.replace(found, 3, " "); 
        found = row.find(flag);
    }
    found = row.find("  ");
    while(found != string::npos) {
        row.replace(found, 2, " "); 
        found = row.find("  ");
    }
    char flag2 = ' ';
    if(row[0] == flag2) row.erase(0,1);
    int fim = row.size();
    fim--;
    if(row[fim] == flag2) row.erase(fim,fim+1);

    cout << row << endl;

    return 0;
}

