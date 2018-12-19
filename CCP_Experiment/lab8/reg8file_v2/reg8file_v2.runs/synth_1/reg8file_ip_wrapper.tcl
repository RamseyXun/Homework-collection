# 
# Synthesis run script generated by Vivado
# 

set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
create_project -in_memory -part xc7a35ticpg236-1L

set_param project.singleFileAddWarning.threshold 0
set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_msg_config -source 4 -id {IP_Flow 19-2162} -severity warning -new_severity info
set_property webtalk.parent_dir D:/��ѧ/���/�����/��������ԭ��/ʵ��/��8��/reg8file_v2/reg8file_v2.cache/wt [current_project]
set_property parent.project_path D:/��ѧ/���/�����/��������ԭ��/ʵ��/��8��/reg8file_v2/reg8file_v2.xpr [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
set_property ip_repo_paths d:/Xilinx/myIP/reg8file_ip [current_project]
set_property ip_output_repo d:/��ѧ/���/�����/��������ԭ��/ʵ��/��8��/reg8file_v2/reg8file_v2.cache/ip [current_project]
set_property ip_cache_permissions {read write} [current_project]
read_verilog -library xil_defaultlib D:/��ѧ/���/�����/��������ԭ��/ʵ��/��8��/reg8file_v2/reg8file_v2.srcs/sources_1/bd/reg8file_ip/hdl/reg8file_ip_wrapper.v
add_files D:/��ѧ/���/�����/��������ԭ��/ʵ��/��8��/reg8file_v2/reg8file_v2.srcs/sources_1/bd/reg8file_ip/reg8file_ip.bd
set_property used_in_implementation false [get_files -all d:/��ѧ/���/�����/��������ԭ��/ʵ��/��8��/reg8file_v2/reg8file_v2.srcs/sources_1/bd/reg8file_ip/ip/reg8file_ip_reg8file_0_0/src/reg8file.xdc]
set_property used_in_implementation false [get_files -all D:/��ѧ/���/�����/��������ԭ��/ʵ��/��8��/reg8file_v2/reg8file_v2.srcs/sources_1/bd/reg8file_ip/reg8file_ip_ooc.xdc]
set_property is_locked true [get_files D:/��ѧ/���/�����/��������ԭ��/ʵ��/��8��/reg8file_v2/reg8file_v2.srcs/sources_1/bd/reg8file_ip/reg8file_ip.bd]

foreach dcp [get_files -quiet -all *.dcp] {
  set_property used_in_implementation false $dcp
}
read_xdc dont_touch.xdc
set_property used_in_implementation false [get_files dont_touch.xdc]

synth_design -top reg8file_ip_wrapper -part xc7a35ticpg236-1L


write_checkpoint -force -noxdef reg8file_ip_wrapper.dcp

catch { report_utilization -file reg8file_ip_wrapper_utilization_synth.rpt -pb reg8file_ip_wrapper_utilization_synth.pb }