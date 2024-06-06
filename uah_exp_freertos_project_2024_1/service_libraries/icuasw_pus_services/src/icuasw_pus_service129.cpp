/*
 * icuasw_pus_Service128.cpp
 *
 *  Created on: Dec 22, 2023
 *      Author: user
 */

#include <stdio.h>

#include <public/icuasw_pus_services_iface_v1.h>
#include <public/emu_uah_exp_kinematics.h>
#include <public/adc_drv.h>

float PUSService129::sFx;
float PUSService129::sFy;
float PUSService129::sFz;

float PUSService129::sCVx = 0;
float PUSService129::sCVy = 0;
//It is not used in Guindance Mode
float PUSService129::sCVz = 0;

float PUSService129::sKpx = 0.1;
float PUSService129::sKpy = 0.1;
float PUSService129::sKpz = 0.1;

class UAHExpEmuKinematic PUSService129::mUAHExpEmulator;


//iniciamos el 129
void PUSService129::Init(){

	SystemDataPool::Init();
}

void PUSService129::ExecTC(CDTCHandler &tcHandler, CDTMList &tmList) {
 //TODO

	switch (tcHandler.GetSubType()) {
		case (1):
		Exec129_1TC(tcHandler, tmList);
			break;
		case (2):
		Exec129_2TC(tcHandler, tmList);
			break;


	default:
		break;
	}

}

void PUSService129::Exec129_1TC(CDTCHandler &tcHandler, CDTMList &tmList) {
	//TODO
	//Valor de la nueva velocidad
		float Vx_Value=tcHandler.GetNextFloat();
		float Vy_Value = tcHandler.GetNextFloat();
		sCVx= Vx_Value;
		sCVy= Vy_Value;

		PUSService1::BuildTM_1_7(tcHandler, tmList);



}

void PUSService129::Exec129_2TC(CDTCHandler &tcHandler, CDTMList &tmList) {

	//TODO
	//Nuevos valores de las constantes de proporcionalidad
		float Kx_Value=tcHandler.GetNextFloat();
		float Ky_Value = tcHandler.GetNextFloat();

		sKpx = Kx_Value;
		sKpy = Ky_Value;

		PUSService1::BuildTM_1_7(tcHandler, tmList);

}

const float ActuatorMAX_X_Y_Newtons = 0.100; //100 MiliNewtons
const float ActuatorMAX_Z_Newtons = 1.000; //1 Newton

float PUSService129::LimitActuator(float F, float Limit) {

	float maxF = F;
	if (maxF > Limit)
		maxF = Limit;
	else if (maxF < (-Limit)) {
		maxF = -Limit;
	}
	return maxF;
}

void PUSService129::GuidanceControl() {

	struct UAHExpKinematic currentKinematic;

	//Update Kinematic with the previous values of Fx, sFy y sFz.

	currentKinematic = mUAHExpEmulator.EmuKinematic(sFx, sFy, sFz);

	//Calculate Forces to apply in the next period:
	sFx = (sCVx - currentKinematic.Vx) * sKpx;
	sFy = (sCVy - currentKinematic.Vy) * sKpy;
	//sFz = (sCVz - currentVeloc.Vz) * sKpz;

	//
	sFx=LimitActuator(sFx,ActuatorMAX_X_Y_Newtons);
	sFy=LimitActuator(sFy,ActuatorMAX_X_Y_Newtons);

	//Fx is only due to Gravity
	/*
	if (sFz >= 0)
		sFz = 0;
	else {
		sFz=LimitActuator(sFz,ActuatorMAX_Z_Newtons);

	}*/

	uint16_t VxScaled, VyScaled, VzScaled, MassScaled;

	//Store in SystemDataPool a scaled version of Vx, Vy, Vz and Mass
	VxScaled = currentKinematic.Vx * 32768 + 32768;
	VyScaled = currentKinematic.Vy * 32768 + 32768;
	VzScaled = currentKinematic.Vz * 65; //
	MassScaled = currentKinematic.Mass* 65535;

	//Set SystemDataPool parameters
	SystemDataPool::SetFromInt16(5, VxScaled);
	SystemDataPool::SetFromInt16(6, VyScaled);
	SystemDataPool::SetFromInt16(7, VzScaled);
	SystemDataPool::SetFromInt16(8, MassScaled);

}
