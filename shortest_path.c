#include<bits/stdc++.h>
using namespace std;

class dj
{
    int n, cost[20][20], d[20], p[20], v[20];
    public:
        void read_matrix();
        void short_path(int);
        void display(int);
};

void dj::read_matrix()
{
    cout<<"enter the number of nodes : ";
    cin>>n;
    cout<<"\nenter the cost matrix\n";
    for (int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>cost[i][j];
}

void dj::display(int src)
{
    int i, k;
    for(i=0; i<n; i++)
    {
        if (i==src)
            continue;
        cout<<"the shortest path from "<<src<<" to"<<i<<" is";
        k = i;
        cout<<k<<"<--";
        while (p[k] != src)
        {
            k=p[k];
            cout<<k<<"<--";
        }

        cout<<src<<endl;
        cout<<"and the distance is : "<<d[i]<<endl;
    }
}

void dj::short_path(int src)
{
    int i, j, min, u, s;
    for(i=0; i<n; i++)
    {
        d[i] = cost[src][i];
        p[i] = src;
        v[i] = 0;
    }

    for(i=0; i<n; i++)
    {
        min=99;
        u=0;
        for(j=0; j<n; j++)
        {
            if (!v[j] && d[j] < min)
            {
                min = d[j];
                u = j;
            }
        }

        v[u] = 1;
        for (s=0; s<n; s++)
        {
            if (!v[s] && d[u] + cost[u][s] < d[s])
            {
                d[s] = cost[u][s] + d[u];
                p[s] = u;
            }
        }
    }
}

int main()
{
    int source;
    dj obj;
    obj.read_matrix();
    cout<<"enter the source node : ";
    cin>>source;
    obj.short_path(source);
    obj.display(source);
    return 0;
}