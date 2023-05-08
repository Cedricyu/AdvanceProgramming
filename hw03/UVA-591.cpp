
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <math.h>
using namespace std;

int main()
{
    int set = 0;
    while (1)
    {

        int cnt;
        cin >> cnt;
        if(cnt==0)
            break;

        size_t size = cnt;
        vector<int> arr;
        for ( int i =0 ; i < cnt ; i++){
            int input;
            cin >> input;
            arr.push_back(input);
        }
        
        int average = accumulate(arr.begin(), arr.end(), 0)/arr.size();
        int total = 0;
        for(auto a : arr)
            total += abs(a-average);

        cout << "Set #" << set+1 << endl;
        cout << "The minimum number of moves is " << total/2 << "." << endl;
        cout << endl;

        set++;
    }
    
    return 0;
}
