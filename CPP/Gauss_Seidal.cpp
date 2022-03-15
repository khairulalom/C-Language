#include<bits/stdc++.h>
#include<iostream>
#include<graphics.h>
#define ERROR 0.00000001  /// Tolerable Error...
using namespace std;
int E_mat[3][4];
long double x[2][3],xold[3];
bool dominant()
{
    int large,sum=0,even=0,odd=0,index[3];
    for(int i=0;i<3;i++){
            large=E_mat[i][0];
            index[i]=0;
            sum=large;
            for(int j=1;j<3;j++)
            {
                if(E_mat[i][j]>large)
                {
                    large=E_mat[i][j];
                    index[i]=j;
                }
                sum+=E_mat[i][j];
            }
            sum-=large;
            if(abs(sum)>large)    /// test condition 1.
                return false;


    }
    /// Test condition 2.
    if((index[0]==index[1]) || (index[1]==index[2]) || (index[0]==index[2]))
        return false;
    return true;
}

int main()
{

    /// input Section ....
    cout<<"Enter Equation "<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<"@root_eq:"<<i+1<<"> ";
        for(int j=0;j<4;j++)
           cin>>E_mat[i][j];
        cout<<endl;
    }

    /// Checking Diagonal Dominant ....
    if(!dominant())
    {
        cout<<"Unable to apply Gauss Seidal(Not diagonal dominant)..."<<endl;
        return 0;
    }
    cout<<"Gauss Seidal Applyable!...."<<endl<<"Enter initial approx. result"<<endl<<">";
    cin>>x[0][0]>>x[0][1]>>x[0][2];
    x[1][0]=x[1][1]=x[1][2]=1;    /// Assume initial Error rate ...
    xold[0]=x[0][0];
    xold[1]=x[0][1];
    xold[2]=x[0][2];
    cout<<"\tX1:"<<x[0][0]<<" Ex1:"<<x[1][0]<<"\t  X2:"<<x[0][1]<<" Ex2:"<<x[1][1]<<"\t  X3:"<<x[0][2]<<" Ex3:"<<x[1][2]<<endl;

    /// E_mat matrix column contain sequencially (a11, a12, a13 and b1) and so on ...

    while((x[1][0]>=ERROR)||(x[1][1]>=ERROR)||(x[1][2]>=ERROR))
    {

            x[0][0]=(E_mat[0][3]-(E_mat[0][1]*x[0][1])-(E_mat[0][2]*x[0][2]))/E_mat[0][0];
            x[0][1]=(E_mat[1][3]-(E_mat[1][0]*x[0][0])-(E_mat[1][2]*x[0][2]))/E_mat[1][1];
            x[0][2]=(E_mat[2][3]-(E_mat[2][0]*x[0][0])-(E_mat[2][1]*x[0][1]))/E_mat[2][2];

                for(int i=0;i<3;i++)
                {
                    x[1][i]=(x[0][i]-xold[i])/x[0][i]; /// Calculating Error
                    xold[i]=x[0][i];
                }

            cout<<"\tX1:"<<x[0][0]<<" Ex1:"<<x[1][0]<<"\tX2:"<<x[0][1]<<" Ex2:"<<x[1][1]<<"\tX3:"<<x[0][2]<<" Ex3:"<<x[1][2]<<endl;

            delay(1000);
    }



}
