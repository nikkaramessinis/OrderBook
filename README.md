# OrderBook
Implementation for an OrderBook ordered "Market-by-price"
Immediate TODOs:
* Implement a spinlock for locking when accessing those maps. Spin lock may be“burning” CPU but waits and reacts really fast. And that is what we would need for a
low latency system like an orderbook.
* Then upgrade testing to support multiple market orders with threads. 
* Upgrade map to multimap. We may have entries for the same price at the same time.

![orderbook.png](https://github.com/nikkaramessinis/OrderBook/blob/main/orderbook.png "OrderBook")

3. How would you improve the algorithm if you had to support 21 million securities?
What data structures would you use and does that change your architecture?
We would still want to get a good insertion time for 21 million entries O(logn)
And good access time O(1) having a tree solution as a map has. If we were to have
changed to a vector or a list or a queue access time would be O(n) which would be
devastating. A set is also a binary tree implementation so perhaps it would be better
to have a set instead and change to comparator to sort on the securityID instead
what the default would be to sort on the pointer.
4. Estimate memory utilisation of an OrderBook containing 21 million securities, 100
orders deep.
So a pointer is worth 4bytes in a 32bit system and 8bytes in a 64byte system. We will
assume we have a 64 bit system. Keeping a pointer for a security is 8 bytes.
So we 1million securities each security has one Orderbook and inside the orderbook
We have 100 entries 4 bytes for each enum 3 of them one int for the volume 4 bytes
also one float for the price four bytes too and one int for the orderID since we have
about a 100 an int is more than enough. Resulting in 28 bytes. 28*100 2800 bytes
just for the entries. Keeping an orderBook takes up some space and a security id
should be unsigned long to keep at least a million securities. Lets say 2900 bytes for
every security in broad terms. Having 21 million entries 2900*21.000.000 results in
60900000000 .Something like 56.71 Gigabytes
