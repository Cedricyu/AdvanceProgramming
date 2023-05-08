#include <iostream>
#include <algorithm>
#include <string>
using std::string ;using std::cin; using std::cout;


string reverse_by_groups(int groups,string& str){
    int size = str.size()/groups;
    for(int i =0 ; i < groups ;i++){
        reverse(str.begin()+size*i, str.begin() + size*(i+1));
    }
    return str;
}

int main() {
    int len;
    string s;
    while (1)
    {
        cin >> len >> s;
        if(len==0)
            break;
	    cout<< reverse_by_groups(len,s) << std::endl; 
    }
    
    
    return 0;
}
