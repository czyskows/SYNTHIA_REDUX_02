// ----------------------------------------------------------------------------
// AT42QT2160.cpp
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#include "../AT42QT2160.h"


AT42QT2160::Status AT42QT2160::getStatus()
{
  Status status;
  read(RegisterAddresses::AT42QT2160::STATUS,status.bytes);
  return status;
}

bool AT42QT2160::anyTouched(Status status)
{
  return status.keys;
}

bool AT42QT2160::touched(Status status,
  uint8_t key)
{
  return bitRead(status.keys,key);
}

/////////////////////////////////////
////////getSliderValue///////////////
/////////////////////////////////////
uint8_t AT42QT2160::getSliderValue()
{
  uint8_t sv;
  read(RegisterAddresses::AT42QT2160::SLIDER_POSITION,sv);
  return sv;
}

uint8_t AT42QT2160::getNumSliderKeys()
{
  uint8_t svNum;
  read(RegisterAddresses::AT42QT2160::SLIDER_CONTROL,svNum);
  return svNum;
}

void AT42QT2160::setNumKeys(uint8_t nKeys)
{
  write(RegisterAddresses::AT42QT2160::SLIDER_CONTROL,nKeys);
}