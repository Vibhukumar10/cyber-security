#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int MMI(int a,int n)
    {
        int x = 1;
        int round=n;
        for(int i=1;;i++)
        {
            if(i>=round)
            {
                // cout<<"\nMMI doesn't exists";
                return 0;
            }
            // cout<<"\nx = "<<x<<endl;
            int temp = (a*x)%n;
            // cout<<a<<"*"<<x<<" mod "<<n<<" = "<< temp;
            if(temp == 1)
                break;
            else
            { 
                // cout<<" != "<<1;
                x++;
            }
            // cout<<"\n-----------------------------";
        }
        // cout<<"\n\nFinal Answer (MMI) = "<<x;
        return x;
    }


    void crt(vector<int> a,vector<int> k)
    {
        int d=1,x=0;
        cout<<"\n\nd = ";
        for(int i=0;i<k.size();i++)
        {
            cout<<k[i]<<" * "; 
            d*=k[i];
        }

        cout<<"\nd = "<<d<<"\n\n";

        vector<int> M(a.size(),0);
        for(int i=0;i<a.size();i++)
        {
            M[i]=d/k[i];
            cout<<"M"<<i+1<<" = d/k"<<i+1<<" = "<<d<<"/"<<k[i]<<" = "<<M[i]<<"\n";
        }

        cout<<"\n";

        vector<int> y(a.size(),0);
        for(int i=0;i<a.size();i++)
        {
            y[i]=MMI(M[i],k[i]);
            cout<<M[i]<<"y"<<i+1<<" ~~~ "<<"1 mod "<<k[i]<<" ---> "<<"y"<<i+1<<" = "<<y[i]<<"\n";
        }

        cout<<"\nx = (";
        for(int i=0;i<a.size();i++)
        {
            cout<<a[i]<<"*"<<M[i]<<"*"<<y[i]<<" + ";
            x+=a[i]*M[i]*y[i];
        }
        x=x%d;
        cout<<" )\n\nx = "<<x;
    }

};

int main()
{
    cout<<"number of congruences: ";
    int n;
    cin>>n;
    vector<int> a(n,0);
    vector<int> k(n,0);
    for(int i=0;i<n;i++)
    {
        cout<<"(a"<<i+1<<",k"<<i+1<<"): ";
        cin>>a[i];
        cin>>k[i];
    }
    Solution obj;
    obj.crt(a,k);
    return 0;
}