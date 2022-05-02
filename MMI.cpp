#include <iostream>
using namespace std;

int main()
{
    int a,x,n;
    x = 1;
    cout<<"inputs(a,n): ";
    cin>>a>>n;
    bool flag = true;
    int round=n;
    for(int i=1;;i++)
    {
        if(i>=round)
        {
            cout<<"\nMMI doesn't exists";
            return 0;
        }
        cout<<"\nx = "<<x<<endl;
        int temp = (a*x)%n;
        cout<<a<<"*"<<x<<" mod "<<n<<" = "<< temp;
        if(temp == 1)
            break;
        else
        { 
            cout<<" != "<<1;
            x++;
        }
        cout<<"\n-----------------------------";
    }
    cout<<"\n\nFinal Answer (MMI) = "<<x;
    return 0;
}