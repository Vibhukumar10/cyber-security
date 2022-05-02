#include <bits/stdc++.h>
using namespace std;
 
unordered_map<int, int> primeFactors(int n)
{
    unordered_map<int, int> umap;
    int c=2;
    while(n>1)
    {
        if(n%c==0)
        {
            umap[c]++;
            n/=c;
        }
        else c++;
    }
    return umap;
}
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    bool prime = isPrime(n);
    if(prime)
    {
        cout<<"phi("<<n<<") = "<<n-1<<endl;
        cout<<"Because "<<n<<" is a Prime No."<<endl;
    }
    else
    {
        unordered_map<int, int> umap = primeFactors(n);
        int sum =1;
        cout<<n<<" = ";
        for (auto x : umap)
            cout << x.first << "^" << x.second <<" + ";
        cout<<"\nphi("<<n<<") = ";
        for (auto x : umap)
            cout << "( "<<x.first << "^" << x.second <<" - "<<x.first << "^" << x.second-1 <<" ) * ";
        cout<<"\nphi("<<n<<") = ";
        for (auto x : umap)
            {int temp =pow(x.first,x.second)- pow(x.first,x.second-1);
            sum = sum*temp;}
        cout<<sum<<endl;
        cout<<"Because "<<n<<" is a Composite No."<<endl;
    }
    
}