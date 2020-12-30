#include<bits/stdc++.h>
using namespace std;

bool isUnique(int n){
    int r, b[1000], p=0, flag = 0;
    while(n != 0){
        r = n%10;
        b[p] = r;
        n = n/10;
        p++;
    }
    for(int i=0; i<p; i++){
    
        for(int j=i+1; j<p; j++){
            if(b[i] == b[j]){
                return false;
            }
        }
    }

    return true;
}

int main(){
    int t, l, r, a[1000];
    cin >> t; 
    while(t--){
        cout << "Enter the left extreme: ";
        cin >> l;
        cout << "Enter the right extreme: ";
        cin >> r;
        for(int i=l; i<=r; i++){
            a[i] = i;
        }
        for(int i=l; i<=r; i++){
            if(isUnique(a[i])){
                cout << a[i] << " ";
            }
        }
	cout<<endl;
    }
