#include<bits/stdc++.h>
using namespace std;
#define INF 100000000
#define MAX_N 8

struct point
{
    string name;
    int x;
    int y;
};
int memo[MAX_N];
double final_dis=0;
int c=0;

void solve(vector<point> pts)
{
    int n=2*pts.size();
    int min_index=0;
    int min_dis=INF;

    c++;
    for(int i=0; i<n; i++)
    {
        if(!memo[i])
        {
            for(int j=0; j<n; j++)
            {

                if(i!=j)
                {
                    int dis=0;
                    dis=abs(pts[i].x-pts[j].x)+abs(pts[i].y-pts[j].y);
                    if(dis<min_dis)
                    {
                        min_dis=dis;
                        min_index=j;
                    }
                }
                memo[i]=1;
                memo[j]=1;
            }

            final_dis+=sqrt( pow(pts[i].x-pts[min_index].x,2)+pow(pts[i].y-pts[min_index].y,2));
        }
    }
    cout<<"Case "<<c<<": "<<final_dis<<endl;
//problem: What if a same point is minimum for two or more points??
}

int main()
{
    int n;

    cin>>n;

    while(n!=0)
    {
        vector<point> points;
        point point_;
        memset(memo,0,sizeof(memo));
        final_dis=0;

        for (int i=0; i<2*n; i++)
        {

            cin>>point_.name;

            cin>>point_.x>>point_.y;
            points.push_back(point_);
        }

        cout<<"The data inputted is: "<<endl;
        for(int j=0; j<points.size(); j++)
            cout<<points[j].name<<" "<<points[j].x<<" "<<points[j].y<<endl;

        solve(points);

        cin>>n;
    }





    cout << "Hello world!" << endl;
    return 0;
}
