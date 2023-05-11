#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>
#include <numeric>

using namespace std;

double operator -(pair<int,int> a,pair<int,int> b){
    return (sqrt(pow(a.first - b.first,2) + pow(a.second - b.second,2)) + 16.0 );
}

int main(){
    int counter = 0;
    while (1)
    {
        int n;
        cin >> n;
        if(n == 0)
            break;
        vector <pair<int,int>> points;
        for(int i = 0 ; i < n ; i++){
            int x,y;
            cin >> x >> y;
            points.push_back(make_pair(x,y));
        }
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        float min = INFINITY;
        vector<int> permuation(n);
        while (next_permutation(idx.begin(),idx.end())) // 0 1 2 3 4 5 // 5 4 3 2 1 0
        {
            float sum=0;
            for(int i = 0 ; i < n-1 ; i++){
                sum += points[idx[i]] - points[idx[i+1]];
            }
            if(sum < min){
                min = sum;
                copy(idx.begin(),idx.end(),permuation.begin());
            }
        }
        /// print
            // for (int i = 0 ; i < n ; i++){
            //     cerr << permuation[i] << " " ;
            // }
            // cerr << endl;
        ///

        cout << "**********************************************************" << endl;
        counter += 1;
        cout << "Network #" << counter << endl;
        for (int i = 0 ; i < n-1 ; i++){
            cout << "Cable requirement to connect (" << points[permuation[i]].first << "," << points[permuation[i]].second << ") to (" << points[permuation[i+1]].first << "," << points[permuation[i+1]].second << ") is " << fixed << setprecision(2) << points[permuation[i]] - points[permuation[i+1]] << " feet." << endl;
        }
        cout << "Number of feet of cable required is " << fixed << setprecision(2) << min << "." << endl;
        
    }
    

}