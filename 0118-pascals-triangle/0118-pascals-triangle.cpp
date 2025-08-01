class Solution {
public:
    //Type-3 : Given n print the entire triangle
    vector<int> generateRow(int row) {
        long long ans=1;
        vector<int> list;
        list.push_back(ans);
        for(int col=1; col<row; col++) {
            ans*=row-col;
            ans/=col;
            list.push_back(ans);
        }
        return list;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++) {
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};

// Type - 2 Print the given nth row of pascal triangle 
// n=5 Ans - 1 3 3 1 
// for(c=1;c<n;c++) {
//     cout<<nCr(n-1,c-1);
// }
//or
// long long ans = 1;
// cout<<ans;
// for(int i=1; i<n; i++) {
//     ans=ans * n-i;
//     ans=ans / i;
//     cout<<ans;
// }

// Type - 1 Given R & C tell the element at that place.
// int R=5, C=3; Ans : 4C2 = 6
// int nCr(int n, int r) {
//     long long res = 1;
//     for(int i=0; i<r; i++) {
//         res = res*n-i;
//         res = res/i+1;
//     }
//     return res;
// }

// cout<<nCr(R-1, C-1);