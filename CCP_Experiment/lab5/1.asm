.data 0x0
z:.space 192 #ѧ��15352408����int z[48],ռ�ڴ�4*48=192?
str:.asciiz " " #������
.text 0x3000 
main:
	la $s0,z #$s0����ʾz[k]�ĵ�ַ
	li $t0,0 #$t0Ϊk����ʼΪ0 
	li $t1,56 #$t2ΪY����ʼֵ56
loop:
	slti $t2,$t0,48 #�ж�k�Ƿ���48
	beq $t2,$0,exit #��k���ڵ���50,ѭ������,�˳�
	srl $t3,$t0,2  #k/4
	addi $t3,$t3,210 #k/4+210
	sll $t3,$t3,4 #16*(k/4+210)
	sub $t3,$t1,$t3 #y-16*(k/4+210)
	sw  $t3,0($s0) #д��z[k]
	
	li $v0,1  #���
	addi $a0,$s0,0 
	syscall
	
	li $v0,4  #������
	la  $a0,str 
	syscall 
	
	addi $s0,$s0,4 #��ַ��һλ
	addi $t0,$t0,1 #k++
	j loop  #ѭ��
exit:
	li $v0,10
    syscall
    