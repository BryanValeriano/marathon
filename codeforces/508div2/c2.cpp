#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
 
bool cmp(int a, int b) {
    return a > b;
}


int main()
{
    int n; cin >> n;
    int s1[n];
    int s2[n];
    for(int i = 0; i < n; i++) 
        cin >> s1[i];

    for(int i = 0; i < n; i++) 
        cin >> s2[i];

    sort(s1, s1 + n, cmp);
    sort(s2, s2 + n, cmp);
   
    ll score1 = 0;
    ll score2 = 0;
    int pont1 = 0;
    int pont2 = 0;
    int turno = 0;
    
    while(pont1 < n and pont2 < n) {
        if(turno == 0) {
            if(s2[pont2] >= s1[pont1])
                pont2++;
            else {
                score1 += s1[pont1];
                pont1++;
            }
        }
        else if(turno == 1) {
            if(s1[pont1] >= s2[pont2])
                pont1++;
            else {
                score2 += s2[pont2];
                pont2++;
            }
        }
        turno = 1 - turno;
    }
    while(pont1 < n) {
        if(turno == 0) { 
            score1 += s1[pont1];
            pont1++;
        }
        else if(turno == 1)
            pont1++;
        turno = 1 - turno;
    }
    while(pont2 < n) {
        if(turno == 0)
            pont2++;
        else if(turno == 1) {
            score2 += s2[pont2];
            pont2++;
        }
        turno = 1 - turno;
    }
    cout << score1 - score2 << endl;
    return 0;
}


