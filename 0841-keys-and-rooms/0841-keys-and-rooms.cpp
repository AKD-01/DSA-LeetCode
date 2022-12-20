class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n, false);
        queue<int>q;
        q.push(0);
        int roomsVisited = 1; //0th room is visited
        visited[0] = true;
        //========================================================
        while(!q.empty())
        {
            int currRoom = q.front();
            q.pop();
            
            for (int nextRoom : rooms[currRoom])
            {
                if (visited[nextRoom]) continue;
                visited[nextRoom] = true;
                q.push(nextRoom);
                roomsVisited++;
            }
        }
        //=============================================================
        return (roomsVisited == n);
    }
};