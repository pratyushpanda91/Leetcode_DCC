class Solution {
  public:
    // Function to count inversions in the array.
    int  merge(vector<int>&arr ,int s ,int mid , int e){
        int left =s,right = mid+1;
        int count=0;
        vector<int>temp;
        while(left<=mid && right<=e){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                count+=mid-left+1;
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
             temp.push_back(arr[left]);
                left++;
        }
        while(right<=e){
            temp.push_back(arr[right]);
                right++;
        }
        for(int i=s;i<=e;i++){
            arr[i]=temp[i-s];
        }
         return count;
    }
    int sort(vector<int>&arr ,int s ,int e){
        if(s>=e){
            return 0 ;
        }
        int count=0;
        int mid = s+ (e-s)/2;
        count+=sort(arr,s,mid);
        count+=sort(arr,mid+1,e);
        count+=merge(arr,s,mid,e);
        return count;
    }

    int inversionCount(vector<int> &arr) {
        int n=arr.size();
       int count= sort(arr,0,n-1);
        return count;
    }
};
