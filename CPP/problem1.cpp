#include<bits/stdc++.h>
#define F1(x) 3*x-exp(-x)
#define F2(x) x*x*x*x*x-x-1
#define F3(x) (2*cos(3*x))-exp(-x)
#define F4(x) x*x-9
#define MAX_ERR 0.05
using namespace std;
double fnc(double x)
{
    return F4(x);
}
void FalsePosition()
{
    int step=0;
    double l,u,r,ERR,oldR;
    cout<<"Initial Value : ";
    cin>>l>>u;
    ERR=100;
    while(ERR>=MAX_ERR)
    {
        cout<<step<<"\t"<<l<<"\t"<<u<<"\t"<<r<<"\t"<<ERR<<endl;
        step++;
        oldR=u;
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
        ERR=1-oldR/r;

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
