#include "ch.h"
#include "hal.h"
#include "blinky.h"
#include "uart_scp.h"
#include "obldcpwm.h"
#include "obldcadc.h"
#include "obldc_catchmotor.h"

int main(void) {
	int temp;
	//Start System
	halInit();
	chSysInit();
	//startBlinkyBlue();
	startBlinkyGreen();
	//startBlinkyRed();
	uartSCPInit();
	motor_start_timer();
	startmyadc();
	v_bat_current_conversion();
    chThdSleepMicroseconds(500);
    temp = get_vbat_sample();//UGLY!!
    chThdSleepMicroseconds(500);
	temp = catchmotor_setup();
	startRampMotorThread();
	obldc_can_init(); // Start CAN bus
	// Just idle on the main loop
	while (TRUE) {
// palTogglePad(GPIOB, GPIOB_LEDG);
// palTogglePad(GPIOB, GPIOB_LEDR);
//uartStartSend(&UARTD1, 13, "Starting...\r\n");
		chThdSleepMilliseconds(1000);
		//resetadccount();
	}
}
