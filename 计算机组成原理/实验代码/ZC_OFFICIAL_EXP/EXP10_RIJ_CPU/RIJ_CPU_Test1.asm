#baseAddr 0000
	add	$t0,	$zero,	$zero;			#$8=0000_0000���ۼ���
	add	$t1,	$zero,	$zero;			#$9=0000_0000����ַָ��
	addi	$t2,	$zero,	20;			#$10=0000_0014��������
Loop1:	lw 	$t3,	0x10($t1)			#$11=mem(0000_0010+$9)
	add	$t0,	$t0,	$t3			#$8=�ۼӺ�
	addi	$t1,	$t1,	4			#ָ��+4
	addi	$t2,	$t2,	-1			#$10=������-1
	beq 	$t2,	$zero,	Loop2			#$10����0��������ѭ��
	j	Loop1
Loop2:	sw $t0,	0x30($zero)				#������0x30H��Ԫ
	lw $t4, 0x30($zero)
