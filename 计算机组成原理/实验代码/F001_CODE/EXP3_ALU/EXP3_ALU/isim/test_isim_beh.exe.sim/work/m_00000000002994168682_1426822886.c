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

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "E:/Computer Orgnization/EXP3_ALU/EXP3_ALU/ALU_8F_EXP.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {4294967295U, 0U};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {3U, 0U};
static unsigned int ng5[] = {1543U, 0U};
static unsigned int ng6[] = {2U, 0U};
static unsigned int ng7[] = {2147483648U, 0U};
static unsigned int ng8[] = {2147483647U, 0U};
static unsigned int ng9[] = {4U, 0U};
static unsigned int ng10[] = {5U, 0U};
static unsigned int ng11[] = {6U, 0U};
static unsigned int ng12[] = {7U, 0U};
static unsigned int ng13[] = {305419896U, 0U};
static unsigned int ng14[] = {858989090U, 0U};
static unsigned int ng15[] = {2596069104U, 0U};
static unsigned int ng16[] = {286335522U, 0U};
static int ng17[] = {7, 0};
static int ng18[] = {0, 0};
static int ng19[] = {6, 0};
static int ng20[] = {1, 0};



static void Always_34_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;

LAB0:    t1 = (t0 + 3488U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(34, ng0);
    t2 = (t0 + 4056);
    *((int *)t2) = 1;
    t3 = (t0 + 3520);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(35, ng0);

LAB5:    xsi_set_current_line(36, ng0);
    t4 = (t0 + 1208U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t4, 3);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng9)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng10)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng11)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng12)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB21;

LAB22:
LAB24:
LAB23:    xsi_set_current_line(45, ng0);

