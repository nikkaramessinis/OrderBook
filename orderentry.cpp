#include "orderentry.hpp"
#include <cassert>

int OrderEntry::curOrderID = 0;

OrderEntry::OrderEntry(OrderAction _orderAction,OrderDirection _orderDirection,OrderConstraints _orderConstraints,float _price, int _volume) : orderAction(_orderAction), orderDirection(_orderDirection), orderConstraints(_orderConstraints), securityID(0), price(_price), volume(_volume)
{
  orderID = curOrderID++;
}

OrderEntry::OrderEntry(OrderAction _orderAction,OrderDirection _orderDirection,OrderConstraints _orderConstraints, int _volume) : orderAction(_orderAction), orderDirection(_orderDirection), orderConstraints(_orderConstraints), securityID(0), price(0), volume(_volume)
{
  orderID = curOrderID++;
}  

int OrderEntry::GetOrderID() const
{
  return orderID;
}

OrderAction OrderEntry::GetOrderAction() const
{
  return orderAction;
}

OrderDirection OrderEntry::GetOrderDirection() const
{
  return orderDirection;
}


OrderConstraints OrderEntry::GetOrderConstraints() const
{
  return orderConstraints;
}

int OrderEntry::GetSecurityID() const
{
  return securityID;
}

float OrderEntry::GetPrice() const
{
  return price;
}

int OrderEntry::GetVolume() const
{
  return volume;
}

void OrderEntry::SetVolume(int vol)
{
  assert(("Volume can't ever be less than zero",  vol>0));
  volume = vol;
}

std::ostream& operator<<(std::ostream& os, const OrderEntry& o)
{
  os << o.volume << std::endl;
  return os;
}
