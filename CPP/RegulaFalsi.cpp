#include<bits/stdc++.h>
#define F1(x) 3*x-exp(-x)
#define F2(x) x*x*x*x*x-x-1
#define F3(x) (2*cos(3*x))-exp(-x)
#define F4(x) x*x-9
#define MAX_ERR 0.0005
using namespace std;
double fnc(double x)
{
    return F4(x);
}
void FalsePosition()
{
    int step=0;
    double l,u,r,ERR,rold;
    cout<<"Initial Value : ";
    cin>>l>>u;
    if((fnc(l)*fnc(u))>0)
    {
        cout<<"Root not Exits!"<<endl;
        return;
    }
    ERR=100;
    r=u;
    while(1)
    {
        cout<<step<<"\t"<<l<<"\t"<<u<<"\t"<<r<<"\t"<<ERR<<endl;
        step++;
        rold=r;
        r=u-((fnc(u)/(fnc(l)-fnc(u)))*(l-u));
        if(fnc(r)==0)
            break;
        if(fnc(r)>0)
        {
            u=r;
        }else
        {
            l=r;
        }
        ERR=(1-(rold/r));
        if(r==rold)
            break;

    }
    cout<<"approxRoot: "<<r<<endl;
    cout<<"No.ofSteps: "<<step<<endl;
    return;

}
int main()
{
    FalsePosition();
    return 0;
}

