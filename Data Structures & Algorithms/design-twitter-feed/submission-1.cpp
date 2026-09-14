class Twitter {
public:

    int time;
    const int max_feeds = 10;
    unordered_map<int, vector<pair<int, int>>> user_tweet_map;
    unordered_map<int, unordered_set<int>> followingMap;

    Twitter() : time(0) {
        
    }
    
    void postTweet(int userId, int tweetId) {
        user_tweet_map[userId].push_back({time, tweetId});
        follow(userId, userId);
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        auto it1 = followingMap.find(userId); 
        unordered_set<int>& followers = it1->second;
        for (auto it2 = followers.begin(); it2 != followers.end(); ++it2) {
                auto it3 = user_tweet_map.find(*it2);
                if (it3 != user_tweet_map.end()) {
                    vector<pair<int, int>>& tweets = it3->second;
                    for (int j = 0; j < tweets.size(); j++) {
                        pq.push(tweets[j]);
                        if (pq.size() > max_feeds)
                            pq.pop();
                    }
                }
            }
        int n = pq.size();
        vector<int> feeds(n);
        for (int i = n - 1; i >= 0; i--) {
            feeds[i] = pq.top().second;
            pq.pop();
        }
        return feeds;
    }
    
    void follow(int followerId, int followeeId) {
        followingMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it = followingMap.find(followerId);
        if (it != followingMap.end()) 
            it->second.erase(followeeId);
    }
};
