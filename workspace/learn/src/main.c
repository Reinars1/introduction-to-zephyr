#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define LED_NODE DT_ALIAS(led)
#define BUTTON_NODE DT_ALIAS(button)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED_NODE, gpios);
static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(BUTTON_NODE, gpios);

int main() {

    if (!gpio_is_ready_dt(&led)) {
        while(1) {
            printf("Led not initialized");
        }
    }
    gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE);

    if (!gpio_is_ready_dt(&button)) {
        while(1) {
            printf("Button not initialized");
        }
    }
    gpio_pin_configure_dt(&button, GPIO_INPUT);

    while (1) {
        int button_state = gpio_pin_get_dt(&button);
        gpio_pin_set_dt(&led, button_state);
        printk("Button state: %d\n", button_state);
        k_msleep(10);

    }

    return 0;
}