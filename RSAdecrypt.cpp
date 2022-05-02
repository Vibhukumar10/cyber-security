#include <bits/stdc++.h>

using namespace std;




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
unordered_map<int, int> primeFactors(int n)
{
    unordered_map<int, int> umap;
    int c=2;
    while(n>1)
    {
        if(n%c==0){
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
int phi(int n)
{
    bool prime = isPrime(n);
    int sum =1;
    if(prime)
    {
        cout<<"phi("<<n<<") = "<<n-1<<endl;
        cout<<"Because "<<n<<" is a Prime No."<<endl;
        sum = n-1;
    }
    else{
        unordered_map<int, int> umap = primeFactors(n);
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
    return sum;
}

int mmi(int a,int n)
{
    int x;
    x = 1;
    bool flag = true;
    while(flag)
    {
        cout<<"\nx = "<<x<<endl;
        int temp = (a*x)%n;
        cout<<a<<"*"<<x<<" mod "<<n<<" ="<< temp;
        if(temp == 1)
            flag = false;
        else
        { 
            cout<<temp <<" != "<<1;
            x++;
        }
        cout<<"\n-----------------------------";
    }
    cout<<"\nans = "<<x;
    return x;
}

int main()
{
    int len;
    cout<<"Enter number of terms: ";
    cin>>len;
    int arr[len];
    for(int i=0;i<len;i++)
        cin>>arr[i];
    int m,db,nb,eb;
    cout<<"ENter eb, nb: ";
    cin>>eb>>nb;
    int ph = phi(nb);
    cout<<"MMI :"<<endl;
    db = mmi(eb,ph);

    unordered_map<int,char> mp;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    for(int i=0;i<26;i++)
        mp[i] = alpha[i];
    string str;
    int results[len];
    for(int i=0;i<len;i++)
    {
        cout<<"For Letter :: "<<arr[i]<<" :: ->\n";
        cout<<arr[i]<<" "<<db<<" "<<nb<<endl;
        results[i] = result(arr[i],db,nb);
        cout<<"\n+++++++++++++++++++++\n";
    }

    
    cout<<"\nPLANE-TEXT\t|\tDECRIPTION\t|\tRESULT\t|ALPHABET\t|\n";
    for(int i=0;i<len;i++)
    {
        cout<<"PT( "<<arr[i]<<" )\t|\t";
        cout<<arr[i]<<"^"<<db<<" = mod "<<nb<<"\t|\t";
        cout<<results[i]<<"\t|\t";
        cout<<mp[results[i]]<<"\t\n";
        str= str+mp[results[i]];
        cout<<"\n------------------------------------------------------------\n";
    }
    cout<<"PLANE-TEXT : "<<str;
    return 0;
}