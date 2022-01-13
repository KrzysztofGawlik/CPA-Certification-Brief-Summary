#include <iostream>
using namespace std;

int main(void){
   int t[] = {8,4,3,2,1}, i;
   for(i=t[4];i<t[0];i++)
    {t[i-1]=-t[3];cout << t[i-1] << endl;}
    cout << i;
    return 0;
}