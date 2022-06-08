/**
 * FICHIER SOURCE TEMPERATURE
 */
#include "sl_sensor_rht.h"
#include "temperature.h"

int16_t get_temp_BLE(void){
  uint32_t rh = 0;
  int32_t rt = 0;
  uint32_t* raw_h = &rh;
  int32_t* raw_t = &rt;
  //on attend la fin de la lecture
  while (sl_sensor_rht_get(raw_h, raw_t));
  //on récupère la température au format BLE:
  int16_t ble = rt*0.1;
  //int16_t ble = (int16_t)rt*0.1;
  return ble;
}
