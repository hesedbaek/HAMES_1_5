#include "pir_sensor.h"
#include "mainwindow.h"

extern int gPir;

PIR_Sensor::PIR_Sensor(QObject *parent) : QThread(parent)
{
   pinMode(PIR_GPIO_IN, INPUT);
}

void PIR_Sensor::run()
{
    while(!m_stopFlag)
    {
        // Insert Your Code
        gPir = digitalRead(PIR_GPIO_IN);

        //
       emit ThreadEnd(gPir);
       sleep(1);
    }
}

uint8_t PIR_Sensor::getPirData()
{
    return _detected;
}

void PIR_Sensor::stop()
{
    m_stopFlag = true;
}
