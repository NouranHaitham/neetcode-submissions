class Solution {

    private int n, r, c;
    private String w;
    private boolean check(int x, int y)
    {
        return (x>=0 && x<r && y>=0 && y<c);
    }

    private boolean mainSolve(char[][] board)
    {
        boolean[][] vis = new boolean[r][c];
        for(int i=0;i<r;i++)
          for(int j=0;j<c;j++)
            if(solve(i,j,0,board,vis)) return true;
        return false;
    }

    private boolean solve(int x, int y,int indx,char[][] board,boolean[][] vis)
    {
        if(indx == n)  return true;
        if(!check(x,y) || vis[x][y]) return false;

        vis[x][y] = true;

        if(board[x][y] == w.charAt(indx))
        {
            indx++;
            boolean ans = solve(x, y+1,indx,board,vis) ||
            solve(x, y-1,indx,board,vis) ||
            solve(x+1, y,indx,board,vis) ||
            solve(x-1, y,indx,board,vis);
            vis[x][y] = false;
            return ans;
        }
        else
        {    
             vis[x][y] = false;
             return false;
        }
    }

    public boolean exist(char[][] board, String word) {
        
        n = word.length();
        r = board.length;
        c = board[0].length;
        w = word;

        return mainSolve(board);

    }
}
