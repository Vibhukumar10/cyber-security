#include <bits/stdc++.h>
using namespace std;

int result(int x,int y,int n)
{
    int PR=x;
        int PRprev=x;
        int rounds=y;
        cout<<"|\tRounds\t|\tPR\t|\tPR(mod n)\t|\n";
        cout<<"-------------------------------------------\n";
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
            cout<<"--------------------------------------\n";
            PR=PR%n;
            PRprev=PR;
        }
        // cout<<"\n\nFinal Answer: "<<PR;
    return PR;
}

int main()
{
    int eb,qb,pb;
    string str;
    cout<<"Enter pb, qb, eb: ";
    cin>>pb>>qb>>eb;
    cout<<"Enter str: ";
    cin>>str;
    int len = str.length();
    int arr[len];
    unordered_map<char,int> mp;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    for(int i=0;i<26;i++)
        mp[alpha[i]] = i;
    for(int i=0;i<len;i++)
    {
        arr[i]=mp[str[i]];
    }
    int nb = pb*qb;
    
    int results[len];
    for(int i=0;i<len;i++)
    {
        cout<<"\nFor Letter :: "<<arr[i]<<" :: -> \n";
        results[i] = result(arr[i],eb,nb);
        cout<<results[i]<<" \n";
        cout<<"\n+++++++++++++++++++++\n";
    }

    cout<<"RESULT:\n";
    cout<<"CIPHER\t|\tENCRYPTION\t|\tRESULT\n";
    for(int i=0;i<len;i++)
    {
        cout<<"C( "<<str[i]<<" )\t|\t";
        cout<<arr[i]<<"^"<<eb<<" = mod "<<nb<<"\t|\t";
        cout<<results[i]<<"\t|";
        cout<<"\n----------------------------------\n";
    }
    cout<<"RESULT: ";
    for(int i=0;i<len;i++)
    {
        cout<<results[i]<<" ";
    }
    return 0;
}