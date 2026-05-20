class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> prefixCommonArray(n);

        for (int currentIndex = 0; currentIndex < n; ++currentIndex) {
            int commonCount = 0;

            for (int aIndex = 0; aIndex <= currentIndex; ++aIndex) {
                for (int bIndex = 0; bIndex <= currentIndex; ++bIndex) {
                    if (A[aIndex] == B[bIndex]) {
                        ++commonCount;
                        break;
                    }
                }
            }

            prefixCommonArray[currentIndex] = commonCount;
        }

        return prefixCommonArray;
    }
};