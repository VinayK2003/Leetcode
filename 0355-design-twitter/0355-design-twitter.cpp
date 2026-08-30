class Twitter {
public:
    //Tweets 
    // userid -> {time,tweetId}
    unordered_map<int, vector<pair<int,int>>> tweets;

    // friends
    // follower -> list of followee 
    unordered_map<int,set<int>> friends;

    Twitter() {
        
    }
    int time=0;
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Adding the user in list of friends, so that we get that users tweets as well
        friends[userId].insert(userId);
        

        // We need a priority queue to sort on the basis of time
        // time, tweetId, userId, indx(Index is used for gettning the latest tweets)

        priority_queue<vector<int>>pq;


        //Get the latest tweets of every friends
        for(int userID: friends[userId]){
            // If friends has never tweeted then continue
            if(tweets[userID].empty()) continue;
            
            // This gives the list of all tweets of that userID
               vector<pair<int,int>>tweet= tweets[userID];

            // we want the lastest tweet only
            int ind=tweet.size()-1;
            pq.push({tweet[ind].first, tweet[ind].second,userID,ind});
        }

        vector<int>ans;
        while(!pq.empty() && ans.size()<10){
            vector<int> latestTweet= pq.top();
            ans.push_back(latestTweet[1]);
            pq.pop();
            int ind=latestTweet[3];
            int user=latestTweet[2];
            if(ind>0){
                ind--;
                pq.push({tweets[user][ind].first,tweets[user][ind].second,user,ind});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);        
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */