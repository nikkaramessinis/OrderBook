#ifndef _ORDER_BOOK
#define _ORDER_BOOK

#include "orderentry.hpp"
#include <map>
#include <memory>

class OrderBook
{
private:
    void LiquidateCommand(OrderEntry* entry, std::map<float, OrderEntry*>& erasalMap, int& entryVolume);
    void OrderHelper(OrderEntry* entry, std::map<float, OrderEntry*>& erasalMap, std::map<float, OrderEntry*>& insertionMap);
public:
  OrderBook(float startingPrice, int Volume);

  void DebugPrint();

  void MakeOrder(OrderEntry* entry);
    
private:
  std::map<float, OrderEntry*> buyOrders;
  std::map<float, OrderEntry*> sellOrders;
  
  int totalBuyVolume = 0;
  int totalSellVolume = 0;
};

#endif
