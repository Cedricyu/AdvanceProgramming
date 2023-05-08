#include <iostream>
#include <algorithm>
#include <string>
#include <string>

using std::string;

bool isSubSequence(string str1, string str2, int m, int n)
{
    //std::cout << m << " " << n << std::endl;
    if(m==str1.size())
        return true;
    if( std::find(str2.begin() + n, str2.end(), str1[m]) == str2.end() )
        return false;
    return isSubSequence(str1, str2, m + 1 , find(str2.begin() + n, str2.end(), str1[m])-str2.begin() + 1 );
}

int main() {
    string s, t;
    while (std::cin >> s >> t) {
        // Check if s is a subsequence of t
        if(isSubSequence(s,t,0,0))
            std::cout << "Yes" << std::endl;
        else    
            std::cout << "No" << std::endl;
    }
    return 0;
}
