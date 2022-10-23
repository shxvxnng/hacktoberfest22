#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>&a,int begin,int end){
    int pivot = a[end];

    int i = begin-1;
    for(int j = begin;j<end;j++){

        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }

    }
    swap(a[end],a[i+1]);
    return i+1;
}


void quicksort(vector<int>&a, int begin, int end){
    if(begin<end){
        int pi = partition(a,begin,end);
        quicksort(a,begin, pi-1);
        quicksort(a,pi+1,end);
    }
}





int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }

    quicksort(a,0,n-1);

    for(int i = 0;i<n;i++){
        cout<<a[i]<<" ";
    }

}
