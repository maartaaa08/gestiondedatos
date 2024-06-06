//##############################################################################
//###############     This file has been generated by EDROOM     ###############
//##############################################################################
 
#ifndef EDROOMDEPLOYMENT_H_
#define EDROOMDEPLOYMENT_H_
 
#include <edroom_glue/edroomdf.h>
#include <public/edroomsl_iface_v1.h>
 
 
//******************************************************************************
// include deployment edroom components
 
#include <public/uahexplorer_iface_v1.h>
#include <public/ccexplorermanager_iface_v1.h>
#include <public/cctm_channelctrl_iface_v1.h>
#include <public/cchk_fdirmng_iface_v1.h>
#include <public/ccbkgtcexec_iface_v1.h>
#include <public/ccguidance_iface_v1.h>
// ***********************************************************************
// class CEDROOMSystemMemory
// ***********************************************************************
 
class CEDROOMSystemMemory{
 
	//!Messages Memory of component comp1
	CEDROOMMessage	comp1Messages[10];
	bool	comp1MessagesMarks[10];
	CEDROOMQueue::CQueueNode	comp1QueueNodes[13];
	bool	comp1QueueNodesMarks[13];
 
	//!Messages Memory of component comp2
	CEDROOMMessage	comp2Messages[10];
	bool	comp2MessagesMarks[10];
	CEDROOMQueue::CQueueNode	comp2QueueNodes[11];
	bool	comp2QueueNodesMarks[11];
 
	//!Messages Memory of component comp3
	CEDROOMMessage	comp3Messages[10];
	bool	comp3MessagesMarks[10];
	CEDROOMQueue::CQueueNode	comp3QueueNodes[10];
	bool	comp3QueueNodesMarks[10];
 
	//!Messages Memory of component comp4
	CEDROOMMessage	comp4Messages[10];
	bool	comp4MessagesMarks[10];
	CEDROOMQueue::CQueueNode	comp4QueueNodes[14];
	bool	comp4QueueNodesMarks[14];
 
	//!Messages Memory of component comp5
	CEDROOMMessage	comp5Messages[10];
	bool	comp5MessagesMarks[10];
	CEDROOMQueue::CQueueNode	comp5QueueNodes[11];
	bool	comp5QueueNodesMarks[11];
 
	//!Messages Memory of component comp6
	CEDROOMMessage	comp6Messages[10];
	bool	comp6MessagesMarks[10];
	CEDROOMQueue::CQueueNode	comp6QueueNodes[14];
	bool	comp6QueueNodesMarks[14];
 
	public:
 
	UAHExplorer::CEDROOMMemory comp1Memory;
	CCExplorerManager::CEDROOMMemory comp2Memory;
	CCTM_ChannelCtrl::CEDROOMMemory comp3Memory;
	CCHK_FDIRMng::CEDROOMMemory comp4Memory;
	CCBKGTCExec::CEDROOMMemory comp5Memory;
	CCGuidance::CEDROOMMemory comp6Memory;
 
//!Set Memory
	void SetMemory();
};
 
class CEDROOMSystemCommSAP{
 
	 friend class CEDROOMSystemDeployment;
//!Communication Service Access Point
 
	CEDROOMLocalCommSAP m_localCommSAP;
 
 
//!Conections
 
	CEDROOMLocalConnection connections[7];
 
	UAHExplorer   * mp_comp1;
	CCExplorerManager   * mp_comp2;
	CCTM_ChannelCtrl   * mp_comp3;
	CCHK_FDIRMng   * mp_comp4;
	CCBKGTCExec   * mp_comp5;
	CCGuidance   * mp_comp6;
 
 
//!Set Components
 
	void SetComponents(UAHExplorer   *p_comp1,
							CCExplorerManager   *p_comp2,
							CCTM_ChannelCtrl   *p_comp3,
							CCHK_FDIRMng   *p_comp4,
							CCBKGTCExec   *p_comp5,
							CCGuidance   *p_comp6);
 
 
//Signal Conversion
 
	static TEDROOMSignal C6Guidance_PGuidanceCtrl__C2ExplorerManager_PGuidanceCtrl(TEDROOMSignal signal);
	static TEDROOMSignal C2ExplorerManager_PGuidanceCtrl__C6Guidance_PGuidanceCtrl(TEDROOMSignal signal);
 
//Signal Conversion
 
