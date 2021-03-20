#include "orderbook.hpp"

/*
/ Constructor will make an initial purchase for some volume at a starting price just like a stock would enter the stock market after IPO.
*/
OrderBook::OrderBook(float startingPrice, int Volume)
{
  OrderEntry* initialOrder = new OrderEntry(OrderAction::Add, OrderDirection::SELL, OrderConstraints::LIMIT, startingPrice, Volume);
  MakeOrder(initialOrder);
}

/*
/ This mostly exists for debugging and visualisation purposes
/ Presents a list with bids and asks for the current orderbook
*/
void OrderBook::DebugPrint()
{
  std::cout <<  "--------------------------------------------------- "<< std::endl;
  for (auto sellItr = sellOrders.rbegin(); sellItr != sellOrders.rend(); sellItr++)
  {
    auto orderEntry = (*sellItr).second;
    std::cout << "ASK " << (*sellItr).first << " " << *orderEntry << std::endl;
  }
  
  for (auto buyItr = buyOrders.rbegin(); buyItr != buyOrders.rend(); buyItr++)
  {
    auto orderEntry1 = (*buyItr).second;
    std::cout << "BID " << (*buyItr).first << " " << *orderEntry1 << std::endl;
  }
  
  std::cout <<  "--------------------------------------------------- \n"<< std::endl;
}

/*
/ Will liquidate as much ammount of the order as it can if not all 
/ and then will place the remaining command.
*/
void OrderBook::LiquidateCommand(OrderEntry* entry, std::map<float, OrderEntry*>& erasalMap, int& entryVolume)
{
    auto beginItr = erasalMap.begin();
    auto currVolume = beginItr->second->GetVolume();
    auto startVolume = entryVolume;
    if (entryVolume > currVolume)
    {
        erasalMap.erase(beginItr->first);
        entryVolume -= currVolume;
    }
    else
    {
        beginItr->second->SetVolume(currVolume - entryVolume);
        entryVolume = 0;
    }
    if (entry->GetOrderDirection() == OrderDirection::BUY)
    {
      totalBuyVolume -= (startVolume - entryVolume);
    }
    else
    {
      totalSellVolume -= (startVolume - entryVolume);
    }
}

/*
/ If this is the a MARKET command we are looking to liquidate at whatever price is available at the time.
/ Else if this is a LIMIT command we are only either selling if the price is not less than our price or buy if the buy is no more than what we commanded to buy for.
*/
void OrderBook::OrderHelper(OrderEntry* entry, std::map<float, OrderEntry*>& erasalMap, std::map<float, OrderEntry*>& insertionMap)
{
  auto entryVolume = entry->GetVolume();
  if (entry->GetOrderConstraints() == OrderConstraints::MARKET)
  {
      while (entryVolume > 0 && !erasalMap.empty())
      {
          LiquidateCommand(entry, erasalMap, entryVolume);
      }
  }
  else if (entry->GetOrderConstraints() == OrderConstraints::LIMIT)
  {
    while (entryVolume > 0 && !erasalMap.empty() && ((entry->GetOrderDirection() == OrderDirection::BUY) ? entry->GetPrice() >= erasalMap.begin()->first : entry->GetPrice() <= erasalMap.begin()->first))
    {
      LiquidateCommand(entry, erasalMap, entryVolume);
    }
  }

  if (entryVolume > 0)
  {
      insertionMap.insert(std::pair<float, OrderEntry*>(entry->GetPrice(), entry));
      if (entry->GetOrderDirection() == OrderDirection::BUY)
      {
        totalSellVolume += entryVolume;
      }
      else
      {
        totalBuyVolume += entryVolume;
      }
  }
}

/*
/ Calling the appropriate order helper depending whether this is a BUY or a SELL command
*/
void OrderBook::MakeOrder(OrderEntry* entry)
{
    if (entry->GetOrderDirection() == OrderDirection::BUY)
    {
      OrderHelper(entry, sellOrders, buyOrders);
    }
    else
    {
      OrderHelper(entry, buyOrders, sellOrders);
    } 
}

