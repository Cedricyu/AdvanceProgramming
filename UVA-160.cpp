#include <iostream>
#include <iomanip>
using namespace std;
bool check_prime(int n) {
  bool is_prime = true;

  // 0 and 1 are not prime numbers
  if (n == 0 || n == 1) {
    is_prime = false;
  }

  for (int i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      is_prime = false;
      break;
    }
  }

  return is_prime;
}

int find_max_prime(int n){
    int tmp = n;
    while(!check_prime(tmp)){
        tmp--;
    }
    return tmp;
}


int main()
{
    while(1){
        int n;
        cin >> n;
        if ( n ==0 )
            break;
        int primes[n+1] = {0};
        int index = 2;
        int max_prime = find_max_prime(n);
        while(index <= n){
            int i =2;
            //cout << "index = " << index << endl;
            int tmp = index;
            while( i <= index ){
                while(tmp%i==0){
                    //cout << tmp << " % " << i << endl;
                    primes[i]++;
                    tmp/=i;
                    //cout << i << endl;
                }
                i++;
            }
           index++; 
        }
        cout << setw(3) <<  n << "! = " ;
        int cnt =0 ;
        for(int  i =0 ; i <= n ; i++){
            if(primes[i]!=0){
                if(cnt == 15){
                    cout << endl;
                    cout << setw(7) << " " ;
                    cnt  =0 ;
                }
                if(i==max_prime || cnt == 14)
                    cout << setw(2) << primes[i];
                else
                    cout << setw(2) << primes[i] << " ";
                cnt ++;
            }
        }
        cout << endl;
    }

    return 0;
}
