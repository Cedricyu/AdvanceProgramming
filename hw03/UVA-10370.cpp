
#include <iostream>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int k = 0; k < n ; k++)
    {
        /* code */
        int cnt;
        cin >> cnt;

        size_t size = cnt;
        vector<int> arr;
        for ( int i =0 ; i < cnt ; i++){
            int input;
            cin >> input;
            arr.push_back(input);
        }
        
        float average = accumulate(arr.begin(), arr.end(), 0);
        //cerr << average << endl;
        average/= arr.size();
        //cerr << average << endl;
        cout << std::fixed << std::setprecision(3) << static_cast<float>(count_if(arr.begin(), arr.end(), [average](int a){ return a > average; }))*100/arr.size() << "%" << endl; 
    }
    
    return 0;
}