LAB34:    xsi_set_current_line(45, ng0);
    t2 = ((char*)((ng15)));
    t3 = (t0 + 2408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(45, ng0);
    t2 = ((char*)((ng16)));
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB25:    goto LAB2;

LAB7:    xsi_set_current_line(37, ng0);

LAB26:    xsi_set_current_line(37, ng0);
    t7 = ((char*)((ng1)));
    t8 = (t0 + 2408);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);
    xsi_set_current_line(37, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    goto LAB25;

LAB9:    xsi_set_current_line(38, ng0);

LAB27:    xsi_set_current_line(38, ng0);
    t3 = ((char*)((ng4)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    xsi_set_current_line(38, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    goto LAB25;

LAB11:    xsi_set_current_line(39, ng0);

LAB28:    xsi_set_current_line(39, ng0);
    t3 = ((char*)((ng7)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    xsi_set_current_line(39, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    goto LAB25;

LAB13:    xsi_set_current_line(40, ng0);

LAB29:    xsi_set_current_line(40, ng0);
    t3 = ((char*)((ng8)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    xsi_set_current_line(40, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    goto LAB25;

LAB15:    xsi_set_current_line(41, ng0);

LAB30:    xsi_set_current_line(41, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    xsi_set_current_line(41, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    goto LAB25;

LAB17:    xsi_set_current_line(42, ng0);

LAB31:    xsi_set_current_line(42, ng0);
    t3 = ((char*)((ng7)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    xsi_set_current_line(42, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    goto LAB25;

LAB19:    xsi_set_current_line(43, ng0);

LAB32:    xsi_set_current_line(43, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    xsi_set_current_line(43, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    goto LAB25;

LAB21:    xsi_set_current_line(44, ng0);

LAB33:    xsi_set_current_line(44, ng0);
    t3 = ((char*)((ng13)));
    t4 = (t0 + 2408);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    xsi_set_current_line(44, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    goto LAB25;

}

static void Always_49_1(char *t0)
{
    char t7[8];
    char t18[8];
    char t19[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t8;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t20;
    char *t21;
    int t22;
    int t23;
    char *t24;
    int t25;
    int t26;
    int t27;
    int t28;
    int t29;

LAB0:    t1 = (t0 + 3736U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 4072);
    *((int *)t2) = 1;
    t3 = (t0 + 3768);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(50, ng0);

LAB5:    xsi_set_current_line(56, ng0);
    t4 = (t0 + 1368U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t4, 3);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB13;

LAB14:
LAB16:
LAB15:    xsi_set_current_line(61, ng0);

LAB18:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    t2 = (t0 + 2248);
    t4 = (t0 + 2248);
    t8 = (t4 + 72U);
    t9 = *((char **)t8);
    t10 = ((char*)((ng17)));
    xsi_vlog_generic_convert_bit_index(t7, t9, 2, t10, 32, 1);
    t17 = (t7 + 4);
    t11 = *((unsigned int *)t17);
    t6 = (!(t11));
    if (t6 == 1)
        goto LAB19;

LAB20:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 1848U);
    t3 = *((char **)t2);
    t2 = (t0 + 2248);
    t4 = (t0 + 2248);
    t8 = (t4 + 72U);
    t9 = *((char **)t8);
    t10 = ((char*)((ng18)));
    xsi_vlog_generic_convert_bit_index(t7, t9, 2, t10, 32, 1);
    t17 = (t7 + 4);
    t11 = *((unsigned int *)t17);
    t6 = (!(t11));
    if (t6 == 1)
        goto LAB21;

LAB22:    xsi_set_current_line(61, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2248);
    t4 = (t0 + 2248);
    t8 = (t4 + 72U);
    t9 = *((char **)t8);
    t10 = ((char*)((ng19)));
    t17 = ((char*)((ng20)));
    xsi_vlog_convert_partindices(t7, t18, t19, ((int*)(t9)), 2, t10, 32, 1, t17, 32, 1);
    t20 = (t7 + 4);
    t11 = *((unsigned int *)t20);
    t6 = (!(t11));
    t21 = (t18 + 4);
    t12 = *((unsigned int *)t21);
    t22 = (!(t12));
    t23 = (t6 && t22);
    t24 = (t19 + 4);
    t13 = *((unsigned int *)t24);
    t25 = (!(t13));
    t26 = (t23 && t25);
    if (t26 == 1)
        goto LAB23;

LAB24:
LAB17:    goto LAB2;

LAB7:    xsi_set_current_line(57, ng0);
    t8 = (t0 + 1528U);
    t9 = *((char **)t8);
    memset(t7, 0, 8);
    t8 = (t7 + 4);
    t10 = (t9 + 4);
    t11 = *((unsigned int *)t9);
    t12 = (t11 >> 0);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t10);
    t14 = (t13 >> 0);
    *((unsigned int *)t8) = t14;
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t15 & 255U);
    t16 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t16 & 255U);
    t17 = (t0 + 2248);
    xsi_vlogvar_assign_value(t17, t7, 0, 0, 8);
    goto LAB17;

LAB9:    xsi_set_current_line(58, ng0);
    t3 = (t0 + 1528U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t3 = (t7 + 4);
    t8 = (t4 + 4);
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 8);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t8);
    t14 = (t13 >> 8);
    *((unsigned int *)t3) = t14;
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t15 & 255U);
    t16 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t16 & 255U);
    t9 = (t0 + 2248);
    xsi_vlogvar_assign_value(t9, t7, 0, 0, 8);
    goto LAB17;

LAB11:    xsi_set_current_line(59, ng0);
    t3 = (t0 + 1528U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t3 = (t7 + 4);
    t8 = (t4 + 4);
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 16);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t8);
    t14 = (t13 >> 16);
    *((unsigned int *)t3) = t14;
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t15 & 255U);
    t16 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t16 & 255U);
    t9 = (t0 + 2248);
    xsi_vlogvar_assign_value(t9, t7, 0, 0, 8);
    goto LAB17;

LAB13:    xsi_set_current_line(60, ng0);
    t3 = (t0 + 1528U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t3 = (t7 + 4);
    t8 = (t4 + 4);
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 24);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t8);
    t14 = (t13 >> 24);
    *((unsigned int *)t3) = t14;
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t15 & 255U);
    t16 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t16 & 255U);
    t9 = (t0 + 2248);
    xsi_vlogvar_assign_value(t9, t7, 0, 0, 8);
    goto LAB17;

LAB19:    xsi_vlogvar_assign_value(t2, t3, 0, *((unsigned int *)t7), 1);
    goto LAB20;

LAB21:    xsi_vlogvar_assign_value(t2, t3, 0, *((unsigned int *)t7), 1);
    goto LAB22;

LAB23:    t14 = *((unsigned int *)t19);
    t27 = (t14 + 0);
    t15 = *((unsigned int *)t7);
    t16 = *((unsigned int *)t18);
    t28 = (t15 - t16);
    t29 = (t28 + 1);
    xsi_vlogvar_assign_value(t3, t2, t27, *((unsigned int *)t18), t29);
    goto LAB24;

}


extern void work_m_00000000002994168682_1426822886_init()
{
	static char *pe[] = {(void *)Always_34_0,(void *)Always_49_1};
	xsi_register_didat("work_m_00000000002994168682_1426822886", "isim/test_isim_beh.exe.sim/work/m_00000000002994168682_1426822886.didat");
	xsi_register_executes(pe);
}
