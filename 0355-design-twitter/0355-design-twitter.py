class Twitter(object):

    def __init__(self):
        self.tweets = []
        self.following = []

    def postTweet(self, userId, tweetId):
        self.tweets.insert(0, [userId,tweetId])
        

    def getNewsFeed(self, userId):
        ans = []
        following = []
        for fols in self.following:
            if fols[0] == userId:
                following.append(fols[1])

        for tweet in self.tweets:
            if tweet[0] is userId or tweet[0] in following:
                if (len(ans) < 10):
                    ans.append(tweet[1])

        return ans
        

    def follow(self, followerId, followeeId):
        self.following.insert(0, [followerId, followeeId])
        

    def unfollow(self, followerId, followeeId):
        if [followerId, followeeId] in self.following:
            self.following.remove([followerId, followeeId])
        


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)