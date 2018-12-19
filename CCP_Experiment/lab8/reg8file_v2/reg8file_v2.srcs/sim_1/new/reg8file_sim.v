`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2017/05/12 23:04:46
// Design Name: 
// Module Name: reg8file_sim
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module reg8file_sim(

    );
    reg clk;
    reg clrn;
    reg wen;
    reg[7:0] d;
    wire[7:0] q;
    reg[2:0] wsel;
    reg[2:0] rsel;
    reg8file_ip reg_sim(
        .clk(clk),
        .clrn(clrn),
        .wen(wen),
        .d(d),
        .wsel(wsel),
        .rsel(rsel),
        .q(q)
    );

    initial begin
    #0 begin clrn=0;clk=0;wen=0;wsel=3'b001;rsel=3'b001;d=8'b0000001;end //����˿��ţ�������
    #5 begin clrn=1;end //����˹ر� Ҳû�仯����Ϊclk����������
    #5 begin clk=1;end  //������
    #10 begin clk=0;wsel=3'b010;rsel=3'b010;d=8'b0000010;end //���żĴ�����2
    #10 begin clk=1;end
    #10 begin clk=0;d=8'b0000011;end //���żĴ�����3 
    #10 begin clk=1;end
    #10 begin clk=0;wen=1;d=8'b0000100;end //�ر�ʹ�ܣ����żĴ���ֵû��
    #10 begin clk=1;end
    #10 begin clk=0;wsel=3'b011;rsel=3'b011;d=8'b0000110;end //ʹ��δ�������żĴ�����2ʧ��
    #10 begin clk=1;end
    #10 begin clk=0;wen=0;end //ʹ�ܴ򿪣����żĴ����ɹ���3 
    #10 begin clk=1;end
    #10 begin clk=0;clrn=0;end//����
    #10 begin clk=1;end
    end
endmodule

