//#include <bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = n;
        if(1){
            for (int div = 1; div <= n; div++) {  
                bool flag = false;
                set<string> st;
                for (int i = 0; i < n; i++) {  
                    string check = s.substr(i, div);
                    if (n % div != 0) continue;
                    if (st.find(check) != st.end()) continue;
                    else st.insert(check);
                    string news;
                    int xyz = n / div;
                    for (int j = 0; j < xyz; j++) {
                        news += check;
                    }
                    int diff = 0;
                    for (int j = 0; j < n; j++) {
                        if (s[j] != news[j]) diff++;
                        if (diff > 1) break;
                    }
                    if (diff > 1) {
                        continue;
                    } else {
                        flag = true;
                        ans = div;
                        break;
                    }
                }
                st.clear();
                if (flag) break;
            }
            cout << ans << endl;
        }
    }
}