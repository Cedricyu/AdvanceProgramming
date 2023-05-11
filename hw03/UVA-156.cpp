#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class word{
    public:
        string s_;
        int id_;
    public :
        word(string s, int id, int option){
            s_ = s;
            id_ = id;
            if(option==1){
                lower();
                sortstring();
            }
        }

        void lower(){
            transform(s_.begin(), s_.end(), s_.begin(),
                [](unsigned char c){ return std::tolower(c); });
        }
        void sortstring(){
            sort(s_.begin(),s_.end());
        }
};


int main(){
    vector <word> inputs;
    vector <word> tmp;
    int id = 0;
    while (1)
    {
        string input;
        cin >> input;
        if(input=="#")
            break;
        inputs.push_back(word(input,id,1));
        tmp.push_back(word(input,id,0));
        //cerr << input << endl;
        id++;
    }
    sort(inputs.begin(), inputs.end(), [](word a, word b){ return a.s_ < b.s_ ; });
    for(int i = 0 ; i < inputs.size()-1 ; ){
        if(inputs[i].s_ == inputs[i+1].s_){
            int counter = 1;
            while (inputs[i+counter].s_ == inputs[i].s_)
            {
                int deleteId = inputs[i+counter].id_;
                tmp.erase(find_if(tmp.begin(),tmp.end(),[deleteId](word a){ return a.id_ == deleteId ;}));
                counter ++;
            }
            int deleteId = inputs[i].id_;
            tmp.erase(find_if(tmp.begin(),tmp.end(),[deleteId](word a){ return a.id_ == deleteId ;}));
            i+=counter;
        }
        else{
            i++;
        }
    }
    sort(tmp.begin(),tmp.end(),[](word a,word b){ return a.s_ < b.s_ ;});
    for(word s : tmp)
        cout << s.s_ << endl;
}