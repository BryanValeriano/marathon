#include <bits/stdc++.h>

int main()
{

    :

char convert(unsigned  long long int num, char* hexa)
{
    int j = 0;
    int tmp = 0;
    char hexatmp[255] = "";

    while ( num != 0 )
    {
        tmp = ( num % 16 );
        hexatmp[j] = hextable(tmp);
        num = ( num / 16 );
        j++;
    }

    invert(j, hexatmp, hexa);

}
char hextable(int tmp)
{
    if(tmp <= 9)
    {
        return 48 + tmp;;
    }
    else
    {
        switch(tmp)
        {
            case 10:
                return 'a';
                break;
            case 11:
                return 'b';
                break;
            case 12:
                return 'c';
                break;
            case 13:
                return 'd';
                break;
            case 14:
                return 'e';
                break;
            case 15:
                return 'f';
                break;
        }
    }
    abort();
}
void invert(int j, char* hexatmp,  char* hexa)
{
    int i = 0;
    j--;

    while(j >= 0)
    {
        hexa[i] = hexatmp[j];
        i++;
        j--;
    }
}
