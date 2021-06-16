# OrderBook
Implementation for an OrderBook ordered "Market-by-price". Low latency C++
<br>![orderbook.png](https://github.com/nikkaramessinis/OrderBook/blob/main/orderbook.png "OrderBook")

<br>Detailed explanation on how commands in an OrderBook get executed. 
<br>https://www.youtube.com/watch?v=Kl4-VJ2K8Ik
<br>Immediate TODOs:
* Implement a spinlock for locking when accessing those maps. Spin lock may be“burning” CPU but waits and reacts really fast. And that is what we would need for a
low latency system like an orderbook.
* Then upgrade testing to support multiple market orders with threads. 
* Upgrade map to multimap. We may have entries for the same price at the same time.

