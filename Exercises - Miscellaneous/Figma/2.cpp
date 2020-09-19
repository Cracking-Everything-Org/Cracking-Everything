- reader service
- articles
- feeds
- each article is part of a feed
- users can subscribe/unsubscribe to feeds
- feature: show the user a list of the 50 most recent articles from feeds that the user is subscribed to
- design a relational database schema



Users
Id ...

Subscriptions
Index
UserId - FeedId -
1      - 2
1      - 4
1      - 1
1      - 3
2      - 5
3      - 1

u -> count UserId = givenId
n -> size

u * x
u * 50

// 50(t) = k
// min(50, t)   50 * t

first 50 rows of t
t = count rows FeedId = givenFeedId
k = first 50 rows in t
Articles
            - Index (FeedId + creationDate)
Name - Id   - FeedId - creationDate
    -   101    - 1   - 10:03
    -   102    - 1   - 10:02
    -   101    - 1   - 08:09
    -   89     - 2

ORDER BY ASC
LIMIT 50

Feeds
Id

User1 
