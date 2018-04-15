class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)return 0;
        int maxarea=INT_MIN;
	    vector<vector<int>>mat(matrix.size() + 1, vector<int>(matrix[0].size() + 1,0));
        
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                if(matrix[i][j]=='1'){
                    mat[i+1][j+1]=min({mat[i][j+1],mat[i+1][j],mat[i][j]})+1;
                    maxarea=max(maxarea,mat[i+1][j+1]);
                }
            }
        }
        return maxarea*maxarea;
    }
};