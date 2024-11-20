class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     int i=0;
     int j=0;
     int k=0;
     vector<int>ans(m+n+1);
     while(i<m&&j<n){
        if(nums1[i]<nums2[j]){
            ans[k++]=nums1[i++];
                    cout<<k<<" ";

        }
        else{
            ans[k++]=nums2[j++];
                    cout<<k<<" ";

        }
     }
     for(;i<m;i++){
        ans[k++]=nums1[i];
                cout<<k<<" ";

     }
     for(;j<n;j++){
        ans[k++]=nums2[j];
        cout<<k<<" ";
     }
     for(i=0;i<m+n;i++){
        nums1[i]=ans[i];
     }

    }
};