  #include <stdio.h>
  #include "pico/stdlib.h"
  #include "hardware/adc.h"
 
int main() {
    const float conversion_factor = 3.3f / (1 << 12);
    float temp;
    float voltage;
    stdio_init_all();

    adc_init();

    adc_set_temp_sensor_enabled (true);

    adc_select_input(4);


    while (1) {
   
        uint16_t result = adc_read();
        voltage = result * conversion_factor;
        temp=27-(voltage-0.706)/0.001721;
        printf("Raw value: 0x%03x, voltage: %.2f V, La temperatura es: %.2f \n", result, result * conversion_factor, temp);
        
        sleep_ms(500);
    }
}