#pragma once
#include <Arduino.h>

#include "data.h"         // данные
#include "Time.h"         // часы
// #include "time.h"
#include "timeRandom.h"   // случайные числа по времени
//#include "fastRandom.h"   // быстрый рандом
#include "Button.h"       // библа кнопки
#include "palettes.h"     // палитры
// #include "NTPClient-Gyver.h"  // сервер времени (модиф)
#include <GyverNTP.h>
#include "timerMillis.h"  // таймер миллис
#include "VolAnalyzer.h"  // анализатор громкости
#include "FFT_C.h"        // фурье
#include <FastLED.h>      // лента
#include <WiFi.h>  // базовая либа есп
#include <WiFiUdp.h>      // общение по UDP
#include <EEPROM.h>       // епром
// #include "ESP8266httpUpdate.h"  // OTA
#include <ArduinoOTA.h>
#include "mString.h"      // стринг билдер
#include "Clap.h"         // обработка хлопков

// ------------------- ДАТА --------------------
Config cfg;
Preset preset[MAX_PRESETS];
Dawn dawn;
Palette pal;
WiFiServer server(80);
WiFiUDP Udp;
WiFiUDP ntpUDP;
IPAddress broadIP;
// NTPClient ntp(ntpUDP);
GyverNTP ntp(3);
CRGB leds[MAX_LEDS];
TimeESP now;
// struct tm timeinfo
Button btn(BTN_PIN);
timerMillis EEtmr(EE_TOUT), turnoffTmr, connTmr(120000ul), dawnTmr, holdPresTmr(30000ul), blinkTmr(300);
timerMillis effTmr(30, true), onlineTmr(500, true), postDawn(10 * 60000ul);
TimeRandom trnd;
VolAnalyzer vol(A0), low, high;
FastFilter phot;
Clap clap;