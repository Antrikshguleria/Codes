#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        string insert=".";
        bool c1=false,v=false,c2=false,helper=false,helper2=false;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i]=='b' || s[i]=='c' || s[i]=='d')
            {
                if(c1==false) c1=true;
                else if(c1==true && c2==false) c2=true;
                else if(c1==true && c2==true) helper2=true;
            }
            else if(s[i]=='a' || s[i]=='e')
            {
                if(v==false) v=true;
                else if(v==true) helper=true;
            }
            if(c1==true && v==true && c2==true && helper==true)
            {
                s.insert(i-1,insert);
                v=false;
                helper=false;
                c2=false;
            }
            else if(c1==true && v==true && c2==true && helper2==true)
            {
                s.insert(i,insert);
                c1=false;
                v=false;
                c2=false;
                helper2=false;
            }
        }
        cout<<s<<endl;
    }
}