class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int c=head->val;
        vector<vector<int>>matrix(m,vector<int>(n));
        int row=matrix.size(),col=matrix[0].size();
        int top=0,bottom=row-1,left=0,right=col-1;
        while(left<=right && top<=bottom){
            for(int j=left;j<=right;j++){
                (head?c=head->val:c=-1);
                matrix[top][j]=c;
                if(head)
                head=head->next;
            }
                top++;
            

            for(int i=top;i<=bottom;i++){
                    (head?c=head->val:c=-1);
                    matrix[i][right]=c;
                    if(head)
                    head=head->next;
            }
                    right--;
            

            if(top<=bottom){
                for(int j=right;j>=left;j--){
                    (head?c=head->val:c=-1);
                    matrix[bottom][j]=c;
                    if(head)
                    head=head->next;
                }
                    bottom--;
                
            }

            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    (head?c=head->val:c=-1);
                    matrix[i][left]=c;
                    if(head)
                    head=head->next;
                }
                    left++;
                
            }
        }
        return matrix;
    }
};
