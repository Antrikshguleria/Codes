#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

bool check(int n)
{
    if(n<1) return false;
    string x=to_string(n);
    bool flag=true;
    for( int i=0 ; i< x.size() ; i++)
    {
       if( x[i]!='0' && x[i]!='1') flag=false;
    }
    return flag;
}

int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        int n;
        cin>>n;
        if(check(n)) 
        {
            cout<<"YES"<<endl;
            continue;;
        }
        while( n>1 )
        {
            // if( n%11==0 )n=n/11;
            // if(check(n))
            // {
            //     cout<<"YES"<<endl;
            //     break;
            // }
            
        }
        if( n< 1) cout<<"NO"<<endl;
    }
}