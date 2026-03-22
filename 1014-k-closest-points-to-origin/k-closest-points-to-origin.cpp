class Solution {
public:
    int distant(int x,int y){
        return x*x + y*y; // fixed (avoid pow)
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();

        priority_queue<pair<int,pair<int,int>>> q;

        for(int i = 0; i < n; i++){
            int temp = distant(points[i][0], points[i][1]);
            q.push({temp, {points[i][0], points[i][1]}});
        }
    
        while(q.size() != k){
            q.pop();
        }

        vector<vector<int>> result;

        while(!q.empty()){
            result.push_back({q.top().second.first, q.top().second.second}); // fixed
            q.pop();
        }

        return result;
    }
};