/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    xilinxcorelib_ver_m_00000000001358910285_4260203354_init();
    xilinxcorelib_ver_m_00000000001687936702_4200177482_init();
    xilinxcorelib_ver_m_00000000000277421008_2885060861_init();
    xilinxcorelib_ver_m_00000000002055014830_2364875671_init();
    work_m_00000000002489990758_2499224580_init();
    work_m_00000000000592361067_0673647908_init();
    work_m_00000000004001709022_3580741337_init();
    work_m_00000000000405021369_0886308060_init();
    xilinxcorelib_ver_m_00000000000277421008_2784221776_init();
    xilinxcorelib_ver_m_00000000002055014830_4270856842_init();
    work_m_00000000000403262735_1948799799_init();
    work_m_00000000000169194717_2197071003_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000000169194717_2197071003");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
