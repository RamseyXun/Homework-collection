.text
main:
	la	$a0,n1
	la	$a1,n2
	jal	swap
	li	$v0,1	# print n1 and n2; should be 27 and 14
	lw	$a0,n1
	syscall
	li	$v0,11
	li	$a0,' '
	syscall
	li	$v0,1 #$a0:��ʾ������ֵ
	lw	$a0,n2
	syscall
	li	$v0,11 #$a0:��ʾ���ַ�
	li	$a0,'\n'
	syscall
	li	$v0,10	# exit
	syscall

swap:	move	$fp, $sp	#FRAME	POINTER NOW POINTS TO THE TOP OF STACK
	addiu $sp,$sp,-12 # ALLOCATE 12 BYTES IN THE STACK
	sw $a0,4($sp)    #��n1�ĵ�ַ�洢��4($sp)
	sw $a1,8($sp)    #��n2�ĵ�ַ�洢��8($sp)
	lw $a0,0($a0)    #$a0= n1��ֵ
	sw $a0,12($sp)   #temp=n1
 	lw $a0,0($a1)    #$a0=n2��ֵ
 	lw $a1,4($sp)    #$a1= n1�ĵ�ַ
 	sw $a0,0($a1)    # *n1=*n2
	lw $a0,12($sp)    #$a0=temp
 	lw $a1,8($sp)    #$a1= n2�ĵ�ַ
 	sw $a0,0($a1)       # *n2=temp
	addiu $sp,$sp,12 
        jr $31
       
.data
n1:	.word	14
n2:	.word	27
