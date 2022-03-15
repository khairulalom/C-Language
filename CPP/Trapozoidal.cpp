#include<bits/stdc++.h>
using namespace std ;
double data[7][7];
double fnc(double x)
{
    return ;
}
double Trapozoidal(double h)
{
    double value=0;
    int n=0.6/h;
    for(int i=0;i<n;i++)
    {
        if(i==0 || i==(n-1))
            value+=fnc(i*h);
        else
        {
            value+=2*fnc(i*h);
        }

    }
    return value*(h/2);
}
int main()
{
   double h;
   for(int i=0;i<2;i++)
   {
      cout<<"Stepsize"<<i<<" :";
       cin>>h;
       cout<<Trapozoidal(h)<<endl;
   }
   return 0;

}
