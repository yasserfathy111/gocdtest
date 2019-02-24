#include "rvs.h"
#include "rvs_ipoint.h"

//typedef struct _Ifx_STM_TIM0_Bits
//{
//    unsigned int STM31_0 : 32;                /**< \brief [31:0] System Timer Bits [31:0] (r) */
//} Ifx_STM_TIM0_Bits;
//
//typedef union
//{
//    unsigned int      U;                    /**< \brief Unsigned access */
//    signed int        I;                    /**< \brief Signed access */
//    Ifx_STM_TIM0_Bits B;                    /**< \brief Bitfield access */
//} Ifx_STM_TIM0;
//
//#define STM0_TIM0    /*lint --e(923)*/ (*(volatile Ifx_STM_TIM0 *)0xF0000010u)


//#pragma section "rvs"
unsigned int rvs_timestamps[RVS_TIMESTAMP_COUNT];
unsigned int rvs_ipoint_id[RVS_TIMESTAMP_COUNT];
//#pragma section
unsigned int rvs_ipoint_iterator;
unsigned int memory_dump_count=0;
unsigned int time_correction = 0;

/**************************************************************
 * Instrumentation point
 **************************************************************/
void RVS_Ipoint(unsigned int id)
{
rvs_timestamps[rvs_ipoint_iterator] = STM0_TIM0.U - time_correction;
rvs_ipoint_id[rvs_ipoint_iterator] = id;

rvs_ipoint_iterator ++;

if(rvs_ipoint_iterator==RVS_TIMESTAMP_COUNT)
{
	RVS_Output();
}
}

/*************************************************************
 *RVS_Init: Initialise the instrumentation library
 *************************************************************/
void RVS_Init (void)
{
}
/**************************************************************
 * RVS_Output: Output the current coverage data
 **************************************************************/
void RVS_Output (void)
{
	unsigned int t1=0;
	unsigned int t2=0;

	t1 = STM0_TIM0.U;
	memory_dump_count++;
	rvs_ipoint_iterator=0;
	memset(&rvs_timestamps, 0, RVS_TIMESTAMP_COUNT*4);
	memset(&rvs_ipoint_id, 0, RVS_TIMESTAMP_COUNT*4);
	t2 = STM0_TIM0.U;

	time_correction += t2 - t1;
}
/*************************************************************
 *RVS_Terminate:
 *************************************************************/
void RVS_Terminate (void)
{
	rvs_ipoint_iterator = 0;
}