#include "pico/stdlib.h"

int main() {
    const uint LED_PIN = 25;  // onboard LED on most Pico boards
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        gpio_put(LED_PIN, 1);  // ON

        // 500 * 10^-3 = 0.5 secs
        //To get the value in seconds
        sleep_ms(500);
        gpio_put(LED_PIN, 0);  // OFF
        sleep_ms(500);
    }
}