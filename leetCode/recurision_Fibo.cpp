#include<iostream>
using namespace std;

int Fibo(int n){
    if(n == 1 || n==0){
        return n;
    }

    return Fibo(n-1)+Fibo(n-2);

}

int main(){
    int n = 4;
    int result = Fibo(n);
    cout<<result<<endl;
    return 0;
}