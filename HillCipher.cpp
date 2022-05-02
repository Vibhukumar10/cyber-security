#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> multiply(vector<vector<int>> m1,vector<int> m2,int n)
    {
        vector<int> res(m1.size(),0);

        for(int i=0;i<m2.size();i++)
        {
            for(int j=0;j<m1.size();j++)
            {
                res[i]=(res[i]+(m2[j]*m1[i][j]));
            }
        }

        return res;
    }

    string hill(vector<vector<int>> matrix, vector<int> text)
    {
        int n=matrix.size();
        vector<int> mul=multiply(matrix,text,n);
        cout<<"\n\nAfter Multiplication: \n";
        for(int i=0;i<mul.size();i++)
        {
            cout<<mul[i]<<"\n";
        }

        cout<<"\n\nAfter Multiplication mod 26: \n";
        string encryption="";
        for(int i=0;i<mul.size();i++)
        {
            mul[i]=mul[i]%26;
            encryption+=mul[i]+'a';
            cout<<mul[i]<<"\n";
        }
        return encryption;
    }

};

int main()
{
    cout<<"Enter dimensions of the matrix: ";
    int n;
    cin>>n;
    string key,plaintext;
    cout<<"Enter plaintext: ";
    cin>>plaintext;
    cout<<"Enter key: ";
    cin>>key;

    int keyit=0;
    vector<vector<int>> matrix(n, vector<int> (n,0));
    vector<int> text(n,0);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            matrix[i][j]=key[keyit++]-'a';
        }
    }

    cout<<"\n\nKey Matrix: \n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<matrix[i][j]<<" ";
        cout<<"\n";
    }

    cout<<"\n\nPlaintext Matrix: \n";
    for(int i=0;i<n;i++)
    {
        text[i]=plaintext[i]-'a';
        cout<<text[i]<<"\n";
    }

    Solution obj;
    string encrypted=obj.hill(matrix,text);
    cout<<"\n\nEncrypted string: "<<encrypted;
    return 0;
}