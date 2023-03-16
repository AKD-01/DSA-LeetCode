class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int N=arr.size();
//Slight better than optimal as reqSum may overflow as its multiplication but xor will never TC-O(n) and SC-O(1)
    int XOR1=0, XOR2=0;
    for(int i=0; i<N; i++) {
        XOR2 = XOR2 ^ arr[i];
        XOR1 = XOR1 ^ (i+1);
    }
    return XOR1^XOR2;
    }
};

//Optimal Solution using Maths - TC-O(n) and SC-O(1)
    /*
    int reqSum = (N*(N+1))/2;
    int sum=0;
    for(int i=0; i<N-1; i++) {
        sum+=arr[i];
    }
    return reqSum-sum
    */
    

//Better approach based on hashing TC-O(2n) and SC-O(n)
    /*
    int hash[N+1]={0};
    for(int i=0; i<N-1; i++) {
        hash[arr[i]]=1;
    }
    for(int i=1; i<=N; i++) {
        if(hash[i]==0)
        return i;
    }
    */

//Brute force approach based on linear search TC-O(n*n) and SC-O(1)
    /*
    for(int i=1; i<=N; i++) {
        int flag=0;
        for(int j=0; j<N-1; j++) { //As array has n-1 elements
            if(arr[j]==i) {
                flag=1;
                break;
            }
        }
        if(flag==0) return i;
    }
    */