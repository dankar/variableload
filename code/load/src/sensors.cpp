#include <OneWire.h> 
#include <DallasTemperature.h>
#include "pins.h"

OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);

uint8_t num_sensors = 0;

void one_wire_setup()
{
    sensors.begin(); 
    num_sensors = sensors.getDeviceCount();
    sensors.setResolution(12);
    sensors.setWaitForConversion(true);
}

uint8_t one_wire_get_num_sensors()
{
    return num_sensors;
}

bool one_wire_get_temperatures(int16_t *temps)
{
    DeviceAddress deviceAddress;

    sensors.requestTemperatures();

    oneWire.reset_search();
    uint8_t index = 0;

    while(oneWire.search(deviceAddress))
    {
        if(sensors.validAddress(deviceAddress))
        {
            if(sensors.validFamily(deviceAddress))
            {
                if(index == num_sensors)
                {
                    return false;
                }
                temps[index] = sensors.getTemp(deviceAddress);
                if(temps[index] == DEVICE_DISCONNECTED_RAW)
                {
                    return false;
                }
                index++;
            }
        }
    }

    return index == num_sensors;
}