#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void exponentiation(int x,int y,int n)
    {
        int PR=x;
        int PRprev=x;
        int rounds=y;
        cout<<"\n\n|\tRounds\t|\tPR\t|\tPR(mod n)\t|\n";
        cout<<"------------------------------------------------------\n";
        for(int i=0;i<rounds;i++)
        {
            cout<<"|\t"<<i+1<<" \t|";
            if(i==0)
                cout<<"\t"<<PR<<"\t|";
            else
            {
                PR=(PRprev%n)*x;
                cout<<"\t"<<PR<<"\t|";
            }

            cout<<"\t"<<PR%n<<"\t|\n";
            cout<<"-------------------------------------------------\n";
            PR=PR%n;
            PRprev=PR;
        }
        cout<<"\n\nFinal Answer: "<<PR;
    }
};

int main()
{
    int x,y,n;
    cout<<"input(x,y,n): ";
    cin>>x>>y>>n;
    Solution obj;
    obj.exponentiation(x,y,n);
    return 0;
}