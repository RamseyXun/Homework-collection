`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2017/05/19 08:13:46
// Design Name: 
// Module Name: signext
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


module signext( 
input [7:0] inst, // ����8λ
output [31:0] data // ���32λ
); 
 //��8λ������չ��32λ���
 // assign data = inst[7:7]?{24'hffffff,inst}:{24'h000000,inst}; 
 assign data = {24'h000000,inst}; 
endmodule 
