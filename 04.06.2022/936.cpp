#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point{
    int x;
    int y;
};

int main()
{
    int answer = 0;
    int mX, mY, n;
    double r;
    cin >> mX >> mY >> r >> n;
    vector<Point> p;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        x -= mX;
        y -= mY;
        if (sqrt(x * x + y * y) <= r)
            p.push_back(Point{ x, y });
    }
    for (Point p1 : p){
        int on = 0, left = 0, right = 0;
        for (Point p2 : p){
            int cp = p1.x * p2.y - p2.x * p1.y;
            if (cp < 0){
                left++;
            }
            else if (cp > 0){
                right++;
            }
            else
                on++;
        }
        answer = max({answer, on + left, on + right});
    }
    cout << answer;
    return 0;
}
