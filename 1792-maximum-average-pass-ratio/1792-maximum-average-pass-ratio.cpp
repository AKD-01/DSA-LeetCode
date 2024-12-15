class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int k) {
        priority_queue<pair<double,int>> pq;
        for(int i=0;i<classes.size();i++)
        {
            int curr_n = classes[i][0];
            int curr_d = classes[i][1];
            double curr_f = (double)curr_n/(double)curr_d;
            int new_n = curr_n+1;
            int new_d = curr_d+1;
            double new_f = (double)new_n/(double)new_d;

            pq.push({new_f-curr_f,i});
        }

        while(k)
        {
            pair<double,int> p = pq.top();
            pq.pop();
            int index = p.second;
            classes[index][0]+=1;
            classes[index][1]+=1;

            int new_n = classes[index][0]+1;
            int new_d = classes[index][1]+1;
            double new_f = (double)new_n/(double)new_d;
            double curr_f = (double)classes[index][0]/(double)classes[index][1];

            pq.push({new_f-curr_f,index});
            k--;
        }
        double sum = 0;
        for(int i=0;i<classes.size();i++)
        {
            sum+=(double)classes[i][0]/(double)classes[i][1];
        }
        return sum/(double)classes.size();
    }
};