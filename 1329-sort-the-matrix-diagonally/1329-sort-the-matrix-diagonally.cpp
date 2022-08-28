class Solution {
public:
    
    void merge( int si, int sj, int mi, int mj, int ei, int ej, vector<vector<int>> &mat ){
        vector<int> mer;
        int fi = si, fj = sj, sei = mi+1, sej = mj+1;
        while ( fi <= mi && fj <= mj && sei <= ei && sej <= ej ){
            if ( mat[fi][fj] < mat[sei][sej] )  mer.push_back(mat[fi++][fj++]);
            else  mer.push_back(mat[sei++][sej++]);
        }
        while ( fi <= mi && fj <= mj )  mer.push_back(mat[fi++][fj++]);
        while ( sei <= ei && sej <= ej )    mer.push_back(mat[sei++][sej++]);
        for ( int i = 0; i<mer.size(); i++ )    mat[si++][sj++] = mer[i];
    }
    
    void merge_sort( int si, int sj, int ei, int ej, vector<vector<int>> &mat ){
        if ( si >= ei && sj >= ej ) return;
        int mi = si + (ei-si)/2, mj = sj + (ej-sj)/2;
        merge_sort(si,sj,mi,mj,mat);
        merge_sort(mi+1,mj+1,ei,ej,mat);
        merge(si,sj,mi,mj,ei,ej,mat);
    }
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for ( int i = n-1; i>=0; i-- ){
            int mi = min(n-i,m);
            merge_sort(i,0,mi+i-1,mi-1,mat);
        }
        for ( int j = 0; j<m; j++ ){
            int mi = min(n,m-j);
            merge_sort(0,j,mi-1,mi+j-1,mat);
        }
        return mat;
    }
};