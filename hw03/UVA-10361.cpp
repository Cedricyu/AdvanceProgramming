#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); 
    while (n--) {
        string line1, line2;
        getline(cin, line1);
        getline(cin, line2);

        int pos1 = line1.find("<");
        int pos2 = line1.find(">");
        string part1 = line1.substr(0, pos1);
        string part2 = line1.substr(pos1 + 1, pos2 - pos1 - 1);
        int pos3 = line1.find("<",pos1+1);
        int pos4 = line1.find(">",pos2+1);
        string part3 = line1.substr(pos2 + 1, pos3 - pos2 -1 );
        string part4 = line1.substr(pos3 + 1, pos4 - pos3 - 1);
        string part5 = line1.substr(pos4 + 1,line1.size()-pos4-1);

        string ouputline2 = line2.substr(0, line2.size() - 3);

        cout << part1 << part2 << part3 << part4 << part5 << endl;
        cout << ouputline2 << part4 << part3 << part2  << part5 << endl;
    }
    return 0;
}
