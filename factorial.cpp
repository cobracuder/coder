/*factorial*/
#include<bits/stdc++.h>
using namespace std;
int factorial(int val)
{
    if(val==1 or val ==0)
    return 1;
    return val*factorial(val-1);
}
int main()
{
    cout<<"\n Enter the number for factorial: ";
    int num;
    cin>>num;
    cout<<factorial(num);
}