	static TEDROOMSignal C6Guidance_PTMChannelCtrl__C3TM_ChannelCtrl_PTMChannelCtrl4(TEDROOMSignal signal);
	static TEDROOMSignal C3TM_ChannelCtrl_PTMChannelCtrl4__C6Guidance_PTMChannelCtrl(TEDROOMSignal signal);
 
//Signal Conversion
 
	static TEDROOMSignal C5BKGTCExec_PBKGExecCtrl__C2ExplorerManager_PBKGExecCtrl(TEDROOMSignal signal);
	static TEDROOMSignal C2ExplorerManager_PBKGExecCtrl__C5BKGTCExec_PBKGExecCtrl(TEDROOMSignal signal);
 
//Signal Conversion
 
	static TEDROOMSignal C3TM_ChannelCtrl_PTMChannelCtrl3__C5BKGTCExec_PTMChannelCtrl(TEDROOMSignal signal);
	static TEDROOMSignal C5BKGTCExec_PTMChannelCtrl__C3TM_ChannelCtrl_PTMChannelCtrl3(TEDROOMSignal signal);
 
//Signal Conversion
 
	static TEDROOMSignal C4HK_FDIRMng_PTMChannelCtrl__C3TM_ChannelCtrl_PTMChannelCtrl2(TEDROOMSignal signal);
	static TEDROOMSignal C3TM_ChannelCtrl_PTMChannelCtrl2__C4HK_FDIRMng_PTMChannelCtrl(TEDROOMSignal signal);
 
//Signal Conversion
 
	static TEDROOMSignal C2ExplorerManager_PHK_FDIRCtrl__C4HK_FDIRMng_PHK_FDIRCtrl(TEDROOMSignal signal);
	static TEDROOMSignal C4HK_FDIRMng_PHK_FDIRCtrl__C2ExplorerManager_PHK_FDIRCtrl(TEDROOMSignal signal);
 
//Signal Conversion
 
	static TEDROOMSignal C2ExplorerManager_PTMChannelCtrl__C3TM_ChannelCtrl_PTMChannelCtrl(TEDROOMSignal signal);
	static TEDROOMSignal C3TM_ChannelCtrl_PTMChannelCtrl__C2ExplorerManager_PTMChannelCtrl(TEDROOMSignal signal);
 
 
//!Register Interfaces
	void RegisterInterfaces();
 
//!Set Local Connections
	void SetLocalConnections();
 
//!Set Remote Connections
	void SetRemoteConnections();
 
//!Set Connections
	void SetConnections();
 
};
 
class CEDROOMSystemDeployment{
 
//!Kernel
	Pr_Kernel	kernel;
 
#ifdef CONFIG_EDROOMDEPLOYMENT_NEED_TASK
 
//!Main Task
static Pr_TaskRV_t main_task(Pr_TaskP_t);
 
#endif
	CEDROOMSystemMemory   systemMemory;
	CEDROOMSystemCommSAP  systemCommSAP;
 
	UAHExplorer   * mp_comp1;
	CCExplorerManager   * mp_comp2;
	CCTM_ChannelCtrl   * mp_comp3;
	CCHK_FDIRMng   * mp_comp4;
	CCBKGTCExec   * mp_comp5;
	CCGuidance   * mp_comp6;
 
	public:
 
	CEDROOMSystemDeployment();
 
//!Deployment Configuration
	void Config(UAHExplorer   *p_comp1,
					CCExplorerManager   *p_comp2,
					CCTM_ChannelCtrl   *p_comp3,
					CCHK_FDIRMng   *p_comp4,
					CCBKGTCExec   *p_comp5,
					CCGuidance   *p_comp6);
 
//!Deployment Start
	void Start();
 
//!StartComponents
	void StartComponents();
//!Config Components
 
	UAHExplorer::CEDROOMMemory 		* GetComp1Memory(){return &systemMemory.comp1Memory;}
	CCExplorerManager::CEDROOMMemory 		* GetComp2Memory(){return &systemMemory.comp2Memory;}
	CCTM_ChannelCtrl::CEDROOMMemory 		* GetComp3Memory(){return &systemMemory.comp3Memory;}
	CCHK_FDIRMng::CEDROOMMemory 		* GetComp4Memory(){return &systemMemory.comp4Memory;}
	CCBKGTCExec::CEDROOMMemory 		* GetComp5Memory(){return &systemMemory.comp5Memory;}
	CCGuidance::CEDROOMMemory 		* GetComp6Memory(){return &systemMemory.comp6Memory;}
 
};
#endif
