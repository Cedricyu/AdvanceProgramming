#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric>
#include <math.h>
using namespace std;
int main(){
    int counter = 0;
    while (1)
    {
        int n,q;
        cin >> n >> q;
        cin.ignore();
        if(n == 0 && q ==0 )
            break;
        vector<int> arr;
        vector<int> ques;
        for(int i =0 ; i < n ;i++){
            int element;
            cin >> element;
            arr.push_back(element);
        }
        for(int i =0 ; i < q ;i++){
            int element;
            cin >> element;
            ques.push_back(element);
        }

        sort(arr.begin(),arr.end());
        // print array
        //     for(int i =0 ; i < n ;i++){
        //         cerr << arr[i] << " ";
        //     }
        //     cerr << endl;
        // ////
        counter+=1;
        cout << "CASE# " << counter <<  ":" << endl;
        for(int i =0 ; i < q ;i++){
            auto it = lower_bound(arr.begin(), arr.end(), ques[i]);
            //cerr << "value = " << arr[it-arr.begin()]  << " ques = " << ques[i] << endl ;
            if( it == arr.end() || arr[it-arr.begin()]!=ques[i])
                cout <<  ques[i] << " not found" << endl;
            else
                cout <<  ques[i] << " found at "  << it-arr.begin()+1 << endl;
        }
    }
    
}