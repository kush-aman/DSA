class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
       map<char,int> mpp;
       for(int i = 0;i < moves.size();i++){
            if(moves[i] != '_') mpp[moves[i]]++;
       } 
       int maxi = -1;
       char maxch = 'L';
       for(auto it : mpp){
        if(it.second > maxi){
            maxi = it.second;
            maxch = it.first;
        }
       }
       for(int i = 0;i < moves.size();i++){
        if(moves[i] == '_') moves[i] = maxch;
       }
       queue<int> q;
       q.push(0);
       for(int i = 0;i < moves.size();i++){
        int x = q.front();
        q.pop();
        if(moves[i] == 'L'){
            q.push(x+1);
        }
        else q.push(x-1);
       }
       return abs(q.front());
    }
};