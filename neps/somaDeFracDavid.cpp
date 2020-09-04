#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int mmc(long long int j, long long int k){
  return (j*k)/__gcd(j,k);
}
int main(){
    long long int a,b,c,d,x,y,yf,xf;
    cin>>a>>b>>c>>d;
    x=mmc(b,d);
    y=((a*x/b)+(c*x/d));
    yf=y/__gcd(y,x);
    xf=x/__gcd(y,x);
    cout<<yf<<" "<<xf;
}
