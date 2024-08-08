#include <iostream>
using namespace std;

class heap{
public:
    int arr[100];
    int size=0;

    heap(){
        arr[0]=-1;
        size=0;
    }

    void insert( int data ){
        size=size+1;
        int index=size;
        arr[index]=data;
        while(index > 1) {
            int parent = index / 2;
            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void deleteFromHeap(){
        if(size==0) return ;

        arr[1]=arr[size];
        size--;

        int i=1;
        while( i<size ){
            int left = 2*1;
            int right = 2*i+1;

            if(left<size && arr[left]>arr[i]){
                swap(arr[left],arr[i]);
                i=left;
            }
            else if( right < size && arr[i]<arr[right]){
                swap(arr[i],arr[right]);
                i=right;
            }else{
                return;
            }
        }
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout<< arr[i] << " ";
        }
        cout<<endl;
    }
};

int main(){

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(34);
    h.insert(22);
    h.insert(64);
    h.print();
    h.deleteFromHeap();
    h.print();
    
    return 0;
}