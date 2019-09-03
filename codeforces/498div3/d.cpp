#include <bits/stdc++.h>
using namespace std;

int cont(char a, char b, char c, char d) { return (a!=b)+(a!=c)+(a!=d)+(b!=c)+(b!=d)+(c!=d); }

int main() {
    const int TAM = 1e5+3;
    int n; cin >> n; 
    char a[n+3];   
    char b[n+3];   
    scanf("%s%s", a+1, b+1);
    int sum = 0;
    for(int i = 1; i+i <= n; i++) {
        int t = cont(a[i], a[n - i + 1],b[i], b[n - i + 1]);
        if(t == 3 || t == 5 && a[i] != a[n - i + 1])sum++;
        if(t == 6 || t == 5 && a[i] == a[n - i + 1])sum+=2;
    }
    cout << sum + ((n&1) && (a[(n+1)>>1] != b[(n+1)>>1])) << endl;
    return 0;
}
