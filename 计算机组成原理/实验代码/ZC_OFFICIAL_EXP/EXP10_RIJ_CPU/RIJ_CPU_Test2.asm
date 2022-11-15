#主程序：
	add	$a0,	$zero, $zero;			#$a0=0000_0000，源数据区域首址
	addi	$a1,	$zero, 20;			#$a1=0000_0014，目的数据区域首址
	addi	$a2,	$zero, 10;			#$a2=0000_000a，复制的数据个数
	jal	BankMove				#子程序调用
#BankMove子程序：
BankMove:add	$t0,	$a0,	$zero; 			#$t0=源数据区域首址
	add	$t1,	$a1,	$zero;			#$t1=目的数据区域首址
	add	$t2,	$a2,	$zero;			#$t2=数据块长度
Loop1:	lw	$t3,	0($t0);				#$t3=取出数据
	sw	$t3,	0($t1); 			#存数据
	addi	$t2,	$t2,	-1;			#计数值-1
	bne	$t2, $zero, Loop1;			#计数值≠0，则没有复制完，转循环体首部
	jr	$ra					#复制完成，则子程序返回
