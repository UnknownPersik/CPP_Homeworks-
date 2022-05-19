#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
 
using namespace std;
const char check = '#';
const char uncheck = '.';
vector<string> mas;
int n,m;
void input()
{
    cin>>n>>m;
    mas.resize(n);
    for (int i=0;i<n;i++)
        cin>>mas[i];
}
struct point
{
    int x,y;
    point(){}
    point(int X, int Y)
    {
        x = X; y = Y;
    }
};
int moveX[4] = {-1,0,1,0};
int moveY[4] = {0,-1,0,1};
bool correct(int x, int y)
{
    if (x<0 || y<0)
        return false;
    if (x>=n || y>=m)
        return false;
    return true;
}
void dfs(int fx, int fy)
{
    stack<point> s;
    s.push(point(fx,fy));
    while (!s.empty())
    {
        point cur = s.top();
        s.pop();
        for (int i=0;i<4;i++)
        {
            int x = cur.x + moveX[i];
            int y = cur.y + moveY[i];
            if (correct(x,y) && mas[x][y] == check)
            {
                mas[x][y] = uncheck;
                s.push(point(x,y));
            }
        }
    }
}
void solve()
{
    int amount = 0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (mas[i][j] == check)
            {
                dfs(i,j);
                amount++;
            }
        }
    }
    cout<<amount;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    input();
    solve();
    return 0;
}
