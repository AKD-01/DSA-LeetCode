class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
         
      if(n1>n2)  return findMedianSortedArrays(nums2,nums1);
        
     // When length is even, let's say 10 then left half length should be: (10+1)/2 =>5
     // When length is odd, let's say 11 then left half length should be: (11+1)/2 =>6
        // This mean that this formula gonna work in both condition
        int partition=(n+1)/2; 
        
    
    // Edge Case
    if(n1==0)
        return n2%2?nums2[n2/2]:(nums2[n2/2]+nums2[n2/2-1])/2.0;
    
    if(n2==0)
        return n1%2?nums1[n1/2]:(nums1[n1/2]+nums1[n1/2-1])/2.0;
    
    // Now do Partioning
    int left1=0;
    int right1=n1;
    int cut1,cut2;
    int l1,r1,l2,r2;
    
    do
    {   
        //Findout 'cut1' and 'cut2'
        cut1=(left1+right1)/2;
        cut2=partition-cut1;
   
        // Calculation for l1
        l1=cut1==0?INT_MIN:nums1[cut1-1];
        
        // Calculation for l2
        l2=cut2==0?INT_MIN:nums2[cut2-1];
        
        // Calculation for r1
        r1=cut1>=n1?INT_MAX:nums1[cut1];
        
        // Calculation for r2
        r2=cut2>=n2?INT_MAX:nums2[cut2];
        
        if(l1<=r2&&l2<=r1)
             // Return Result
             return n%2?max(l1,l2):(max(l1,l2)+min(r1,r2))/2.0;
        else
            
        if(l1>r2)
            right1=cut1-1;
        else
             left1=cut1+1;
       
       
    }while(left1<=right1);
        
             
    return 0.0;
    }
};