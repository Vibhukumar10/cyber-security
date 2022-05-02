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

    void getCofactor(vector<vector<int>> &A, vector<vector<int>> &temp, int p, int q, int n)
    {
        int i = 0, j = 0;
    
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (row != p && col != q)
                {
                    temp[i][j++] = A[row][col];
                    if (j == n - 1)
                    {
                        j = 0;
                        i++;
                    }
                }
            }
        }
    }

    int determinant(vector<vector<int>> &A,int n)
    {
        int D = 0; // Initialize result
 
        if (n == 1)
            return A[0][0];
    
        vector<vector<int>> temp(n, vector<int> (n,0));
    
        int sign = 1; // To store sign multiplier
    
        for (int f = 0; f < n; f++)
        {
            getCofactor(A, temp, 0, f, n);
            D += sign * A[0][f] * determinant(temp, n - 1);
    
            sign = -sign;
        }
    
        return D;
    }

    vector<vector<int>> getInverse(vector<vector<int>> key, int n)
    {
        vector<vector<int>> res(key.size(), vector<int> (key.size(),0));
        if (n == 1)
        {
            res[0][0] = 1;
            return res;
        }
    
        int sign = 1;
        vector<vector<int>> temp(n,vector<int> (n,0));
    
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                getCofactor(key, temp, i, j, n);
                sign = ((i + j) % 2 == 0)? 1: -1;
                res[j][i] = (sign)*(determinant(temp, n-1));
            }
        }

        cout<<"\n\nAdjoint Matrix: \n";
        for(int i=0;i<res.size();i++)
        {
            for(int j=0;j<res.size();j++)
                cout<<res[i][j]<<" ";
            cout<<"\n";
        }

        return res;
    }

    int mmi(int a,int n)
    {
        int x = 1;
        bool flag = true;
        int round=n;
        for(int i=1;;i++)
        {
            if(i>=round)
            {
                return 0;
            }
            int temp = (a*x)%n;
            if(temp == 1)
                break;
            else
            {
                x++;
            }
        }
        return x;
    }

    string dehill(vector<vector<int>> key,vector<int> text)
    {
        vector<vector<int>> inverse=getInverse(key,key.size());
        int det=determinant(key,key.size());
        cout<<"\n\nInverse: (1/"<<det<<") * \n";
        int MMI=mmi(abs(det),26);

        for(int i=0;i<inverse.size();i++)
        {
            for(int j=0;j<inverse.size();j++)
                cout<<inverse[i][j]<<" ";
            cout<<"\n";
        }

        cout<<"\n\nMMI(det,26): "<<MMI;

        cout<<"\n\nAfter MMI: \n";
        for(int i=0;i<inverse.size();i++)
        {
            for(int j=0;j<inverse.size();j++)
            {
                if(det<0)
                {
                    inverse[i][j]=-1*MMI*inverse[i][j];
                    inverse[i][j]=inverse[i][j]%26;
                }
                else
                {
                    inverse[i][j]=(inverse[i][j]*MMI)%26;
                }

                if(inverse[i][j]<0)
                    inverse[i][j]+=26;
                cout<<inverse[i][j]<<" ";
            }
            cout<<"\n";
        }

        return hill(inverse,text);
    }

};

int main()
{
    cout<<"Enter dimensions of the matrix: ";
    int n;
    cin>>n;
    string key,ciphertext;
    cout<<"Enter ciphertext: ";
    cin>>ciphertext;
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

    cout<<"\n\Ciphertext Matrix: \n";
    for(int i=0;i<n;i++)
    {
        text[i]=ciphertext[i]-'a';
        cout<<text[i]<<"\n";
    }

    Solution obj;
    string decrypted=obj.dehill(matrix,text);
    cout<<"\n\nDecrypted string: "<<decrypted;

    return 0;
}