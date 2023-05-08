
#include <iostream>
#include <ctype.h>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n)
    {
        /* code */
        string str;
        cin >> str;
        int strlen = str.size();
        string output = str;
        for(int i=0 ; i < strlen ; i++){
            rotate(str.begin(),str.begin()+1,str.end());
            if(str.compare(output) < 0)
                output = str;
        }
        //cout << endl;
        cout << output << endl;
        n--;
    }
    

    return 0;
}
