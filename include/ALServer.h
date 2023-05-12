#ifndef ALServer_h
#define ALServer_h

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>
#include "data.h"

// структура результатов
struct Metering
{
  float accel30;
  float accel50;
  float accel60;
  float accel100;
  float accel150;
  float accel50_150;
};

class ALServer
{
  private:
    Metering* _meterings;
    size_t _n;
    char buf30[5], buf60[5], buf100[5], buf50_150[5];

  public:
    ALServer();
    void createAP();
    void serverHandle();
    void setData(Metering* meterings, size_t n);

    void handleRoot();
    void handleStyle();
    void handleResults();
};

#endif
