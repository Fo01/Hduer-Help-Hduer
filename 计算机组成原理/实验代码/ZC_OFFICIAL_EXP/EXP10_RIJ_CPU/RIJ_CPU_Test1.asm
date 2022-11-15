#baseAddr 0000
	add	$t0,	$zero,	$zero;			#$8=0000_0000，累加器
	add	$t1,	$zero,	$zero;			#$9=0000_0000，变址指针
	addi	$t2,	$zero,	20;			#$10=0000_0014，计数器
Loop1:	lw 	$t3,	0x10($t1)			#$11=mem(0000_0010+$9)
	add	$t0,	$t0,	$t3			#$8=累加和
	addi	$t1,	$t1,	4			#指针+4
	addi	$t2,	$t2,	-1			#$10=计数器-1
	beq 	$t2,	$zero,	Loop2			#$10等于0，则跳出循环
	j	Loop1
Loop2:	sw $t0,	0x30($zero)				#存数到0x30H单元
	lw $t4, 0x30($zero)
