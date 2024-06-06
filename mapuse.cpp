#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int sumzero(int *a, int as)
{
    int count = 0;
    unordered_map<int, int> zero;
    for (int i = 0; i < as; i++)
    {
        if (zero.count(-1 * a[i]) > 0)
        {
            count += zero[-1 * a[i]];
        }
        zero[a[i]]++;
    }
    return count;
}
void printinter(int *a, int as, int *b, int bs)
{
    unordered_map<int, int> ump;
    for (int i = 0; i < as; i++)
    {
        ump[a[i]]++;
    }
    for (int i = 0; i < bs; i++)
    {
        if (ump.count(b[i]) > 0)
        {
            if (ump[a[i]] > 0)
            {
                cout << b[i] << endl;
                ump[b[i]]--;
            }
        }
    }
}
void arrayintersection(int *a, int as, int *b, int bs) // NO ||
{
    // vector<int> output;
    unordered_map<int, bool> inter;
    for (int i = 0; i < as; i++)
    {
        if (inter.count(a[i]) > 0)
        {
            continue;
        }
        for (int j = 0; j < bs; j++)
        {
            if (a[i] == b[j])
            {
                inter[a[i]] = true;
                cout << a[i] << " ";
            }
        }
    }
    // return output;
}
int maxfreqnumber(int *a, int size)
{
    int maxf = 0, maxelement = 0;
    unordered_map<int, int> maxfreq;
    for (int i = 0; i < size; i++)
    {
        maxfreq[a[i]]++;
        maxf = max(maxf, maxfreq[a[i]]);
    }
    for (int i = 0; i < size; i++)
    {
        if (maxfreq[a[i]] == maxf)
        {
            maxelement = a[i];
            break;
        }
    }
    return maxelement;
}
vector<int> removeduplicates(int *a, int size)
{
    vector<int> output;
    unordered_map<int, bool> seen;
    for (int i = 0; i < size; i++)
    {
        if (seen.count(a[i]) > 0)
        {
            continue;
        }
        seen[a[i]] = true;
        output.push_back(a[i]);
    }
    return output;
}
int main()
{
    // int a[] = {1, 2, 3, 3, 2, 1, 4, 3, 6, 5, 5};
    // vector<int> output = removeduplicates(a, 11);
    // for (int i = 0; i < output.size(); i++)
    // {
    //     cout << output[i] << endl;
    // }
    // unordered_map<string, int> ourmap;
    // pair<string, int> p("abc", 1);
    // ourmap.insert(p);
    // ourmap["def"] = 2;
    // cout << ourmap["abc"] << endl;
    // cout << ourmap.at("abc") << endl;
    // // cout << ourmap.at("ghi") << endl;
    // cout << ourmap["ghi"] << endl;
    // if (ourmap.count("ghi") > 0)
    // {
    //     cout << "ghi is present" << endl;
    // }
    // cout << "size is " << ourmap.size() << endl;
    // ourmap.erase("ghi");
    // cout << "size is " << ourmap.size() << endl;
    // int n;
    // cin >> n;
    // int a[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }
    // cout << maxfreqnumber(a, n);
    // int as;
    // cin >> as;
    // int a[as];
    // for (int i = 0; i < as; i++)
    // {
    //     cin >> a[i];
    // }
    // int bs;
    // cin >> bs;
    // int b[bs];
    // for (int i = 0; i < bs; i++)
    // {
    //     cin >> b[i];
    // }
    // vector<int> output = arrayintersection(a, as, b, bs);
    // for (int i = 0; i < output.size(); i++)
    // {
    //     cout << output[i] << " ";
    // }
    // printinter(a, as, b, bs);
    // unordered_map<string, int> ourmap;
    // ourmap["abc"] = 1;
    // ourmap["abc1"] = 2;
    // ourmap["abc2"] = 3;
    // ourmap["abc3"] = 4;
    // ourmap["abc4"] = 5;
    // ourmap["abc5"] = 6;
    // unordered_map<string, int>::iterator it = ourmap.begin();
    // while (it != ourmap.end())
    // {
    //     cout << "key :" << it->first << "  value :" << it->second << endl;
    //     it++;
    // }

    // unordered_map<string, int>::iterator it2 = ourmap.find("abc");
    // ourmap.erase(it2);
    // ourmap.erase(it2, it2 + 4);
    int as;
    cin >> as;
    int a[as];
    for (int i = 0; i < as; i++)
    {
        cin >> a[i];
    }
    cout << sumzero(a, as) << endl;
}
