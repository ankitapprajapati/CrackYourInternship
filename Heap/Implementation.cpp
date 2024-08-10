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

    void heapify(int arr[],int n, int i){

        int largest =i;
        int left = 2*i;
        int right = 2*i+1;

        if(left <= n && arr[left]>arr[largest] ){
            largest=left;
        }
        if(right <= n && arr[right]>arr[largest] ){
            largest=right;
        }

        if( largest != i){
            swap(arr[i],arr[largest]);
            heapify(arr,n,largest);
        }

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

    int arr[6]={-1,54,53,55,52,56};
    for( int i=5/2; i>0; i--){
        h.heapify(arr,5,i);
    }
    for (int i=1; i<6; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}