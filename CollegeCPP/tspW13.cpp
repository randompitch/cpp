#include <iostream>
#include <vector>
using namespace std;
#define V 8

void tsp(int graph[V][V], vector<bool>& v, int curr, int n, int count, int cost, int &res)
{
    if(count == n && graph[curr][0]){
        res = min(res, cost+graph[curr][0]);
        return;
    }
    for(int i = 0; i<n; i++){
        if(!v[i] && graph[curr][i]){
            v[i] = true;
            tsp(graph, v, i, n,count+1, cost+graph[curr][i], res);
            v[i] = false;
        }
    }
}

int main()
{
    int n = V;
    int graph[V][V] = {
        { 0, 4, 4, 5, 0, 0, 6, 0 },
        { 4, 0, 6, 0, 3, 0, 0, 1 },
        { 4, 6, 0, 0, 2, 0, 0, 0 },
        { 5, 0, 1, 0, 0, 5, 2, 0 },
        { 0, 3, 2, 0, 0, 2, 0, 2 },
        { 0, 0, 5, 0, 2, 0, 3, 4 },
        { 6, 0, 0, 2, 0, 3, 0, 7 },
        { 0, 1, 0, 0, 2, 4, 7, 0 }
    };

    vector<bool> v(n);
    for (int i = 0; i < n; i++)
        v[i] = false;
    v[0] = true;
    int ans = INT_MAX;
    tsp(graph, v, 0, n, 1, 0, ans);
    cout << "Minimum distance travlled by salesman: " << ans;
  
    return 0;
}