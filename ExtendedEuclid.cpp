#include <iostream>
using namespace std;

int main()
{
    int a,m;
    cout<<"inputs(a,m): ";
    cin>>a>>m;
    int q,a1,a2,a3,b1,b2,b3,t1,t2,t3;
    a1 = 1;
    a2=0;
    a3=m;
    b1=0;
    b2=1;
    b3=a;
    int flag =1;
    cout<<"\n\nQ\tA1\tA2\tA3\tB1\tB2\tB3\tT1\tT2\tT3\n";
    cout<<"-"<<"\t"<<a1<<"\t"<<a2<<"\t"<<a3<<"\t"<<b1<<"\t"<<b2<<"\t"<<b3<<"\t"<<"-"<<"\t"<<"-"<<"\t"<<"-"<<"\n";

    while(flag == 1)
    {
        q = a3/b3;
        t1 = a1-q*b1;
        t2 = a2 - q*b2;
        t3 = a3-q*b3;
        a1 = b1;
        a2=b2;
        a3=b3;
        b1=t1;
        b2=t2;
        b3=t3;
        cout<<q<<"\t"<<a1<<"\t"<<a2<<"\t"<<a3<<"\t"<<b1<<"\t"<<b2<<"\t"<<b3<<"\t"<<t1<<"\t"<<t2<<"\t"<<t3<<"\n";
        if(b3 == 0)
        {cout<<"GCD = "<<a3<<endl;
        cout<<"No inverse"<<endl;
        flag = 0;
        }
        if(b3 == 1)
        {cout<<"\n\nGCD = "<<b3<<endl;
        cout<<"inverse = "<<b2<<endl;
        flag =0;
        }
        
    }
    return 0;
}