
EAGLE3D_HOME=/home/poine/work/eagle3d/eagle3d/

POVLIB=+L$(EAGLE3D_HOME)/povray  +L/usr/share/fonts/truetype/msttcorefonts +L/usr/share/fonts/truetype/vlgothic/ +L/usr/share/fonts/truetype/ttf-tuffy/ +L/usr/share/fonts/truetype

OPT_BIG =  +W1600 +H1200 +Q9 +A0.3 +R5
OPT_SMALL = +W800 +H600

jobyrobotics_icon:
	povray -Ijoby_robotics_favicon.pov $(POVLIB)  +W96 +H96  +Q9 +A0.3 +R5

jobyrobotics_logo:
	povray -Ijoby_robotics.pov $(POVLIB)  +W1500 +H300

jobyrobotics_logo_big:
	povray -Ijoby_robotics.pov $(POVLIB)  +W1500 +H300  +Q9 +A0.3 +R5

boozaero_logo:
	povray -Iboozaero_logo2.pov $(POVLIB)  +W1500 +H300

boozaero_logo_big:
	povray -Iboozaero_logo2.pov $(POVLIB) +W1500 +H300 +Q9 +A0.3 +R5

lisa_l_con_top:
	povray -Ilisa_l_connectors_top.pov $(POVLIB) $(OPT_SMALL)

lisa_l_con_bot:
	povray -Ilisa_l_connectors_bot.pov $(POVLIB) $(OPT_SMALL)


lisa_l_con_top_big:
	povray -Ilisa_l_connectors_top.pov $(POVLIB) $(OPT_BIG)

lisa_l_con_bot_big:
	povray -Ilisa_l_connectors_bot.pov $(POVLIB) $(OPT_BIG)



imu_small:
	povray -Iimu_assembly.pov $(POVLIB) +W800 +H600

imu_big:
	povray -Iimu_assembly.pov $(POVLIB)  +W1600 +H1200 +Q9 +A0.3 +R5


#declare pack_CON_UI=off;
lisa_small:
	povray -Ilisa_main-0_101.pov $(POVLIB) +W800 +H600

lisa_big:
	povray -Ilisa_main-0_101.pov $(POVLIB) +W1600 +H1200 +Q9 +A0.3 +R5

lisa_imu_small: make_inc
	povray -Ilisa_imu_assembly.pov $(POVLIB) $(OPT_SMALL)

lisa_imu_big:
	povray -Ilisa_imu_assembly.pov $(POVLIB)  $(OPT_BIG)

gps_small:
	povray -Ibooz_gps_no_ami_mag.pov $(POVLIB)  +W800 +H600

lisa_imu_gps_small:
	povray -Ilisa_imu_gps_assembly.pov $(POVLIB) +W800 +H600

lisa_imu_gps_big:
	povray -Ilisa_imu_gps_assembly.pov $(POVLIB)  +W1600 +H1200 +Q9 +A0.3 +R5

lisa_mkk:
	povray -Ilisa_mkk.pov  $(POVLIB) +W800 +H600

lisa_mkk_big:
	povray -Ilisa_mkk.pov  $(POVLIB)  +W1600 +H1200 +Q9 +A0.3 +R5

lisa_asctec:
	povray -Ilisa_asctec.pov  $(POVLIB) +W800 +H600

lisa_asctec_big:
	povray -Ilisa_asctec.pov  $(POVLIB) +W1600 +H1200 +Q9 +A0.3 +R5

lisa_bipe:
	povray -Ilisa_bipe.pov  $(POVLIB) +W800 +H600

lisa_bipe_big:
	povray -Ilisa_bipe.pov  $(POVLIB) +W1600 +H1200 +Q9 +A0.3 +R5

scene_beth:
	povray -Iscene_beth.pov  $(POVLIB) +W800 +H600

scene_beth_big:
	povray -Iscene_beth.pov  $(POVLIB) +W1600 +H1200 +Q9 +A0.3 +R5

test:
	povray -Itmp.pov $(POVLIB) +W800 +H600

test_big:
	povray -Itmp.pov $(POVLIB)  +W1600 +H1200

test2:
	povray -Itiny_1_2.pov $(POVLIB) +W800 +H600

test2_big:
	povray -Itiny_1_2.pov $(POVLIB)  +W1600 +H1200 +Q9 +A0.3 +R5

tiny_1_1:
	povray -Itiny13_1_1.pov $(POVLIB) +W800 +H600

tiny_pen:
	povray -Itiny_pen.pov $(POVLIB) +W800 +H600

tiny_pen_big:
	povray -Itiny_pen.pov $(POVLIB)  +W1600 +H1200 +Q9 +A0.3 +R5

lisa_s_box_1:
	povray -Ilisa_s_box_1.pov $(POVLIB) +W800 +H600

lisa_s_box_1_b:
	povray -Ilisa_s_box_1.pov $(POVLIB)   +W1600 +H1200 +Q9 +A0.3 +R5

lisa_s_box_2:
	povray -Ilisa_s_box_2.pov $(POVLIB) +W800 +H600

lisa_s_box_2_b:
	povray -Ilisa_s_box_2.pov $(POVLIB)   +W1600 +H1200 +Q9 +A0.3 +R5

tiny_lisa_comp:
	povray -Itiny_lisa_comp.pov $(POVLIB) +W800 +H600

tiny_lisa_comp_b:
	povray -Itiny_lisa_comp.pov $(POVLIB) +W1600 +H1200 +Q9 +A0.3 +R5

make_inc: lisa_l_0.101.pov
	TMP=`mktemp`;\
	`sed 's/local use_file_as_inc = off;/local use_file_as_inc = on;/' < $< > $$TMP`;\
	`mv $$TMP  $<`

clean:
	rm *~