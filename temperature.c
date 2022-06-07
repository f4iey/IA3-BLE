/**
 * FICHIER SOURCE TEMPERATURE
 */
#include "sl_sensor_rht.h"
#include "temperature.h"

short get_temp_BLE(void){
  uint32_t rh = 0;
  int32_t rt = 0;
  uint32_t* raw_h = &rh;
  int32_t* raw_t = &rt;
  //on attend la fin de la lecture
  while (sl_sensor_rht_get(raw_h, raw_t));
  //on récupère la température au format BLE:
  short ble = 0.01*(short)rt - 273;
  return ble;
}
