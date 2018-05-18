
# PlanAhead Launch Script for Post-Synthesis floorplanning, created by Project Navigator

create_project -name nes -dir "D:/ra97-2015/fpga_nes/hw/ise/planAhead_run_2" -part xc6slx45fgg676-2
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "D:/ra97-2015/fpga_nes/hw/ise/nes_top.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {D:/ra97-2015/fpga_nes/hw/ise} {ipcore_dir_bak} }
set_property target_constrs_file "D:/ra97-2015/fpga_nes/hw/src/nes.ucf" [current_fileset -constrset]
add_files [list {D:/ra97-2015/fpga_nes/hw/src/nes.ucf}] -fileset [get_property constrset [current_run]]
link_design
