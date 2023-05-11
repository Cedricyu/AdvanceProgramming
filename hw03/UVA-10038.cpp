
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int n;
    while(cin >> n){
        auto print = [n](const int *array)
        {
            for (int i =1 ; i < n ; i++)
                std::cerr << array[i] << ' ';
            std::cerr << '\n';
        };
        vector<int> array ;
        int result[n];
        //cout << "n = " << n;
        for(int i = 0 ; i < n ; i++){
            int num;
            cin >> num;
            array.push_back(num);
        }
        // for(int i = 0 ; i < n ; i++){
        //     cout << array[i] << " " << endl;
        // }
        adjacent_difference(array.begin(), array.end(), result);
        //print(result);
        sort(result+1,result+n,[](int &a,int &b){ return abs(a) < abs(b); });
        //print(result);
        int one = 1;
        int &index = one;
        if(all_of(result+1 , result+n, [&index](int i){ return abs(i) == index++; })){
            std::cout << "Jolly" << std::endl;
        }
        else{
            std::cout << "Not jolly" << std::endl;
        }
    }

    return 0;
}
