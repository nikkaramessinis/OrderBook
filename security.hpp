#ifndef _SECURITY_
#define _SECURITY_
#include "orderbook.hpp"

enum class SecurityType
{
  Equity,
  Debt,
  Hybrid
};


class Security
{
public:
  // Constructs the security and initializes an orderbook for it.
  Security(unsigned long _securityID, SecurityType _type, float initialPrice,int volume);

  // Destructs the orderbook
  ~Security();
  
  // Returns a pointer to an orderBook
  OrderBook* GetOrderBook() const;
  
private:
  // Unique identifier for a particular security
  unsigned long securityID;

  // On construct a security is assigned an orderbook.
  OrderBook* orderBook;

  // A security is of some type
  SecurityType type;
};

#endif
