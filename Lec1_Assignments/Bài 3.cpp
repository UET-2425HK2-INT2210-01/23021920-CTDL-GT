#include <iostream>
using namespace std;

int ucln(int m, int n){
    for(int i=n;i>0;i--){
        if(m%i == 0 && n%i == 0){
            return i;
        }
    }
    return 1;
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << ucln(m,n) << endl;
    return 0;
}