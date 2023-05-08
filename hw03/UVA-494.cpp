
#include <iostream>
#include<ctype.h>
using namespace std;

int main()
{
    string line;
    while(getline(cin,line)){
        int cnt =0 ;
        bool find_alphabet = false;
        for(int i =0 ; i < line.size() ; i++){
            if( isalpha(line[i]) && !find_alphabet ){
                cnt++;
                find_alphabet = true;
            }
            else if( !isalpha(line[i]) && find_alphabet){
                find_alphabet = false;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
