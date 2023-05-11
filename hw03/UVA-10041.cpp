#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric>
#include <math.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    while (n)
    {
        int m;
        cin >> m;
        vector<int> arr;
        for(int i =0 ; i < m ;i++){
            int element;
            cin >> element;
            arr.push_back(element);
        }
        nth_element(arr.begin(),arr.begin()+m/2,arr.end());
        int sum =0;

        cout <<  accumulate(arr.begin(),arr.end(),sum,[arr,m](int a,int b){ return a+abs(b-arr[m/2]); }) << endl;
        n--;
    }
    
}