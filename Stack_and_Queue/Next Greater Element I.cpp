class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> mp;

        // back treverse in array and store greater in map
        int n=nums2.size()-1;
        stack<int> st;

        for(int i=n; i>=0; i--){
            while( !st.empty() && nums2[i]>st.top() )   {
                st.pop();
            }         
            if( !st.empty() ){
                mp[nums2[i]]=st.top();                
            }else{
                mp[nums2[i]]=-1;
            }
            st.push(nums2[i]);
        }
        for( int i=0; i<nums1.size(); i++){
            nums1[i]=mp[nums1[i]];
        }
        
        return nums1;        
    }
};