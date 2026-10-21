class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
    int max_score=0;
    int score=0;
    int i=0;
    sort(tokens.begin(),tokens.end());
    int j=tokens.size()-1;
    while(i<tokens.size() && i<=j){
    if(power>=tokens[i]){
    power-=tokens[i];
    score++;
    max_score=max(max_score,score);
    i++;    
    }
    else if(power<tokens[i] && score>=1 && j>=i){
    power+=tokens[j];
    j--;
    score--;
    }
    else if(power<tokens[i] && score==0) break;
    } 
    return max_score;   
    }
};