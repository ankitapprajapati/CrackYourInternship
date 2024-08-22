class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here

        for( int i=0; i<n; i++ ){
            int val = arr[i];
            
            while ( val>0 && val<=n && val!=arr[val-1] ){
                swap(val,arr[val-1]);
            }
        }
        
        for(int i=0; i<n; i++){
            if(arr[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    } 
};