#include "security.hpp"
#include "orderbook.hpp"
#include "orderentry.hpp"
#include "memory"

int main()
{
  // Example case. Should have been in unit test instead. 
  std::unique_ptr<Security> sec = std::make_unique<Security>(1,SecurityType::Equity, 100.0f, 1000);
  OrderBook* orderBook = (*sec).GetOrderBook();
  orderBook->DebugPrint();
  
  std::unique_ptr<OrderEntry> entry1 = std::make_unique<OrderEntry>(OrderAction::Add, OrderDirection::SELL, OrderConstraints::LIMIT, 100.1f, 100);
  orderBook->MakeOrder(entry1.get());
  orderBook->DebugPrint();
  
  std::unique_ptr<OrderEntry> entry2 = std::make_unique<OrderEntry>(OrderAction::Add, OrderDirection::SELL, OrderConstraints::LIMIT, 100.05f, 500);
  
  std::unique_ptr<OrderEntry> entry3 = std::make_unique<OrderEntry>(OrderAction::Add, OrderDirection::BUY, OrderConstraints::LIMIT, 99.95f, 100);
  std::unique_ptr<OrderEntry> entry4 = std::make_unique<OrderEntry>(OrderAction::Add, OrderDirection::BUY, OrderConstraints::LIMIT, 99.9f, 50);
  std::unique_ptr<OrderEntry> entry5 = std::make_unique<OrderEntry>(OrderAction::Add, OrderDirection::BUY, OrderConstraints::LIMIT, 99.85f, 50);

  orderBook->MakeOrder(entry2.get());
  orderBook->MakeOrder(entry3.get());
  orderBook->MakeOrder(entry4.get());
  orderBook->MakeOrder(entry5.get());
  orderBook->DebugPrint();
  
  std::unique_ptr<OrderEntry> entry6 = std::make_unique<OrderEntry>(OrderAction::Add, OrderDirection::BUY, OrderConstraints::MARKET, 100);
   orderBook->MakeOrder(entry6.get());
  orderBook->DebugPrint();
  
  std::unique_ptr<OrderEntry> entry7 = std::make_unique<OrderEntry>(OrderAction::Add, OrderDirection::BUY, OrderConstraints::LIMIT, 100.02f, 100);  
  orderBook->MakeOrder(entry7.get());
  orderBook->DebugPrint();
  
  std::unique_ptr<OrderEntry> entry8 = std::make_unique<OrderEntry>(OrderAction::Add, OrderDirection::SELL, OrderConstraints::MARKET, 175);  
  orderBook->MakeOrder(entry8.get());
  orderBook->DebugPrint();
  
}
