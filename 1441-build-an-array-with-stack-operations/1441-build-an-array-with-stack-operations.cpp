class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int currElem=1; //Current Element tells the element to be added in the stack, first element added will be 1
        for(int i=0;i<target.size();i++){
            while(currElem!=target[i]){ //While we do not make current element equal to corresponding element in target array 
                ans.push_back("Push");  //We will simply push and pop those elements which are not in final target array
                ans.push_back("Pop");
                currElem++;
            }
            ans.push_back("Push"); //Pushing the target element in stack 
            currElem++;
        }
        return ans;
    }
};