class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int ans = 0;
        for(int i=0; i<seats.size(); i++){
            if(seats[i] > students[i]){
                ans = ans + seats[i] - students[i];
            } else {
                ans = ans + students[i] - seats[i];
            }
        }
        return ans;
    }
};