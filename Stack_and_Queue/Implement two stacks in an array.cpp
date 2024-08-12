class twoStacks {
  public:
    
    int arr[100];
    int i;
    int j;
    
    twoStacks() {
        i=-1;
        j=100;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        arr[++i]=x;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        arr[--j]=x;
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        int popped;
        if( i==-1){
            popped=-1;
        }else{
            popped=arr[i--];
        }
        return popped;
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        int popped;
        if( j==100){
            popped=-1;
        }else{
            popped=arr[j++];
        }
        return popped;
    }
};