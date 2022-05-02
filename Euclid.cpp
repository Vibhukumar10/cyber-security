#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long int euclids(long long int a,long long int b)
    {
        cout<<"\n|\tA\t|\tB\t|\tC=A(mod B)\t|\n";
        cout<<"---------------------------------------------------------\n";
        long long int A=a,B=b;
        if(B==0)
            return a;
        
        while(B!=0)
        {
            long long int C=A%B;
            cout<<"|\t"<<A<<"\t|\t"<<B<<"\t|\t"<<A<<"%"<<B<<"="<<C<<"\t|\n";
            A=B;
            B=C;
        }
        cout<<"|\t"<<A<<"\t|\t"<<B<<"\t|\t"<<"stop"<<"\t|\n\nFinal Answer: ";

        return A;
    }
};

int main()
{
    cout<<"inputs(a,b): ";
    long long int a,b;
    cin>>a>>b;

    Solution obj;
    cout<<obj.euclids(a,b);
    return 0;
}