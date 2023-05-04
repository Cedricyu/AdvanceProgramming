
#include <iostream>

using namespace std;

int find_peaks(int *start,int *end){
    int increasing =1,decreasing =1;
    int flag =0;
    //cerr << "distance = " << end - start << endl;
    for(int *tmp = end-1 ; tmp >= start ; tmp--){
        if(*tmp > *(tmp+1))
            increasing = decreasing +1;
        else if(*tmp < *(tmp+1))
            decreasing = increasing +1;
    }
    return increasing-1;
}

int main()
{
    int n;
    cin >> n;
    while(n){
        int arrlen = 0;
        cin >> arrlen;
        int arr[arrlen];
        for(int i=0 ; i < arrlen ; i++){
            cin >> arr[i];
        }
        // cerr << " arr = " ;
        // for(auto a : arr){
        //     cerr << a  << " ";
        // }
        // cerr << endl;
        int index =0 ;
        int len = find_peaks(&arr[index],&arr[arrlen-1])+1;
        cout << len << endl;
        n--;
    }
    return 0;
}
