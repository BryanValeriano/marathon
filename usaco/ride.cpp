/*
ID: bryan_21
TASK: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
 {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
   
    int a = 1, b = 1;
    char sa[8], sb[8];
    fin >> sa;
    fin >> sb;

    for(int i = 0; sa[i] != '\0'!= '\0'; i++)
    {
        a *= sa[i] - 64;
    }
    
    for(int i = 0; sb[i] != '\0'; i++)
    {
        b *= sb[i] - 64;
    }
    a = a % 47;
    b = b % 47;

    if(a == b) fout << "GO" << endl;
    else fout << "STAY" << endl;

    return 0;
}
