#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}

int main()
{
    int num1,num2;

    cout<<"\n Enter two number:";
    cin>>num1>>num2;

    cout<<"\n Number before swap:"<<num1<<"\t"<<num2;

    swap(&num1,&num2);

    cout<<"\n Number after swap:"<<num1<<"\t"<<num2;

    return 0;
}

