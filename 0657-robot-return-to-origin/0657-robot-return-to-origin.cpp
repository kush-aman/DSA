class Solution {
public:
    bool judgeCircle(string moves) {
        queue<pair<int,int>> q;
        q.push({0,0});
        int checkx = -1,checky = -1;
        for(int i = 0;i < moves.size();i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(moves[i] == 'U'){
                q.push({x,y+1});
            }
            if(moves[i] == 'D'){
                q.push({x,y-1});
            }
            if(moves[i] == 'L'){
                q.push({x-1,y});
            }
            if(moves[i] == 'R'){
                q.push({x+1,y});
            }
        }
        if(q.front().first == 0 && q.front().second == 0) return true;
        return false;
    }
};