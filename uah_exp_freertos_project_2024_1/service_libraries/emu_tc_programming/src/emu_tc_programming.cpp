/*
 * emu_tc_programming.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: user
 */

#include <public/emu_hw_timecode_drv_v1.h>
#include <public/emu_sc_channel_drv_v1.h>
#include <public/emu_gss_v1.h>

#define FT_SOLO_EPD_ICU_SERV_17_0010
#define FT_SOLO_EPD_ICU_SERV_9_0020
#define FT_UAH_EXP_SERV_129_0040
#define FT_SOLO_EPD_ICU_SERV_3_UPDATE_INTERVAL_TC_0050


//TODO

/*#ifdef FT_SOLO_EPD_ICU_SERV_17_0010

EmuGSS_TCProgram17_1 prog_FT_0010_step_0(UNITIME_AFTER_POWER_ON + 6,
					"FT_SOLO_EPD_ICU_SERV_17_0010 step 0, Connection Test");


#endif


#ifdef FT_SOLO_EPD_ICU_SERV_9_0020

#define FT_SOLO_EPD_ICU_SERV_9_0020_TIME 200000

EmuGSS_TCProgram9_129 prog_FT_0020_step_0(UNITIME_AFTER_POWER_ON + 10 ,
		"FT_SOLO_EPD_ICU_SERV_9_0020 step 0, Update UniTime Test",
		FT_SOLO_EPD_ICU_SERV_9_0020_TIME);



#endif

*/

// Cambio de frecuencia
#ifdef FT_SOLO_EPD_ICU_SERV_3_UPDATE_INTERVAL_TC_0050

#define FT_SOLO_EPD_ICU_SERV_3_0050_TIME_step0 (UNITIME_AFTER_POWER_ON + 20)
//#define FT_SOLO_EPD_ICU_SERV_3_0050_TIME_step1 (FT_SOLO_EPD_ICU_SERV_3_0050_TIME_step0 + 10)


EmuGSS_TCProgram3_31 prog_FT_0050_step_0(FT_SOLO_EPD_ICU_SERV_3_0050_TIME_step0,
		"FT_SOLO_EPD_ICU_SERV_3_0050 step 0, Update SID 10 Rate to 5",10,5);




#endif


//prueba telecomando [129,1] y [129,2]
#ifdef FT_UAH_EXP_SERV_129_0040


EmuGSS_TCProgram129_1 prog_FT_0040_step_0(UNITIME_AFTER_POWER_ON + 5,
					"FT_UAH_EXP_SERV_129_00XX step 0, Set Kp", 0.3, 0.3);

EmuGSS_TCProgram129_2 prog_FT_0040_step_1(UNITIME_AFTER_POWER_ON + 10,
					"FT_UAH_EXP_SERV_129_00XX step 0, Set Command Vx and Vy "
					, 0.5, 0.5);

#endif
