#include <bits/stdc++.h>
using namespace std;
class store 
{
    public:
        int length, width, noofdays, rent, totalprofit;
        int area;
        vector<int> profit;
    store(int l, int w) : length(l), width(w) 
    {
        area = length * width;
        totalprofit = 0;
    }
    bool acceptbox(int length, int width, int noofdays, int rent) 
    {
        int areaofnewone = length * width;
        if (areaofnewone > area)
            return false;
        int profitforxdays = checkprofit(length, width, noofdays, rent);
        if (profitforxdays == 0)
            return false;
        else 
        {
            area -= areaofnewone;
            cout << "Profit for no of days: " << profitforxdays << endl;
            totalprofit = accumulate(profit.begin(), profit.end(), 0);
            cout << "Total profit: " << totalprofit << endl;
            return true;
        }
    }
    int checkprofit(int length, int width, int noofdays, int rent) \
    {
        int last30days = profitfor30days(min(noofdays, 30));  
        int newprofit = noofdays * rent;
        if (newprofit >= last30days)
        {
            for (int i = 0; i < noofdays; ++i)
                profit.push_back(rent);
            return newprofit;
        else
            return 0;
    }
    int profitfor30days(int noofdays) 
    {
        int totalprofit = 0;
        int daysToConsider = min(noofdays, (int)profit.size());
        for (int i = 0; i < daysToConsider; ++i)
            totalprofit += profit[i];
        return totalprofit;
    }
};
int main() {
    store myStore(10, 10);
    bool item1 = myStore.acceptbox(2, 2, 4, 10);
    if (!item1)
        cout << "Cannot store box" << '\n';
    return 0;
}
