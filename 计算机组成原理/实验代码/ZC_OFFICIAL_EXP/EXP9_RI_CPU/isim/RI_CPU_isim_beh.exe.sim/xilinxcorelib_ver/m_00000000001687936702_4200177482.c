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

/* This file is designed for use with ISim build 0x2f00eba5 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif



static void Always_1930_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 2764U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 2960);
    *((int *)t2) = 1;
    t3 = (t0 + 2792);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = (t0 + 1092U);
    t5 = *((char **)t4);
    t4 = (t0 + 1596);
    xsi_vlogvar_assign_value(t4, t5, 0, 0, 32);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    t2 = (t0 + 1872);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 6);
    t2 = (t0 + 1184U);
    t3 = *((char **)t2);
    t2 = (t0 + 1688);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 1);
    t2 = (t0 + 1276U);
    t3 = *((char **)t2);
    t2 = (t0 + 1780);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 1);
    goto LAB2;

}


extern void xilinxcorelib_ver_m_00000000001687936702_4200177482_init()
{
	static char *pe[] = {(void *)Always_1930_0};
	xsi_register_didat("xilinxcorelib_ver_m_00000000001687936702_4200177482", "isim/RI_CPU_isim_beh.exe.sim/xilinxcorelib_ver/m_00000000001687936702_4200177482.didat");
	xsi_register_executes(pe);
}
