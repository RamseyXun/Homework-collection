.data 0x0
x: .space 4
y: .space 4
.text 0x3000
.globl main
main:
	sw $0,x($0)         #x=0
	addi $9,$0,1        #y'=1
	sw $9,y($0)         #y=y'      
	lw $8,0($0)         #x'=x
while:
	slti $10,$9,100     #while(y<100),��y<100,��$10=1����$10=0
	beq $10,$0, endw    #��$10=0,˵��y>=100���˳�ѭ������endw
	add $10,$0,$8       #$10=x'
	add $8,$0,$9        #x'=y'
	sw $8,0($0)         #x=x'     
	add $9,$10,$9       #y'=x'+y';
	sw $9,4($0)         #y=y'
	beq $0,$0,while     #��ת��while
endw:
	ori $v0 , $0, 10
syscall
