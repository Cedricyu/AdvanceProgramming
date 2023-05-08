#include <iostream>
#include <algorithm> 
#include <array>
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << "Lumberjacks:\n";
    while (n--) {
        array<int,10> arr;
        for (int i = 0; i < 10; i++) {
            cin >> arr[i];
        }

        if(is_sorted(arr.begin(),arr.end(),[](int a,int b){ return a < b ;}) || is_sorted(arr.begin(),arr.end(),[](int a,int b){ return a > b ;}))
            cout << "Ordered" << endl;
        else    
            cout << "Unordered" << endl;
    }

    return 0;
}
