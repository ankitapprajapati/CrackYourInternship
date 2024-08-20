class NumArray {
public:
    vector<int> ST; // Segment tree array
    vector<int> nums; // Original array
    int n; // Size of the input array

    // Function to build the segment tree
    void buildST(int idx, int l, int r) {
        if (l == r) {
            ST[idx] = nums[l]; // Leaf node
            return;
        }
        int mid = (l + r) / 2;
        buildST(2 * idx + 1, l, mid); // Build left subtree
        buildST(2 * idx + 2, mid + 1, r); // Build right subtree
        ST[idx] = ST[2 * idx + 1] + ST[2 * idx + 2]; // Combine the results
    }

    // Constructor to initialize the segment tree
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        ST.resize(4 * n); // Resize the segment tree array
        buildST(0, 0, n - 1); // Build the segment tree
    }

    // Function to update the value in the segment tree
    void updateST(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            ST[idx] = val; // Update the leaf node
            nums[pos] = val; // Update the original array
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            updateST(2 * idx + 1, l, mid, pos, val); // Update in the left subtree
        } else {
            updateST(2 * idx + 2, mid + 1, r, pos, val); // Update in the right subtree
        }
        ST[idx] = ST[2 * idx + 1] + ST[2 * idx + 2]; // Recalculate the current node's value
    }

    // Public function to update a value
    void update(int idx, int val) {
        updateST(0, 0, n - 1, idx, val);
    }

    // Function to get the sum of a range [left, right]
    int sumRangeST(int idx, int l, int r, int left, int right) {
        if (r < left || l > right) {
            return 0; // No overlap
        }
        if (l >= left && r <= right) {
            return ST[idx]; // Complete overlap
        }
        int mid = (l + r) / 2;
        return sumRangeST(2 * idx + 1, l, mid, left, right) + sumRangeST(2 * idx + 2, mid + 1, r, left, right);
    }

    // Public function to get the sum in the range [left, right]
    int sumRange(int left, int right) {
        return sumRangeST(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */