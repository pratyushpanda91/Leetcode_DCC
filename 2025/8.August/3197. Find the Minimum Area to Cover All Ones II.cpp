unsigned A[30], T[30];

class Solution {
public:
    static void build_A_T(vector<vector<int>>& grid, int n, int m) {
        fill(A, A+n, 0);// reset
        fill(T, T+m, 0);// reset transpose
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j]==0) continue;
                A[i]|=(1U<<j);  // row i
                T[j]|=(1U<<i);  // col j (transpose)
            }
        }
    }

    // area of the bounding box of 1s in submatrix [i0..iN][j0..jN]
    static int minRect(int i0, int iN, int j0, int jN){
        int iMin=30, iMax=-1, jMin=30, jMax=-1;

        // Proceed in 4 directions
        // find top row with any 1 in [j0..jN]
        for (int i=i0; i<=iN; i++) {
            unsigned row=A[i];
            unsigned mRow=(row>>j0)<<j0;
            mRow&=((1u<<(jN+1))-1u);
            if (mRow) { iMin=i; break; }
        }
        if (iMin==30) return 1e8; // no 1s in this submatrix

        // bottom row
        for (int i=iN; i>=iMin; i--) {
            unsigned row=A[i];
            unsigned mRow=(row>>j0)<<j0;
            mRow&=((1u<<(jN+1))-1u);
            if (mRow) { iMax=i; break; }
        }
        // left col
        for (int j=j0; j<=jN; j++) {
            unsigned col=T[j];
            unsigned mCol=(col>>i0)<<i0;
            mCol&=((1u<<(iN+1)) - 1u);
            if (mCol) { jMin=j; break; }
        }
        // right col
        for (int j=jN; j>=jMin; j--) {
            unsigned col=T[j];
            unsigned mCol=(col>>i0)<<i0;
            mCol&=((1u<<(iN+1)) - 1u);
            if (mCol) { jMax=j; break; }
        }
        return (iMax-iMin+1)*(jMax-jMin+1);
    }

    static int minimumSum(vector<vector<int>>& grid) {
        const int n=grid.size(), m=grid[0].size();
        build_A_T(grid, n, m);

        int ans=INT_MAX;

        //  2 vertical cuts
        for (int c1=0; c1<m-2; c1++) {
            for (int c2=c1+1; c2<m-1; c2++) {
                int a=minRect(0, n-1, 0,c1);
                int b=minRect(0, n-1, c1+1, c2);
                int c=minRect(0, n-1, c2+1, m-1);
                ans=min(ans, a+b+c);
            }
        }

        // 2 horizontal cuts
        for (int r1=0; r1<n-2; r1++) {
            for (int r2=r1+1; r2<n-1; r2++) {
                int a=minRect(0, r1, 0, m-1);
                int b=minRect(r1+1, r2, 0, m-1);
                int c=minRect(r2+1, n-1, 0, m-1);
                ans=min(ans, a+b+c);
            }
        }

        // T-shapes (3-rectangle partitions)
        for (int r=0; r<n-1; r++) {
            for (int c=0; c<m-1; c++) {
                // top, bottom-left & bottom-right
                {
                    int top=minRect(0, r, 0, m-1);
                    int bl=minRect(r+1, n-1, 0, c);
                    int br=minRect(r+1, n-1, c+1, m-1);
                    ans=min(ans, top+bl+br);
                }
                // bottom, top-left & top-right
                {
                    int bottom=minRect(r+1, n-1, 0, m-1);
                    int tl=minRect(0, r, 0, c);
                    int tr=minRect(0, r, c+1, m-1);
                    ans=min(ans, bottom+tl+tr);
                }
                // left, top-right & bottom-right
                {
                    int left=minRect(0, n-1, 0, c);
                    int tr=minRect(0, r, c+1, m-1);
                    int br=minRect(r+1, n-1, c+1, m-1);
                    ans=min(ans, left+tr+br);
                }
                // right, top-left & bottom-left
                {
                    int right=minRect(0, n-1, c+1, m-1);
                    int tl=minRect(0, r, 0, c);
                    int bl=minRect(r+1, n-1, 0, c);
                    ans = min(ans, right+tl+bl);
                }
            }
        }

        return ans;
    }
};
