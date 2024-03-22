class Solution {
public:

    void fill(int x,int y,vector<vector<int>>& image, int color,int mark,int n, int m){
        image[x][y] = color;

        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if( nx <0 || ny<0 || nx >= n || ny >= m || image[nx][ny]!=mark || image[nx][ny]==color){
                continue;
            }

            // image[nx][ny] = color;
            fill(nx,ny,image,color,mark,n,m);


        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        if(image[sr][sc] == color){
            return image;
        }

        int n = image.size();
        int m = image[0].size();

        int mark = image[sr][sc];

        fill(sr,sc,image,color,mark,n,m);


        return image;

        
    }
};