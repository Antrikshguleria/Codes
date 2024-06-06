#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n ; i++)
    {
        int x;
        cin>>x;
        int sum=0;
        for(int j=0;j<x;j++)
        {
            int input;
            cin>>input;
            sum+=input;
        }
        float check=pow(sum,0.5);
        if(check==(int)check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}