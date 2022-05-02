#include<bits/stdc++.h>
using namespace std;

int eed(int a,int m)
{
    int q,a1,a2,a3,b1,b2,b3,t1,t2,t3;
    a1 = 1;
    a2=0;
    a3=m;
    b1=0;
    b2=1;
    b3=a;
    int flag =1;
    cout<<"q\ta1\ta2\ta3\tb1\tb2\tb3\tt1\tt2\tt3\n";
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
        return -1;
        }
        if(b3 == 1)
        {cout<<"GCD = "<<b3<<endl;
        cout<<"inverse = "<<b2<<endl;
        flag =0;
        return b2;
        }
        
    }
}

int result(int x,int y,int n)
{
    int PR=x;
        int PRprev=x;
        int rounds=y;
        cout<<"|\tRounds\t|\tPR\t|\tPR(mod n)\t|\n";
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
    return PR;
}

int main()
{
    int a,p,g,A;
    cout<<"Enter a,p,g: ";
    cin>>a>>p>>g;
    A = result(g,a,p);
    
    cout<<"\nENCRYPTION\n";
    int c1,c2,k,m;
    cout<<"Enter m, k [ 1<k<P-1] : ";
    cin>>m>>k;
    c1 = result(g,k,p);
    c2 = (m*pow(A,k));
    c2= c2%p;
    cout<<"\nC1 = "<<c1<<endl;
    cout<<"C2= "<<c2<<endl;
    
    cout<<"\nDECRYPTION\n";
    int x = result(c1,a,p);
    cout<<"X = "<<x<<endl;
    int xinv = eed(p,x);
    cout<<"X^-1 = "<<xinv<<endl;
    int d = (xinv*c2)%p;
    cout<<"Decrypted = "<<d;
}