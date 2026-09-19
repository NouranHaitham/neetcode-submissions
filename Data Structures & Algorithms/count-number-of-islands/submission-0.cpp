class Solution {
private:

int n,m;
int disX[4] = {0,0,1,-1};
int disY[4] = {1,-1,0,0};
vector<vector<bool>> vis;

bool inBounds(int x, int y, int n, int m)
{
    return x >=0 && x < n && y >=0 && y < m;
}

void bfs(int xx, int yy,vector<vector<char>>& grid)
{
        queue<pair<int,int>> q;
        q.push({xx,yy});
        vis[xx][yy] = 1;

        while(q.size())
        {
            auto [x, y] = q.front();
            q.pop();

            for(int i=0;i<4;i++)
            {
                int newX = x + disX[i];
                int newY = y + disY[i];

                if(inBounds(newX,newY, n,m) && !vis[newX][newY] && grid[newX][newY] == '1')
                {
                    q.push({newX,newY});
                    vis[newX][newY] = 1;
                }
            }
        }
}

public:
    int numIslands(vector<vector<char>>& grid) {

        n = grid.size();
        m = grid[0].size();
        vis = vector<vector<bool>>(n,vector<bool>(m));
        
        
        int islands = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1' && !vis[i][j])
                {
                    bfs(i,j,grid);
                    islands++;
                }
            }
        }    
    
        return islands;
    }
};
