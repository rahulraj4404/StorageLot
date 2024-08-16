#include<bits/stdc++.h>
using namespace std;
class storage
{
    public:
        int n,m,noofdays;
        vector<vector<int>>grid;
        grid.resize(n,(m,0));
        vector<vector<int>>profit(noofdays);
    
    
    bool isspaceavailable(int length,int width,int days)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;i++)
            {
                if(grid[i][j]==0 && grid[i+length][j+width]==0)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool checkprofit(int days,int priceperday)
    {
        int totalprofit=0,profitforxdays=0;
        for(int p:profit)
        {
            totalprofit+=p;
        }
        int profitperday=totalprofit/noofdays;
        profitforxdays=priceperday*days;
        if(profitforxdays>=profitperday)
            return true;
        else
            return false;
        
    }
    bool cantakebox(int length,int width,int days,int priceperday)
    {
        if(!isspaceavailable(int length,int width))
            return false;
        if(!checkprofit(int days,int priceperday))
            return false;
    }
    int profitmade(int noofdays,int priceperday)
    {
        int totalprofitmade=priceperday*noofdays; // for a specific box 
        return totalprofitmade;
    }
    int totalprofit()
    {
        int overallprofit=0;
        for(int p:profit)
            overallprofit+=p;
        return overallprofit;   // overall profit
    }
};
int main()
{
    
}