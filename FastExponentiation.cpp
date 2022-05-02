#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void fastExponentiation(int x,int y,int n)
    {
        int binary=y;
        vector<int> bin;
        while(binary)
        {
            bin.push_back(binary%2);
            binary/=2;
        }
        reverse(bin.begin(),bin.end());
        cout<<"\n"<<y<<" = ";
        for(int x:bin)
            cout<<x<<" ";
        // int prev=0,prevPow=0,res=1;
        // vector<int> val(0,bin.size());

        // for(int i=bin.size()-1;i>=0;i--)
        // {
        //     if(bin[i]==1)
        //     {
        //         int power=bin.size()-i-1;
        //         if(prev==0)
        //         {
        //             int temp=pow(x,power);
        //             val[i]=temp%n;
        //             prev=val[i];
        //             prevPow=power;
        //         }
        //         else
        //         {
        //             int temp=pow(prev,power-prevPow);
        //             val[i]=temp%n;
        //             prev=val[i];
        //             prevPow=power;
        //         }
        //     }
        // }

        // for(int i=val.size()-1;i>=0;i--)
        // {
        //     if(val[i]!=0)
        //     {
        //         cout<<val[i]<<" ";
        //         res*=val[i]%n;
        //     }
        // }

        // cout<<"\n\nFinal Answer: "<<res;
    }
};

int main()
{
    int x,y,n;
    cout<<"input(x,y,n): ";
    cin>>x>>y>>n;
    Solution obj;
    obj.fastExponentiation(x,y,n);
    return 0;
}