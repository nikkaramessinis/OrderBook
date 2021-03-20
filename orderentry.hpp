#ifndef _ORDER_ENTRY
#define _ORDER_ENTRY

#include <iostream>

enum class OrderAction
{
  Add,
  Modify,
  Delete
};

enum class OrderDirection{
  BUY,
  SELL
};

enum class OrderConstraints
{
  LIMIT,
  MARKET
};

class OrderEntry
{
  static int curOrderID;
public:
  OrderEntry(OrderAction _orderAction,OrderDirection _orderDirection,OrderConstraints _orderConstraints,float _price, int _volume);

  OrderEntry(OrderAction _orderAction,OrderDirection _orderDirection,OrderConstraints _orderConstraints, int _volume);
  
  int GetOrderID() const;
  
  OrderAction GetOrderAction() const;
  
  OrderDirection GetOrderDirection() const;
  
  OrderConstraints GetOrderConstraints() const;

  int GetSecurityID() const;
  
  float GetPrice() const;

  int GetVolume() const;

  void SetVolume(int vol);

private:
  
  int orderID;
  
  OrderAction orderAction;
  
  OrderDirection orderDirection;
  
  OrderConstraints orderConstraints;
  
  int securityID;
  
  float price;
  
  int volume;
  
public:
  friend std::ostream& operator<<(std::ostream& os, const OrderEntry& o);
};

#endif







