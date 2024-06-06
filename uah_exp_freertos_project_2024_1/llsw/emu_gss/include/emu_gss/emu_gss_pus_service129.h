/*
 * emu_gss_pus_service129.h
 *
 *  Created on: Jun 3, 2024
 *      Author: atcsol
 */

#ifndef LLSW_EMU_GSS_INCLUDE_EMU_GSS_EMU_GSS_PUS_SERVICE129_H_
#define LLSW_EMU_GSS_INCLUDE_EMU_GSS_EMU_GSS_PUS_SERVICE129_H_



class EmuGSS_TCProgram129_1:public EmuGSS_TCProgram{
	float mCVx;
	float mCVy;


	virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor);

public:

	EmuGSS_TCProgram129_1(uint32_t uniTime2YK,
                 const char * brief,float CVx,float CVy);


};

class EmuGSS_TCProgram129_2:public EmuGSS_TCProgram{

	float mKpx;
	float mKpy;


	virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor);

public:

	EmuGSS_TCProgram129_2(uint32_t uniTime2YK,
                 const char * brief,float Kpx,float Kpy);


};



/*
void EmuGSS_ShowServ129TM(const struct tm_descriptor *pTMDescriptor);


class GSSServ129TMHandler:public GSSTMHandler{

	friend void EmuGSS_ShowServ129TM(const struct tm_descriptor * );

protected:

	GSSServ129TMHandler(const uint8_t * pTMBytes);

	void ShowTM();

	void ShowTM_20_2();


};
*/


#endif /* LLSW_EMU_GSS_INCLUDE_EMU_GSS_EMU_GSS_PUS_SERVICE129_H_ */
