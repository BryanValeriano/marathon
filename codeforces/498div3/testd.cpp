#include<cstdio>
int l,t,s;char a[100002],b[100002];
int cnt(int a,int b,int c,int d){return (a!=b)+(a!=c)+(a!=d)+(b!=c)+(b!=d)+(d!=c);}
int main()
{
    scanf("%d%s%s",&l,a,b);
    for(int i=0;i+i<l;i++){
      t=cnt(a[i],b[i],a[l-(i+1)],b[l-(i+1)]);
      if(t==3||t==5&&a[i]!=a[l-(i+1)])s++;
      if(t==6||t==5&&a[i]==a[l-(i+1)])s+=2;
      //printf("%d %c %c\n", t, a[i], a[l-(i+1)]);
    }
    printf("%d\n",s+((l&1)&&a[(l+1>>1) - 1]!=b[(l+1>>1) -1]));
    return 0;
}
