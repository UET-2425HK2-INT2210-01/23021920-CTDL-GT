#include <iostream>
using namespace std;
int demcapbangnhau(int a[],int n){
    int dem=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j])
            dem++;
        }
    }
    return dem;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cout << demcapbangnhau(a,n)<< endl;
    return 0;
}
