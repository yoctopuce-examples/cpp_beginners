#include <iostream>

#include "yocto_api.h"
#include "yocto_temperature.h"
#include "yocto_relay.h"

using namespace std;

int main(int argc, const char* argv[])
{
  string errmsg;
  if (YAPI::RegisterHub("usb", errmsg) != YAPI::SUCCESS) {
    cerr << "RegisterHub error: " << errmsg << endl;
    return 1;
  }

  YTemperature* t = YTemperature::FirstTemperature();
  if (t == NULL) {
    cerr << "No temperature sensor found" << endl;
    return 1;
  }

  YRelay* r = YRelay::FirstRelay();
  if (r == NULL) {
    cerr << "No relay found" << endl;
    return 1;
  }

  while (t->isOnline() && r->isOnline()) {
    double value = t->get_currentValue();
    if (value > 25) {
      r->set_state(YRelay::STATE_B);
    }
    if (value < 24) {
      r->set_state(YRelay::STATE_A);
    }
    YAPI::Sleep(100, errmsg);
  }
  YAPI::FreeAPI();
  return 0;
}
