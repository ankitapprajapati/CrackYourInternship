class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int sum = 0;

        while (arr.size() > 1) {
            int minProduct = INT_MAX;
            int index = 0;

            // Find the pair with the minimum product
            for (int i = 0; i < arr.size() - 1; i++) {
                int product = arr[i] * arr[i + 1];
                if (product < minProduct) {
                    minProduct = product;
                    index = arr[i]>arr[i+1]?i+1:i;
                }
            }
            // Add the minimum product to the sum
            sum += minProduct;

            // Remove the first element of the smallest product pair
            arr.erase(arr.begin() + index);
        }

    return sum;
    }
};