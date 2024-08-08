class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int top = rStart, down = rStart, left = cStart, right = cStart;
        ans.push_back({rStart, cStart});
        int count = 1;
        
        int dir = 0;
        while(count < rows*cols)
        {
            if(dir == 0)
            {
                for(int i=left+1; i<=right+1; i++)
                {
                    if(i>=0 && i<cols && top>=0 && top<rows)
                    {
                        ans.push_back({top, i});
                        count++;
                    }
                }
                right++;
            }
            else if(dir == 1)
            {
                for(int i=top+1; i<=down+1; i++)
                {
                    if(i>=0 && i<rows && right>=0 && right<cols)
                    {
                        ans.push_back({i, right});
                        count++;
                    }
                }
                down++;
            }
            else if(dir == 2)
            {
                for(int i=right-1; i>=left-1; i--)
                {
                    if(i>=0 && i<cols && down>=0 && down<rows)
                    {
                        ans.push_back({down, i});
                        count++;
                    }
                }
                left--;
            }
            else if(dir == 3)
            {
                for(int i=down-1; i>=top-1; i--)
                {
                    if(i>=0 && i<rows && left>=0 && left<cols)
                    {
                        ans.push_back({i, left});
                        count++;
                    }
                }
                top--;
            }
            dir = (dir+1)%4;
        }
        return ans;
    }
};