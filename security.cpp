#include "security.hpp"

Security::Security(unsigned long _securityID, SecurityType _type, float initialPrice,int volume) : securityID(_securityID), type(_type)
{
  orderBook = new OrderBook(initialPrice, volume);
}
Security::~Security()
{
  delete orderBook;
}

OrderBook* Security::GetOrderBook() const
{
  return orderBook;
}
