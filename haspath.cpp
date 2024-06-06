#include <iostream>
#include <queue>
using namespace std;

void isconnected(int **edges, int n, bool *visited, int start)
{
    visited[start] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == start)
        {
            continue;
        }
        if (edges[start][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            isconnected(edges, n, visited, i);
        }
    }
}

vector<int> *getpathbfs(int **edges, int n, int start, int end)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    queue<int> pendingvertices;
    pendingvertices.push(start);
    visited[start] = true;
    bool done = false;
    unordered_map<int, int> helper;
    while (!pendingvertices.empty() && !done)
    {
        int currentvertice = pendingvertices.front();
        pendingvertices.pop();
        for (int i = 0; i < n; i++)
        {
            if (edges[currentvertice][i] == 1 && !visited[i])
            {
                pendingvertices.push(i);
                helper[i] = currentvertice;
                if (i == end)
                {
                    // helper[i]=end;
                    // ans.push_back(i);
                    done = true;
                    break;
                }
            }
        }
    }
    if (!done)
        return NULL;
    int current = end;
    vector<int> *ans = new vector<int>();
    ans->push_back(current);
    while (current != start)
    {
        current = helper[current];
        ans->push_back(current);
    }
    return ans;
}

vector<int> *getpathdfs(int **edges, int n, bool *visted, int start, int end)
{

    if (start == end)
    {
        vector<int> *ans = new vector<int>();
        ans->push_back(start);
        return ans;
    }
    visted[start] = true;
    for (int i = 0; i < n; i++)
    {
        if (edges[start][i] && !visted[i])
        {
            vector<int> *smalloutput = getpathdfs(edges, n, visted, i, end);
            if (smalloutput != NULL)
            {
                smalloutput->push_back(start);
                return smalloutput;
            }
        }
    }

    return NULL;
}

bool haspath(int **edges, int n, int sv, bool *visited, int end)
{
    visited[sv] = true;
    if (sv == end)
        return true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
            continue;
        if (edges[sv][i] == 1)
        {
            if (visited[i])
                continue;
            return haspath(edges, n, i, visited, end);
        }
    }
    return false;
}
int main()
{
    int n;
    int e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    // cout << "enter the path" << endl;
    // int sv, end;
    // cin >> sv >> end;
    // cout << haspath(edges, n, sv, visited, end);
    // int start, end;
    // cin >> start >> end;
    // vector<int> *ans = getpathdfs(edges, n, visited, start, end);
    // if (ans != NULL)
    // {
    //     for (int i = 0; i < ans->size(); i++)
    //     {
    //         cout << ans->at(i) << " ";
    //     }
    // }
    // vector<int> *ans = getpathbfs(edges, n, start, end);
    // if (ans != NULL)
    // {
    //     for (int i = 0; i < ans->size(); i++)
    //     {
    //         cout << ans->at(i) << " ";
    //     }
    // }
    isconnected(edges, n, visited, 0);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            cout << "not connected" << endl;
            return 0;
        }
    }
    cout << "connected" << endl;
    return 0;
}