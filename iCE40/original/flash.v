// Reading file 'flash.asc'..

module chip (input io_0_8_1, output io_13_9_1, output io_13_11_0, output io_13_12_1, output io_13_11_1, output io_13_12_0);

wire io_0_8_1;
// (0, 0, 'glb_netwk_1')
// (0, 8, 'io_1/D_IN_0')
// (0, 8, 'io_1/PAD')
// (0, 8, 'padin_1')
// (1, 7, 'neigh_op_tnl_2')
// (1, 7, 'neigh_op_tnl_6')
// (1, 8, 'neigh_op_lft_2')
// (1, 8, 'neigh_op_lft_6')
// (1, 9, 'neigh_op_bnl_2')
// (1, 9, 'neigh_op_bnl_6')
// (11, 9, 'lutff_global/clk')
// (11, 11, 'lutff_global/clk')
// (11, 12, 'lutff_global/clk')
// (12, 9, 'lutff_global/clk')
// (12, 10, 'lutff_global/clk')
// (12, 11, 'lutff_global/clk')
// (12, 12, 'lutff_global/clk')

wire n2;
// (7, 9, 'sp4_h_r_3')
// (8, 9, 'sp4_h_r_14')
// (9, 9, 'sp4_h_r_27')
// (10, 9, 'neigh_op_tnr_6')
// (10, 9, 'sp4_h_r_38')
// (10, 10, 'neigh_op_rgt_6')
// (10, 10, 'sp4_r_v_b_44')
// (10, 11, 'neigh_op_bnr_6')
// (10, 11, 'sp4_r_v_b_33')
// (10, 12, 'sp4_r_v_b_20')
// (10, 13, 'sp4_r_v_b_9')
// (11, 9, 'neigh_op_top_6')
// (11, 9, 'sp4_h_l_38')
// (11, 9, 'sp4_h_r_6')
// (11, 9, 'sp4_v_t_44')
// (11, 10, 'local_g0_6')
// (11, 10, 'lutff_1/in_3')
// (11, 10, 'lutff_6/out')
// (11, 10, 'sp4_v_b_44')
// (11, 11, 'local_g1_6')
// (11, 11, 'lutff_4/in_3')
// (11, 11, 'lutff_6/in_3')
// (11, 11, 'neigh_op_bot_6')
// (11, 11, 'sp4_v_b_33')
// (11, 12, 'local_g1_4')
// (11, 12, 'lutff_2/in_3')
// (11, 12, 'sp4_v_b_20')
// (11, 13, 'sp4_v_b_9')
// (12, 9, 'local_g1_3')
// (12, 9, 'lutff_global/cen')
// (12, 9, 'neigh_op_tnl_6')
// (12, 9, 'sp4_h_r_19')
// (12, 10, 'neigh_op_lft_6')
// (12, 11, 'neigh_op_bnl_6')
// (13, 9, 'span4_horz_19')

reg n3 = 0;
// (8, 10, 'sp4_h_r_1')
// (9, 10, 'sp4_h_r_12')
// (10, 10, 'sp4_h_r_25')
// (11, 10, 'local_g3_4')
// (11, 10, 'lutff_3/in_2')
// (11, 10, 'neigh_op_tnr_2')
// (11, 10, 'sp4_h_r_36')
// (11, 11, 'neigh_op_rgt_2')
// (11, 11, 'sp4_r_v_b_36')
// (11, 12, 'neigh_op_bnr_2')
// (11, 12, 'sp4_r_v_b_25')
// (11, 13, 'sp4_r_v_b_12')
// (11, 14, 'sp4_r_v_b_1')
// (12, 10, 'neigh_op_top_2')
// (12, 10, 'sp4_h_l_36')
// (12, 10, 'sp4_v_t_36')
// (12, 11, 'local_g1_2')
// (12, 11, 'lutff_2/in_1')
// (12, 11, 'lutff_2/out')
// (12, 11, 'sp4_v_b_36')
// (12, 12, 'neigh_op_bot_2')
// (12, 12, 'sp4_v_b_25')
// (12, 13, 'sp4_v_b_12')
// (12, 14, 'sp4_v_b_1')
// (13, 10, 'logic_op_tnl_2')
// (13, 11, 'logic_op_lft_2')
// (13, 12, 'logic_op_bnl_2')

reg n4 = 0;
// (8, 11, 'sp4_h_r_3')
// (9, 11, 'sp4_h_r_14')
// (10, 11, 'sp4_h_r_27')
// (11, 8, 'neigh_op_tnr_1')
// (11, 8, 'sp4_r_v_b_47')
// (11, 9, 'local_g2_1')
// (11, 9, 'lutff_0/in_3')
// (11, 9, 'neigh_op_rgt_1')
// (11, 9, 'sp4_r_v_b_34')
// (11, 10, 'neigh_op_bnr_1')
// (11, 10, 'sp4_r_v_b_23')
// (11, 11, 'local_g2_2')
// (11, 11, 'local_g3_6')
// (11, 11, 'lutff_3/in_2')
// (11, 11, 'lutff_5/in_3')
// (11, 11, 'lutff_6/in_0')
// (11, 11, 'sp4_h_r_38')
// (11, 11, 'sp4_r_v_b_10')
// (12, 7, 'sp4_v_t_47')
// (12, 8, 'neigh_op_top_1')
// (12, 8, 'sp4_v_b_47')
// (12, 9, 'local_g3_1')
// (12, 9, 'lutff_1/in_3')
// (12, 9, 'lutff_1/out')
// (12, 9, 'sp4_v_b_34')
// (12, 10, 'neigh_op_bot_1')
// (12, 10, 'sp4_v_b_23')
// (12, 11, 'sp4_h_l_38')
// (12, 11, 'sp4_v_b_10')
// (13, 8, 'logic_op_tnl_1')
// (13, 9, 'logic_op_lft_1')
// (13, 10, 'logic_op_bnl_1')

reg n5 = 0;
// (8, 11, 'sp4_h_r_8')
// (9, 11, 'sp4_h_r_21')
// (10, 11, 'sp4_h_r_32')
// (11, 8, 'neigh_op_tnr_0')
// (11, 8, 'sp4_r_v_b_45')
// (11, 9, 'local_g0_3')
// (11, 9, 'lutff_1/in_0')
// (11, 9, 'neigh_op_rgt_0')
// (11, 9, 'sp4_r_v_b_32')
// (11, 10, 'neigh_op_bnr_0')
// (11, 10, 'sp4_r_v_b_21')
// (11, 11, 'local_g2_5')
// (11, 11, 'lutff_5/in_2')
// (11, 11, 'sp4_h_r_45')
// (11, 11, 'sp4_r_v_b_8')
// (12, 7, 'sp4_v_t_45')
// (12, 8, 'neigh_op_top_0')
// (12, 8, 'sp4_v_b_45')
// (12, 9, 'local_g1_0')
// (12, 9, 'lutff_0/in_1')
// (12, 9, 'lutff_0/out')
// (12, 9, 'sp4_v_b_32')
// (12, 10, 'neigh_op_bot_0')
// (12, 10, 'sp4_v_b_21')
// (12, 11, 'sp4_h_l_45')
// (12, 11, 'sp4_v_b_8')
// (13, 8, 'logic_op_tnl_0')
// (13, 9, 'logic_op_lft_0')
// (13, 10, 'logic_op_bnl_0')

wire n6;
// (10, 7, 'sp4_r_v_b_42')
// (10, 8, 'sp4_r_v_b_31')
// (10, 9, 'neigh_op_tnr_1')
// (10, 9, 'sp4_r_v_b_18')
// (10, 10, 'neigh_op_rgt_1')
// (10, 10, 'sp4_r_v_b_7')
// (10, 11, 'neigh_op_bnr_1')
// (11, 6, 'sp4_v_t_42')
// (11, 7, 'sp4_v_b_42')
// (11, 8, 'sp4_v_b_31')
// (11, 9, 'local_g0_2')
// (11, 9, 'lutff_global/cen')
// (11, 9, 'neigh_op_top_1')
// (11, 9, 'sp4_v_b_18')
// (11, 10, 'lutff_1/out')
// (11, 10, 'sp4_h_r_2')
// (11, 10, 'sp4_v_b_7')
// (11, 11, 'neigh_op_bot_1')
// (12, 9, 'neigh_op_tnl_1')
// (12, 10, 'neigh_op_lft_1')
// (12, 10, 'sp4_h_r_15')
// (12, 11, 'neigh_op_bnl_1')
// (13, 10, 'span4_horz_15')

reg n7 = 0;
// (10, 8, 'neigh_op_tnr_0')
// (10, 8, 'sp4_r_v_b_45')
// (10, 9, 'neigh_op_rgt_0')
// (10, 9, 'sp4_r_v_b_32')
// (10, 10, 'neigh_op_bnr_0')
// (10, 10, 'sp4_r_v_b_21')
// (10, 11, 'sp4_r_v_b_8')
// (11, 7, 'sp4_v_t_45')
// (11, 8, 'neigh_op_top_0')
// (11, 8, 'sp4_v_b_45')
// (11, 9, 'local_g0_0')
// (11, 9, 'lutff_0/in_0')
// (11, 9, 'lutff_0/out')
// (11, 9, 'sp4_v_b_32')
// (11, 10, 'neigh_op_bot_0')
// (11, 10, 'sp4_v_b_21')
// (11, 11, 'local_g0_0')
// (11, 11, 'lutff_3/in_1')
// (11, 11, 'lutff_5/in_1')
// (11, 11, 'sp4_v_b_8')
// (12, 8, 'neigh_op_tnl_0')
// (12, 9, 'neigh_op_lft_0')
// (12, 10, 'neigh_op_bnl_0')

reg n8 = 0;
// (10, 8, 'neigh_op_tnr_1')
// (10, 9, 'neigh_op_rgt_1')
// (10, 10, 'neigh_op_bnr_1')
// (11, 8, 'neigh_op_top_1')
// (11, 8, 'sp4_r_v_b_46')
// (11, 9, 'local_g3_1')
// (11, 9, 'lutff_1/in_1')
// (11, 9, 'lutff_1/out')
// (11, 9, 'sp4_r_v_b_35')
// (11, 10, 'neigh_op_bot_1')
// (11, 10, 'sp4_r_v_b_22')
// (11, 11, 'local_g2_3')
// (11, 11, 'lutff_7/in_2')
// (11, 11, 'sp4_r_v_b_11')
// (12, 7, 'sp4_v_t_46')
// (12, 8, 'neigh_op_tnl_1')
// (12, 8, 'sp4_v_b_46')
// (12, 9, 'neigh_op_lft_1')
// (12, 9, 'sp4_v_b_35')
// (12, 10, 'neigh_op_bnl_1')
// (12, 10, 'sp4_v_b_22')
// (12, 11, 'sp4_v_b_11')

wire n9;
// (10, 9, 'neigh_op_tnr_0')
// (10, 9, 'sp4_r_v_b_45')
// (10, 10, 'neigh_op_rgt_0')
// (10, 10, 'sp4_r_v_b_32')
// (10, 11, 'neigh_op_bnr_0')
// (10, 11, 'sp4_r_v_b_21')
// (10, 12, 'sp4_r_v_b_8')
// (11, 8, 'sp4_v_t_45')
// (11, 9, 'local_g3_5')
// (11, 9, 'lutff_global/s_r')
// (11, 9, 'neigh_op_top_0')
// (11, 9, 'sp4_v_b_45')
// (11, 10, 'lutff_0/out')
// (11, 10, 'lutff_1/in_2')
// (11, 10, 'sp4_v_b_32')
// (11, 11, 'local_g1_5')
// (11, 11, 'lutff_global/s_r')
// (11, 11, 'neigh_op_bot_0')
// (11, 11, 'sp4_v_b_21')
// (11, 12, 'sp4_v_b_8')
// (12, 9, 'neigh_op_tnl_0')
// (12, 10, 'neigh_op_lft_0')
// (12, 11, 'neigh_op_bnl_0')

wire n10;
// (10, 9, 'neigh_op_tnr_2')
// (10, 10, 'neigh_op_rgt_2')
// (10, 11, 'neigh_op_bnr_2')
// (11, 9, 'neigh_op_top_2')
// (11, 10, 'local_g2_2')
// (11, 10, 'lutff_2/out')
// (11, 10, 'lutff_5/in_3')
// (11, 10, 'lutff_6/in_2')
// (11, 11, 'local_g0_2')
// (11, 11, 'lutff_1/in_1')
// (11, 11, 'neigh_op_bot_2')
// (12, 9, 'neigh_op_tnl_2')
// (12, 10, 'neigh_op_lft_2')
// (12, 11, 'neigh_op_bnl_2')

wire n11;
// (10, 9, 'neigh_op_tnr_3')
// (10, 10, 'neigh_op_rgt_3')
// (10, 11, 'neigh_op_bnr_3')
// (11, 9, 'neigh_op_top_3')
// (11, 10, 'local_g0_3')
// (11, 10, 'local_g1_3')
// (11, 10, 'lutff_3/out')
// (11, 10, 'lutff_5/in_0')
// (11, 10, 'lutff_6/in_0')
// (11, 11, 'local_g1_3')
// (11, 11, 'lutff_1/in_3')
// (11, 11, 'neigh_op_bot_3')
// (12, 9, 'neigh_op_tnl_3')
// (12, 10, 'neigh_op_lft_3')
// (12, 11, 'neigh_op_bnl_3')

wire n12;
// (10, 9, 'neigh_op_tnr_4')
// (10, 10, 'neigh_op_rgt_4')
// (10, 11, 'neigh_op_bnr_4')
// (11, 9, 'neigh_op_top_4')
// (11, 10, 'lutff_4/out')
// (11, 10, 'lutff_5/in_2')
// (11, 11, 'neigh_op_bot_4')
// (12, 9, 'neigh_op_tnl_4')
// (12, 10, 'neigh_op_lft_4')
// (12, 11, 'neigh_op_bnl_4')

wire n13;
// (10, 9, 'neigh_op_tnr_5')
// (10, 10, 'neigh_op_rgt_5')
// (10, 11, 'neigh_op_bnr_5')
// (11, 9, 'neigh_op_top_5')
// (11, 10, 'local_g0_5')
// (11, 10, 'lutff_0/in_3')
// (11, 10, 'lutff_5/out')
// (11, 11, 'neigh_op_bot_5')
// (12, 9, 'neigh_op_tnl_5')
// (12, 10, 'neigh_op_lft_5')
// (12, 11, 'neigh_op_bnl_5')

wire n14;
// (10, 9, 'neigh_op_tnr_7')
// (10, 10, 'neigh_op_rgt_7')
// (10, 11, 'neigh_op_bnr_7')
// (11, 9, 'neigh_op_top_7')
// (11, 10, 'local_g0_7')
// (11, 10, 'lutff_6/in_1')
// (11, 10, 'lutff_7/out')
// (11, 11, 'local_g0_7')
// (11, 11, 'lutff_1/in_0')
// (11, 11, 'neigh_op_bot_7')
// (12, 9, 'neigh_op_tnl_7')
// (12, 10, 'neigh_op_lft_7')
// (12, 11, 'neigh_op_bnl_7')

wire n15;
// (10, 10, 'neigh_op_tnr_0')
// (10, 11, 'neigh_op_rgt_0')
// (10, 12, 'neigh_op_bnr_0')
// (11, 10, 'local_g1_0')
// (11, 10, 'lutff_0/in_1')
// (11, 10, 'lutff_6/in_3')
// (11, 10, 'neigh_op_top_0')
// (11, 11, 'lutff_0/out')
// (11, 11, 'lutff_1/in_2')
// (11, 12, 'neigh_op_bot_0')
// (12, 10, 'neigh_op_tnl_0')
// (12, 11, 'neigh_op_lft_0')
// (12, 12, 'neigh_op_bnl_0')

wire n16;
// (10, 10, 'neigh_op_tnr_1')
// (10, 11, 'neigh_op_rgt_1')
// (10, 12, 'neigh_op_bnr_1')
// (11, 10, 'neigh_op_top_1')
// (11, 11, 'lutff_1/out')
// (11, 11, 'lutff_2/in_2')
// (11, 12, 'neigh_op_bot_1')
// (12, 10, 'neigh_op_tnl_1')
// (12, 11, 'neigh_op_lft_1')
// (12, 12, 'neigh_op_bnl_1')

reg n17 = 0;
// (10, 10, 'neigh_op_tnr_2')
// (10, 11, 'neigh_op_rgt_2')
// (10, 12, 'neigh_op_bnr_2')
// (11, 10, 'neigh_op_top_2')
// (11, 11, 'local_g3_2')
// (11, 11, 'lutff_2/in_3')
// (11, 11, 'lutff_2/out')
// (11, 12, 'neigh_op_bot_2')
// (12, 10, 'neigh_op_tnl_2')
// (12, 11, 'neigh_op_lft_2')
// (12, 12, 'local_g2_2')
// (12, 12, 'local_g3_2')
// (12, 12, 'lutff_0/in_1')
// (12, 12, 'lutff_1/in_1')
// (12, 12, 'neigh_op_bnl_2')

wire n18;
// (10, 10, 'neigh_op_tnr_3')
// (10, 11, 'neigh_op_rgt_3')
// (10, 12, 'neigh_op_bnr_3')
// (11, 9, 'local_g3_7')
// (11, 9, 'lutff_1/in_3')
// (11, 9, 'sp4_r_v_b_47')
// (11, 10, 'neigh_op_top_3')
// (11, 10, 'sp4_r_v_b_34')
// (11, 11, 'lutff_3/out')
// (11, 11, 'lutff_4/in_2')
// (11, 11, 'sp4_r_v_b_23')
// (11, 12, 'neigh_op_bot_3')
// (11, 12, 'sp4_r_v_b_10')
// (12, 8, 'sp4_v_t_47')
// (12, 9, 'local_g3_7')
// (12, 9, 'lutff_0/in_0')
// (12, 9, 'sp4_v_b_47')
// (12, 10, 'neigh_op_tnl_3')
// (12, 10, 'sp4_v_b_34')
// (12, 11, 'neigh_op_lft_3')
// (12, 11, 'sp4_v_b_23')
// (12, 12, 'neigh_op_bnl_3')
// (12, 12, 'sp4_v_b_10')

reg n19 = 0;
// (10, 10, 'neigh_op_tnr_4')
// (10, 11, 'neigh_op_rgt_4')
// (10, 12, 'neigh_op_bnr_4')
// (11, 3, 'sp12_v_t_23')
// (11, 4, 'sp12_v_b_23')
// (11, 5, 'sp12_v_b_20')
// (11, 6, 'sp12_v_b_19')
// (11, 7, 'sp12_v_b_16')
// (11, 8, 'sp12_v_b_15')
// (11, 8, 'sp4_r_v_b_44')
// (11, 9, 'local_g3_4')
// (11, 9, 'lutff_1/in_2')
// (11, 9, 'sp12_v_b_12')
// (11, 9, 'sp4_r_v_b_33')
// (11, 10, 'neigh_op_top_4')
// (11, 10, 'sp12_v_b_11')
// (11, 10, 'sp4_r_v_b_20')
// (11, 11, 'local_g3_4')
// (11, 11, 'lutff_4/in_1')
// (11, 11, 'lutff_4/out')
// (11, 11, 'lutff_5/in_0')
// (11, 11, 'sp12_v_b_8')
// (11, 11, 'sp4_r_v_b_9')
// (11, 12, 'neigh_op_bot_4')
// (11, 12, 'sp12_v_b_7')
// (11, 13, 'sp12_v_b_4')
// (11, 14, 'sp12_v_b_3')
// (11, 15, 'sp12_v_b_0')
// (12, 7, 'sp4_v_t_44')
// (12, 8, 'sp4_v_b_44')
// (12, 9, 'local_g2_1')
// (12, 9, 'lutff_0/in_3')
// (12, 9, 'sp4_v_b_33')
// (12, 10, 'neigh_op_tnl_4')
// (12, 10, 'sp4_v_b_20')
// (12, 11, 'neigh_op_lft_4')
// (12, 11, 'sp4_v_b_9')
// (12, 12, 'neigh_op_bnl_4')

wire n20;
// (10, 10, 'neigh_op_tnr_5')
// (10, 11, 'neigh_op_rgt_5')
// (10, 12, 'neigh_op_bnr_5')
// (11, 10, 'local_g1_5')
// (11, 10, 'lutff_0/in_0')
// (11, 10, 'neigh_op_top_5')
// (11, 11, 'lutff_5/out')
// (11, 12, 'neigh_op_bot_5')
// (12, 10, 'neigh_op_tnl_5')
// (12, 11, 'neigh_op_lft_5')
// (12, 12, 'neigh_op_bnl_5')

reg n21 = 0;
// (10, 10, 'neigh_op_tnr_6')
// (10, 11, 'neigh_op_rgt_6')
// (10, 12, 'neigh_op_bnr_6')
// (11, 5, 'sp12_v_t_23')
// (11, 6, 'sp12_v_b_23')
// (11, 7, 'sp12_v_b_20')
// (11, 8, 'sp12_v_b_19')
// (11, 9, 'local_g2_0')
// (11, 9, 'lutff_0/in_2')
// (11, 9, 'sp12_v_b_16')
// (11, 10, 'neigh_op_top_6')
// (11, 10, 'sp12_v_b_15')
// (11, 11, 'local_g2_6')
// (11, 11, 'lutff_3/in_3')
// (11, 11, 'lutff_6/in_2')
// (11, 11, 'lutff_6/out')
// (11, 11, 'lutff_7/in_3')
// (11, 11, 'sp12_v_b_12')
// (11, 12, 'neigh_op_bot_6')
// (11, 12, 'sp12_v_b_11')
// (11, 13, 'sp12_v_b_8')
// (11, 14, 'sp12_v_b_7')
// (11, 15, 'sp12_v_b_4')
// (11, 16, 'sp12_v_b_3')
// (11, 17, 'span12_vert_0')
// (12, 10, 'neigh_op_tnl_6')
// (12, 11, 'neigh_op_lft_6')
// (12, 12, 'neigh_op_bnl_6')

wire n22;
// (10, 10, 'neigh_op_tnr_7')
// (10, 11, 'neigh_op_rgt_7')
// (10, 12, 'neigh_op_bnr_7')
// (11, 10, 'local_g1_7')
// (11, 10, 'lutff_0/in_2')
// (11, 10, 'neigh_op_top_7')
// (11, 11, 'lutff_7/out')
// (11, 12, 'neigh_op_bot_7')
// (12, 10, 'neigh_op_tnl_7')
// (12, 11, 'neigh_op_lft_7')
// (12, 12, 'neigh_op_bnl_7')

reg n23 = 0;
// (10, 11, 'neigh_op_tnr_2')
// (10, 12, 'neigh_op_rgt_2')
// (10, 13, 'neigh_op_bnr_2')
// (11, 9, 'local_g3_0')
// (11, 9, 'lutff_0/in_1')
// (11, 9, 'sp4_r_v_b_40')
// (11, 10, 'sp4_r_v_b_29')
// (11, 11, 'local_g1_2')
// (11, 11, 'lutff_3/in_0')
// (11, 11, 'lutff_6/in_1')
// (11, 11, 'lutff_7/in_0')
// (11, 11, 'neigh_op_top_2')
// (11, 11, 'sp4_r_v_b_16')
// (11, 12, 'local_g3_2')
// (11, 12, 'lutff_2/in_1')
// (11, 12, 'lutff_2/out')
// (11, 12, 'sp4_r_v_b_5')
// (11, 13, 'neigh_op_bot_2')
// (12, 8, 'sp4_v_t_40')
// (12, 9, 'local_g2_0')
// (12, 9, 'lutff_1/in_1')
// (12, 9, 'sp4_v_b_40')
// (12, 10, 'sp4_v_b_29')
// (12, 11, 'neigh_op_tnl_2')
// (12, 11, 'sp4_v_b_16')
// (12, 12, 'neigh_op_lft_2')
// (12, 12, 'sp4_v_b_5')
// (12, 13, 'neigh_op_bnl_2')

wire io_13_9_1;
// (11, 7, 'neigh_op_tnr_6')
// (11, 8, 'neigh_op_rgt_6')
// (11, 9, 'neigh_op_bnr_6')
// (12, 7, 'neigh_op_top_6')
// (12, 8, 'lutff_6/out')
// (12, 9, 'neigh_op_bot_6')
// (13, 7, 'logic_op_tnl_6')
// (13, 8, 'logic_op_lft_6')
// (13, 9, 'io_1/D_OUT_0')
// (13, 9, 'io_1/PAD')
// (13, 9, 'local_g1_6')
// (13, 9, 'logic_op_bnl_6')

reg n25 = 0;
// (11, 7, 'sp4_r_v_b_39')
// (11, 8, 'sp4_r_v_b_26')
// (11, 9, 'neigh_op_tnr_1')
// (11, 9, 'sp4_r_v_b_15')
// (11, 10, 'local_g1_2')
// (11, 10, 'lutff_4/in_1')
// (11, 10, 'lutff_7/in_0')
// (11, 10, 'neigh_op_rgt_1')
// (11, 10, 'sp4_r_v_b_2')
// (11, 11, 'neigh_op_bnr_1')
// (12, 6, 'sp4_v_t_39')
// (12, 7, 'sp4_v_b_39')
// (12, 8, 'sp4_v_b_26')
// (12, 9, 'neigh_op_top_1')
// (12, 9, 'sp4_v_b_15')
// (12, 10, 'local_g3_1')
// (12, 10, 'lutff_1/in_1')
// (12, 10, 'lutff_1/out')
// (12, 10, 'sp4_v_b_2')
// (12, 11, 'neigh_op_bot_1')
// (13, 9, 'logic_op_tnl_1')
// (13, 10, 'logic_op_lft_1')
// (13, 11, 'logic_op_bnl_1')

reg n26 = 0;
// (11, 9, 'neigh_op_tnr_0')
// (11, 10, 'local_g2_0')
// (11, 10, 'lutff_5/in_1')
// (11, 10, 'lutff_7/in_1')
// (11, 10, 'neigh_op_rgt_0')
// (11, 11, 'neigh_op_bnr_0')
// (12, 9, 'neigh_op_top_0')
// (12, 10, 'local_g3_0')
// (12, 10, 'lutff_0/in_1')
// (12, 10, 'lutff_0/out')
// (12, 11, 'neigh_op_bot_0')
// (13, 9, 'logic_op_tnl_0')
// (13, 10, 'logic_op_lft_0')
// (13, 11, 'logic_op_bnl_0')

reg n27 = 0;
// (11, 9, 'neigh_op_tnr_2')
// (11, 10, 'local_g1_1')
// (11, 10, 'local_g3_2')
// (11, 10, 'lutff_4/in_0')
// (11, 10, 'lutff_7/in_2')
// (11, 10, 'neigh_op_rgt_2')
// (11, 10, 'sp4_h_r_9')
// (11, 11, 'neigh_op_bnr_2')
// (12, 9, 'neigh_op_top_2')
// (12, 10, 'local_g1_4')
// (12, 10, 'lutff_2/in_1')
// (12, 10, 'lutff_2/out')
// (12, 10, 'sp4_h_r_20')
// (12, 11, 'neigh_op_bot_2')
// (13, 9, 'logic_op_tnl_2')
// (13, 10, 'logic_op_lft_2')
// (13, 10, 'span4_horz_20')
// (13, 11, 'logic_op_bnl_2')

reg n28 = 0;
// (11, 9, 'neigh_op_tnr_3')
// (11, 10, 'neigh_op_rgt_3')
// (11, 11, 'local_g0_3')
// (11, 11, 'lutff_0/in_3')
// (11, 11, 'neigh_op_bnr_3')
// (12, 9, 'neigh_op_top_3')
// (12, 10, 'local_g1_3')
// (12, 10, 'lutff_3/in_1')
// (12, 10, 'lutff_3/out')
// (12, 11, 'neigh_op_bot_3')
// (13, 9, 'logic_op_tnl_3')
// (13, 10, 'logic_op_lft_3')
// (13, 11, 'logic_op_bnl_3')

reg n29 = 0;
// (11, 9, 'neigh_op_tnr_4')
// (11, 10, 'local_g2_4')
// (11, 10, 'lutff_3/in_1')
// (11, 10, 'neigh_op_rgt_4')
// (11, 11, 'neigh_op_bnr_4')
// (12, 9, 'neigh_op_top_4')
// (12, 10, 'local_g3_4')
// (12, 10, 'lutff_4/in_1')
// (12, 10, 'lutff_4/out')
// (12, 11, 'neigh_op_bot_4')
// (13, 9, 'logic_op_tnl_4')
// (13, 10, 'logic_op_lft_4')
// (13, 11, 'logic_op_bnl_4')

reg n30 = 0;
// (11, 9, 'neigh_op_tnr_5')
// (11, 10, 'local_g2_5')
// (11, 10, 'local_g3_5')
// (11, 10, 'lutff_4/in_3')
// (11, 10, 'lutff_7/in_3')
// (11, 10, 'neigh_op_rgt_5')
// (11, 11, 'neigh_op_bnr_5')
// (12, 9, 'neigh_op_top_5')
// (12, 10, 'local_g1_5')
// (12, 10, 'lutff_5/in_1')
// (12, 10, 'lutff_5/out')
// (12, 11, 'neigh_op_bot_5')
// (13, 9, 'logic_op_tnl_5')
// (13, 10, 'logic_op_lft_5')
// (13, 11, 'logic_op_bnl_5')

reg n31 = 0;
// (11, 9, 'neigh_op_tnr_6')
// (11, 10, 'local_g3_6')
// (11, 10, 'lutff_3/in_0')
// (11, 10, 'neigh_op_rgt_6')
// (11, 11, 'neigh_op_bnr_6')
// (12, 9, 'neigh_op_top_6')
// (12, 10, 'local_g1_6')
// (12, 10, 'lutff_6/in_1')
// (12, 10, 'lutff_6/out')
// (12, 11, 'neigh_op_bot_6')
// (13, 9, 'logic_op_tnl_6')
// (13, 10, 'logic_op_lft_6')
// (13, 11, 'logic_op_bnl_6')

reg n32 = 0;
// (11, 9, 'neigh_op_tnr_7')
// (11, 10, 'local_g2_7')
// (11, 10, 'lutff_2/in_1')
// (11, 10, 'neigh_op_rgt_7')
// (11, 11, 'neigh_op_bnr_7')
// (12, 9, 'neigh_op_top_7')
// (12, 10, 'local_g3_7')
// (12, 10, 'lutff_7/in_1')
// (12, 10, 'lutff_7/out')
// (12, 11, 'neigh_op_bot_7')
// (13, 9, 'logic_op_tnl_7')
// (13, 10, 'logic_op_lft_7')
// (13, 11, 'logic_op_bnl_7')

reg n33 = 0;
// (11, 10, 'local_g2_6')
// (11, 10, 'lutff_3/in_3')
// (11, 10, 'neigh_op_tnr_6')
// (11, 11, 'neigh_op_rgt_6')
// (11, 12, 'neigh_op_bnr_6')
// (12, 10, 'neigh_op_top_6')
// (12, 11, 'local_g1_6')
// (12, 11, 'lutff_6/in_1')
// (12, 11, 'lutff_6/out')
// (12, 12, 'neigh_op_bot_6')
// (13, 10, 'logic_op_tnl_6')
// (13, 11, 'logic_op_lft_6')
// (13, 12, 'logic_op_bnl_6')

reg n34 = 0;
// (11, 10, 'local_g3_0')
// (11, 10, 'lutff_2/in_3')
// (11, 10, 'neigh_op_tnr_5')
// (11, 10, 'sp4_r_v_b_40')
// (11, 11, 'neigh_op_rgt_5')
// (11, 11, 'sp4_r_v_b_29')
// (11, 12, 'neigh_op_bnr_5')
// (11, 12, 'sp4_r_v_b_16')
// (11, 13, 'sp4_r_v_b_5')
// (12, 4, 'sp12_v_t_22')
// (12, 5, 'sp12_v_b_22')
// (12, 6, 'sp12_v_b_21')
// (12, 7, 'sp12_v_b_18')
// (12, 8, 'sp12_v_b_17')
// (12, 9, 'sp12_v_b_14')
// (12, 9, 'sp4_v_t_40')
// (12, 10, 'neigh_op_top_5')
// (12, 10, 'sp12_v_b_13')
// (12, 10, 'sp4_v_b_40')
// (12, 11, 'local_g1_5')
// (12, 11, 'lutff_5/in_1')
// (12, 11, 'lutff_5/out')
// (12, 11, 'sp12_v_b_10')
// (12, 11, 'sp4_v_b_29')
// (12, 12, 'neigh_op_bot_5')
// (12, 12, 'sp12_v_b_9')
// (12, 12, 'sp4_v_b_16')
// (12, 13, 'sp12_v_b_6')
// (12, 13, 'sp4_v_b_5')
// (12, 14, 'sp12_v_b_5')
// (12, 15, 'sp12_v_b_2')
// (12, 16, 'sp12_v_b_1')
// (13, 10, 'logic_op_tnl_5')
// (13, 11, 'logic_op_lft_5')
// (13, 12, 'logic_op_bnl_5')

reg n35 = 0;
// (11, 10, 'local_g3_1')
// (11, 10, 'lutff_2/in_0')
// (11, 10, 'neigh_op_tnr_1')
// (11, 11, 'neigh_op_rgt_1')
// (11, 12, 'neigh_op_bnr_1')
// (12, 10, 'neigh_op_top_1')
// (12, 11, 'local_g3_1')
// (12, 11, 'lutff_1/in_1')
// (12, 11, 'lutff_1/out')
// (12, 12, 'neigh_op_bot_1')
// (13, 10, 'logic_op_tnl_1')
// (13, 11, 'logic_op_lft_1')
// (13, 12, 'logic_op_bnl_1')

reg n36 = 0;
// (11, 10, 'local_g3_3')
// (11, 10, 'lutff_2/in_2')
// (11, 10, 'neigh_op_tnr_3')
// (11, 11, 'neigh_op_rgt_3')
// (11, 12, 'neigh_op_bnr_3')
// (12, 10, 'neigh_op_top_3')
// (12, 11, 'local_g1_3')
// (12, 11, 'lutff_3/in_1')
// (12, 11, 'lutff_3/out')
// (12, 12, 'neigh_op_bot_3')
// (13, 10, 'logic_op_tnl_3')
// (13, 11, 'logic_op_lft_3')
// (13, 12, 'logic_op_bnl_3')

reg n37 = 0;
// (11, 10, 'neigh_op_tnr_0')
// (11, 11, 'local_g3_0')
// (11, 11, 'lutff_0/in_1')
// (11, 11, 'neigh_op_rgt_0')
// (11, 12, 'neigh_op_bnr_0')
// (12, 10, 'neigh_op_top_0')
// (12, 11, 'local_g3_0')
// (12, 11, 'lutff_0/in_1')
// (12, 11, 'lutff_0/out')
// (12, 12, 'neigh_op_bot_0')
// (13, 10, 'logic_op_tnl_0')
// (13, 11, 'logic_op_lft_0')
// (13, 12, 'logic_op_bnl_0')

reg n38 = 0;
// (11, 10, 'neigh_op_tnr_4')
// (11, 11, 'local_g2_4')
// (11, 11, 'lutff_0/in_0')
// (11, 11, 'neigh_op_rgt_4')
// (11, 12, 'neigh_op_bnr_4')
// (12, 10, 'neigh_op_top_4')
// (12, 11, 'local_g3_4')
// (12, 11, 'lutff_4/in_1')
// (12, 11, 'lutff_4/out')
// (12, 12, 'neigh_op_bot_4')
// (13, 10, 'logic_op_tnl_4')
// (13, 11, 'logic_op_lft_4')
// (13, 12, 'logic_op_bnl_4')

reg n39 = 0;
// (11, 10, 'neigh_op_tnr_7')
// (11, 11, 'local_g3_7')
// (11, 11, 'lutff_0/in_2')
// (11, 11, 'neigh_op_rgt_7')
// (11, 12, 'neigh_op_bnr_7')
// (12, 10, 'neigh_op_top_7')
// (12, 11, 'local_g1_7')
// (12, 11, 'lutff_7/in_1')
// (12, 11, 'lutff_7/out')
// (12, 12, 'neigh_op_bot_7')
// (13, 10, 'logic_op_tnl_7')
// (13, 11, 'logic_op_lft_7')
// (13, 12, 'logic_op_bnl_7')

reg n40 = 0;
// (11, 11, 'neigh_op_tnr_0')
// (11, 12, 'neigh_op_rgt_0')
// (11, 13, 'neigh_op_bnr_0')
// (12, 11, 'neigh_op_top_0')
// (12, 12, 'local_g1_0')
// (12, 12, 'lutff_0/in_3')
// (12, 12, 'lutff_0/out')
// (12, 12, 'lutff_2/in_3')
// (12, 12, 'lutff_3/in_0')
// (12, 12, 'lutff_5/in_0')
// (12, 12, 'lutff_6/in_3')
// (12, 13, 'neigh_op_bot_0')
// (13, 11, 'logic_op_tnl_0')
// (13, 12, 'logic_op_lft_0')
// (13, 13, 'logic_op_bnl_0')

reg n41 = 0;
// (11, 11, 'neigh_op_tnr_1')
// (11, 12, 'neigh_op_rgt_1')
// (11, 13, 'neigh_op_bnr_1')
// (12, 11, 'neigh_op_top_1')
// (12, 12, 'local_g3_1')
// (12, 12, 'lutff_0/in_0')
// (12, 12, 'lutff_1/in_3')
// (12, 12, 'lutff_1/out')
// (12, 12, 'lutff_2/in_0')
// (12, 12, 'lutff_3/in_3')
// (12, 12, 'lutff_5/in_3')
// (12, 12, 'lutff_6/in_0')
// (12, 13, 'neigh_op_bot_1')
// (13, 11, 'logic_op_tnl_1')
// (13, 12, 'logic_op_lft_1')
// (13, 13, 'logic_op_bnl_1')

wire io_13_11_0;
// (11, 11, 'neigh_op_tnr_2')
// (11, 12, 'neigh_op_rgt_2')
// (11, 13, 'neigh_op_bnr_2')
// (12, 11, 'neigh_op_top_2')
// (12, 12, 'lutff_2/out')
// (12, 13, 'neigh_op_bot_2')
// (13, 11, 'io_0/D_OUT_0')
// (13, 11, 'io_0/PAD')
// (13, 11, 'local_g0_2')
// (13, 11, 'logic_op_tnl_2')
// (13, 12, 'logic_op_lft_2')
// (13, 13, 'logic_op_bnl_2')

wire io_13_12_1;
// (11, 11, 'neigh_op_tnr_3')
// (11, 12, 'neigh_op_rgt_3')
// (11, 13, 'neigh_op_bnr_3')
// (12, 11, 'neigh_op_top_3')
// (12, 12, 'lutff_3/out')
// (12, 13, 'neigh_op_bot_3')
// (13, 11, 'logic_op_tnl_3')
// (13, 12, 'io_1/D_OUT_0')
// (13, 12, 'io_1/PAD')
// (13, 12, 'local_g0_3')
// (13, 12, 'logic_op_lft_3')
// (13, 13, 'logic_op_bnl_3')

wire io_13_11_1;
// (11, 11, 'neigh_op_tnr_5')
// (11, 12, 'neigh_op_rgt_5')
// (11, 13, 'neigh_op_bnr_5')
// (12, 11, 'neigh_op_top_5')
// (12, 12, 'lutff_5/out')
// (12, 13, 'neigh_op_bot_5')
// (13, 11, 'io_1/D_OUT_0')
// (13, 11, 'io_1/PAD')
// (13, 11, 'local_g0_5')
// (13, 11, 'logic_op_tnl_5')
// (13, 12, 'logic_op_lft_5')
// (13, 13, 'logic_op_bnl_5')

wire io_13_12_0;
// (11, 11, 'neigh_op_tnr_6')
// (11, 12, 'neigh_op_rgt_6')
// (11, 13, 'neigh_op_bnr_6')
// (12, 11, 'neigh_op_top_6')
// (12, 12, 'lutff_6/out')
// (12, 13, 'neigh_op_bot_6')
// (13, 11, 'logic_op_tnl_6')
// (13, 12, 'io_0/D_OUT_0')
// (13, 12, 'io_0/PAD')
// (13, 12, 'local_g0_6')
// (13, 12, 'logic_op_lft_6')
// (13, 13, 'logic_op_bnl_6')

wire n46;
// (12, 10, 'carry_in_mux')
// (12, 10, 'lutff_0/in_3')

wire n47;
// (12, 10, 'lutff_0/cout')
// (12, 10, 'lutff_1/in_3')

wire n48;
// (12, 10, 'lutff_1/cout')
// (12, 10, 'lutff_2/in_3')

wire n49;
// (12, 10, 'lutff_2/cout')
// (12, 10, 'lutff_3/in_3')

wire n50;
// (12, 10, 'lutff_3/cout')
// (12, 10, 'lutff_4/in_3')

wire n51;
// (12, 10, 'lutff_4/cout')
// (12, 10, 'lutff_5/in_3')

wire n52;
// (12, 10, 'lutff_5/cout')
// (12, 10, 'lutff_6/in_3')

wire n53;
// (12, 10, 'lutff_6/cout')
// (12, 10, 'lutff_7/in_3')

wire n54;
// (12, 10, 'lutff_7/cout')
// (12, 11, 'carry_in')
// (12, 11, 'carry_in_mux')
// (12, 11, 'lutff_0/in_3')

wire n55;
// (12, 11, 'lutff_0/cout')
// (12, 11, 'lutff_1/in_3')

wire n56;
// (12, 11, 'lutff_1/cout')
// (12, 11, 'lutff_2/in_3')

wire n57;
// (12, 11, 'lutff_2/cout')
// (12, 11, 'lutff_3/in_3')

wire n58;
// (12, 11, 'lutff_3/cout')
// (12, 11, 'lutff_4/in_3')

wire n59;
// (12, 11, 'lutff_4/cout')
// (12, 11, 'lutff_5/in_3')

wire n60;
// (12, 11, 'lutff_5/cout')
// (12, 11, 'lutff_6/in_3')

wire n61;
// (12, 11, 'lutff_6/cout')
// (12, 11, 'lutff_7/in_3')

wire n62;
// FF (12, 10, 7)

wire n63;
// FF (12, 10, 6)

wire n64;
// FF (12, 10, 1)

wire n65;
// FF (12, 11, 6)

// Carry-In for (12 10)
assign n46 = 1;

wire n66;
// FF (12, 10, 0)

wire n67;
// FF (12, 11, 7)

wire n68;
// FF (12, 10, 3)

wire n69;
// FF (12, 11, 4)

wire n70;
// FF (12, 10, 2)

wire n71;
// FF (12, 12, 1)

wire n72;
// FF (12, 11, 5)

wire n73;
// FF (12, 12, 0)

wire n74;
// FF (12, 11, 2)

wire n75;
// FF (12, 11, 3)

wire n76;
// FF (11, 12, 2)

wire n77;
// FF (12, 11, 0)

wire n78;
// FF (12, 11, 1)

wire n79;
// FF (11, 11, 2)

wire n80;
// FF (11, 11, 4)

wire n81;
// FF (11, 11, 6)

wire n82;
// FF (11, 9, 1)

wire n83;
// FF (11, 9, 0)

wire n84;
// FF (12, 9, 0)

wire n85;
// FF (12, 10, 5)

wire n86;
// FF (12, 9, 1)

wire n87;
// FF (12, 10, 4)

assign io_13_9_1  = 1'b1;
assign n62        = /* LUT   12 10  7 */ n53 ? n32 ? 1'b0 ? 1'b1 : 1'b0 : 1'b0 ? 1'b0 : 1'b1 : n32 ? 1'b0 ? 1'b0 : 1'b1 : 1'b0 ? 1'b1 : 1'b0;
assign io_13_12_0 = /* LUT   12 12  6 */ n40 ? 1'b0 : n41 ? 1'b1 : 1'b0;
assign n13        = /* LUT   11 10  5 */ n10 ? n12 ? n26 ? 1'b0 : n11 ? 1'b1 : 1'b0 : 1'b0 : 1'b0;
assign n63        = /* LUT   12 10  6 */ n52 ? n31 ? 1'b0 ? 1'b1 : 1'b0 : 1'b0 ? 1'b0 : 1'b1 : n31 ? 1'b0 ? 1'b0 : 1'b1 : 1'b0 ? 1'b1 : 1'b0;
assign io_13_11_1 = /* LUT   12 12  5 */ n41 ? 1'b0 : n40 ? 1'b1 : 1'b0;
assign n64        = /* LUT   12 10  1 */ n47 ? n25 ? 1'b0 ? 1'b1 : 1'b0 : 1'b0 ? 1'b0 : 1'b1 : n25 ? 1'b0 ? 1'b0 : 1'b1 : 1'b0 ? 1'b1 : 1'b0;
assign n65        = /* LUT   12 11  6 */ n60 ? n33 ? 1'b0 ? 1'b1 : 1'b0 : 1'b0 ? 1'b0 : 1'b1 : n33 ? 1'b0 ? 1'b0 : 1'b1 : 1'b0 ? 1'b1 : 1'b0;
assign n66        = /* LUT   12 10  0 */ n46 ? n26 ? 1'b0 ? 1'b1 : 1'b0 : 1'b0 ? 1'b0 : 1'b1 : n26 ? 1'b0 ? 1'b0 : 1'b1 : 1'b0 ? 1'b1 : 1'b0;
assign io_13_12_1 = /* LUT   12 12  3 */ n41 ? 1'b0 : n40 ? 1'b0 : 1'b1;
assign n67        = /* LUT   12 11  7 */ n61 ? n39 ? 1'b0 : 1'b1 : n39 ? 1'b1 : 1'b0;
assign n68        = /* LUT   12 10  3 */ n49 ? n28 ? 1'b0 ? 1'b1 : 1'b0 : 1'b0 ? 1'b0 : 1'b1 : n28 ? 1'b0 ? 1'b0 : 1'b1 : 1'b0 ? 1'b1 : 1'b0;
assign io_13_11_0 = /* LUT   12 12  2 */ n40 ? n41 ? 1'b1 : 1'b0 : 1'b0;
assign n69        = /* LUT   12 11  4 */ n58 ? n38 ? 1'b0 ? 1'b1 : 1'b0 : 1'b0 ? 1'b0 : 1'b1 : n38 ? 1'b0 ? 1'b0 : 1'b1 : 1'b0 ? 1'b1 : 1'b0;
assign n70        = /* LUT   12 10  2 */ n48 ? n27 ? 1'b0 ? 1'b1 : 1'b0 : 1'b0 ? 1'b0 : 1'b1 : n27 ? 1'b0 ? 1'b0 : 1'b1 : 1'b0 ? 1'b1 : 1'b0;
assign n71        = /* LUT   12 12  1 */ n41 ? n17 ? 1'b0 : 1'b1 : n17 ? 1'b1 : 1'b0;
assign n72        = /* LUT   12 11  5 */ n59 ? n34 ? 1'b0 ? 1'b1 : 1'b0 : 1'b0 ? 1'b0 : 1'b1 : n34 ? 1'b0 ? 1'b0 : 1'b1 : 1'b0 ? 1'b1 : 1'b0;
assign n73        = /* LUT   12 12  0 */ n40 ? n17 ? n41 ? 1'b0 : 1'b1 : 1'b1 : n17 ? n41 ? 1'b1 : 1'b0 : 1'b0;
assign n74        = /* LUT   12 11  2 */ n56 ? n3 ? 1'b0 ? 1'b1 : 1'b0 : 1'b0 ? 1'b0 : 1'b1 : n3 ? 1'b0 ? 1'b0 : 1'b1 : 1'b0 ? 1'b1 : 1'b0;
assign n16        = /* LUT   11 11  1 */ n11 ? n15 ? n10 ? n14 ? 1'b0 : 1'b1 : 1'b1 : 1'b1 : 1'b1;
assign n75        = /* LUT   12 11  3 */ n57 ? n36 ? 1'b0 ? 1'b1 : 1'b0 : 1'b0 ? 1'b0 : 1'b1 : n36 ? 1'b0 ? 1'b0 : 1'b1 : 1'b0 ? 1'b1 : 1'b0;
assign n15        = /* LUT   11 11  0 */ n28 ? 1'b0 : n39 ? 1'b0 : n37 ? 1'b0 : n38 ? 1'b0 : 1'b1;
assign n76        = /* LUT   11 12  2 */ n2 ? n23 ? 1'b0 : 1'b1 : n23 ? 1'b1 : 1'b0;
assign n77        = /* LUT   12 11  0 */ n54 ? n37 ? 1'b0 ? 1'b1 : 1'b0 : 1'b0 ? 1'b0 : 1'b1 : n37 ? 1'b0 ? 1'b0 : 1'b1 : 1'b0 ? 1'b1 : 1'b0;
assign n18        = /* LUT   11 11  3 */ n21 ? n4 ? n7 ? n23 ? 1'b1 : 1'b0 : 1'b0 : 1'b0 : 1'b0;
assign n78        = /* LUT   12 11  1 */ n55 ? n35 ? 1'b0 ? 1'b1 : 1'b0 : 1'b0 ? 1'b0 : 1'b1 : n35 ? 1'b0 ? 1'b0 : 1'b1 : 1'b0 ? 1'b1 : 1'b0;
assign n79        = /* LUT   11 11  2 */ n17 ? n16 ? 1'b0 : 1'b1 : 1'b0;
assign n20        = /* LUT   11 11  5 */ n4 ? n5 ? 1'b0 : n7 ? n19 ? 1'b1 : 1'b0 : 1'b0 : 1'b0;
assign n10        = /* LUT   11 10  2 */ n34 ? 1'b0 : n36 ? 1'b0 : n32 ? 1'b0 : n35 ? 1'b0 : 1'b1;
assign n80        = /* LUT   11 11  4 */ n2 ? n18 ? n19 ? 1'b0 : 1'b1 : n19 ? 1'b1 : 1'b0 : n19 ? 1'b1 : 1'b0;
assign n11        = /* LUT   11 10  3 */ n33 ? 1'b0 : n3 ? 1'b0 : n29 ? 1'b0 : n31 ? 1'b0 : 1'b1;
assign n22        = /* LUT   11 11  7 */ n21 ? 1'b0 : n8 ? n23 ? 1'b1 : 1'b0 : 1'b0;
assign n9         = /* LUT   11 10  0 */ n13 ? n22 ? n15 ? n20 ? 1'b1 : 1'b0 : 1'b0 : 1'b0 : 1'b0;
assign n81        = /* LUT   11 11  6 */ n2 ? n21 ? n23 ? n4 ? 1'b0 : 1'b1 : 1'b1 : n23 ? n4 ? 1'b1 : 1'b0 : 1'b0 : n21 ? 1'b1 : 1'b0;
assign n82        = /* LUT   11  9  1 */ n18 ? n19 ? n8 ? n5 ? 1'b0 : 1'b1 : n5 ? 1'b1 : 1'b0 : n8 ? 1'b1 : 1'b0 : n8 ? 1'b1 : 1'b0;
assign n6         = /* LUT   11 10  1 */ n2 ? 1'b1 : n9 ? 1'b1 : 1'b0;
assign n83        = /* LUT   11  9  0 */ n4 ? n21 ? n23 ? n7 ? 1'b0 : 1'b1 : n7 ? 1'b1 : 1'b0 : n7 ? 1'b1 : 1'b0 : n7 ? 1'b1 : 1'b0;
assign n2         = /* LUT   11 10  6 */ n15 ? n10 ? n14 ? n11 ? 1'b1 : 1'b0 : 1'b0 : 1'b0 : 1'b0;
assign n84        = /* LUT   12  9  0 */ n19 ? n5 ? n18 ? 1'b0 : 1'b1 : n18 ? 1'b1 : 1'b0 : n5 ? 1'b1 : 1'b0;
assign n85        = /* LUT   12 10  5 */ n51 ? n30 ? 1'b0 ? 1'b1 : 1'b0 : 1'b0 ? 1'b0 : 1'b1 : n30 ? 1'b0 ? 1'b0 : 1'b1 : 1'b0 ? 1'b1 : 1'b0;
assign n86        = /* LUT   12  9  1 */ n4 ? n23 ? 1'b0 : 1'b1 : n23 ? 1'b1 : 1'b0;
assign n14        = /* LUT   11 10  7 */ n30 ? 1'b0 : n27 ? 1'b0 : n26 ? 1'b0 : n25 ? 1'b0 : 1'b1;
assign n87        = /* LUT   12 10  4 */ n50 ? n29 ? 1'b0 ? 1'b1 : 1'b0 : 1'b0 ? 1'b0 : 1'b1 : n29 ? 1'b0 ? 1'b0 : 1'b1 : 1'b0 ? 1'b1 : 1'b0;
assign n12        = /* LUT   11 10  4 */ n30 ? 1'b0 : n25 ? 1'b0 : n27 ? 1'b0 : 1'b1;
assign n54        = /* CARRY 12 10  7 */ (n32 & 1'b0) | ((n32 | 1'b0) & n53);
assign n53        = /* CARRY 12 10  6 */ (n31 & 1'b0) | ((n31 | 1'b0) & n52);
assign n48        = /* CARRY 12 10  1 */ (n25 & 1'b0) | ((n25 | 1'b0) & n47);
assign n61        = /* CARRY 12 11  6 */ (n33 & 1'b0) | ((n33 | 1'b0) & n60);
assign n47        = /* CARRY 12 10  0 */ (n26 & 1'b0) | ((n26 | 1'b0) & n46);
assign n50        = /* CARRY 12 10  3 */ (n28 & 1'b0) | ((n28 | 1'b0) & n49);
assign n59        = /* CARRY 12 11  4 */ (n38 & 1'b0) | ((n38 | 1'b0) & n58);
assign n49        = /* CARRY 12 10  2 */ (n27 & 1'b0) | ((n27 | 1'b0) & n48);
assign n60        = /* CARRY 12 11  5 */ (n34 & 1'b0) | ((n34 | 1'b0) & n59);
assign n57        = /* CARRY 12 11  2 */ (n3 & 1'b0) | ((n3 | 1'b0) & n56);
assign n58        = /* CARRY 12 11  3 */ (n36 & 1'b0) | ((n36 | 1'b0) & n57);
assign n55        = /* CARRY 12 11  0 */ (n37 & 1'b0) | ((n37 | 1'b0) & n54);
assign n56        = /* CARRY 12 11  1 */ (n35 & 1'b0) | ((n35 | 1'b0) & n55);
assign n52        = /* CARRY 12 10  5 */ (n30 & 1'b0) | ((n30 | 1'b0) & n51);
assign n51        = /* CARRY 12 10  4 */ (n29 & 1'b0) | ((n29 | 1'b0) & n50);
/* FF 12 10  7 */ always @(posedge io_0_8_1) if (1'b1) n32 <= 1'b0 ? 1'b0 : n62;
/* FF 12 10  6 */ always @(posedge io_0_8_1) if (1'b1) n31 <= 1'b0 ? 1'b0 : n63;
/* FF 12 10  1 */ always @(posedge io_0_8_1) if (1'b1) n25 <= 1'b0 ? 1'b0 : n64;
/* FF 12 11  6 */ always @(posedge io_0_8_1) if (1'b1) n33 <= 1'b0 ? 1'b0 : n65;
/* FF 12 10  0 */ always @(posedge io_0_8_1) if (1'b1) n26 <= 1'b0 ? 1'b0 : n66;
/* FF 12 11  7 */ always @(posedge io_0_8_1) if (1'b1) n39 <= 1'b0 ? 1'b0 : n67;
/* FF 12 10  3 */ always @(posedge io_0_8_1) if (1'b1) n28 <= 1'b0 ? 1'b0 : n68;
/* FF 12 11  4 */ always @(posedge io_0_8_1) if (1'b1) n38 <= 1'b0 ? 1'b0 : n69;
/* FF 12 10  2 */ always @(posedge io_0_8_1) if (1'b1) n27 <= 1'b0 ? 1'b0 : n70;
/* FF 12 12  1 */ always @(posedge io_0_8_1) if (1'b1) n41 <= 1'b0 ? 1'b0 : n71;
/* FF 12 11  5 */ always @(posedge io_0_8_1) if (1'b1) n34 <= 1'b0 ? 1'b0 : n72;
/* FF 12 12  0 */ always @(posedge io_0_8_1) if (1'b1) n40 <= 1'b0 ? 1'b0 : n73;
/* FF 12 11  2 */ always @(posedge io_0_8_1) if (1'b1) n3 <= 1'b0 ? 1'b0 : n74;
/* FF 12 11  3 */ always @(posedge io_0_8_1) if (1'b1) n36 <= 1'b0 ? 1'b0 : n75;
/* FF 11 12  2 */ always @(posedge io_0_8_1) if (1'b1) n23 <= 1'b0 ? 1'b0 : n76;
/* FF 12 11  0 */ always @(posedge io_0_8_1) if (1'b1) n37 <= 1'b0 ? 1'b0 : n77;
/* FF 12 11  1 */ always @(posedge io_0_8_1) if (1'b1) n35 <= 1'b0 ? 1'b0 : n78;
/* FF 11 11  2 */ always @(posedge io_0_8_1) if (1'b1) n17 <= n9 ? 1'b1 : n79;
/* FF 11 11  4 */ always @(posedge io_0_8_1) if (1'b1) n19 <= n9 ? 1'b0 : n80;
/* FF 11 11  6 */ always @(posedge io_0_8_1) if (1'b1) n21 <= n9 ? 1'b0 : n81;
/* FF 11  9  1 */ always @(posedge io_0_8_1) if (n6) n8 <= n9 ? 1'b0 : n82;
/* FF 11  9  0 */ always @(posedge io_0_8_1) if (n6) n7 <= n9 ? 1'b0 : n83;
/* FF 12  9  0 */ always @(posedge io_0_8_1) if (n2) n5 <= 1'b0 ? 1'b0 : n84;
/* FF 12 10  5 */ always @(posedge io_0_8_1) if (1'b1) n30 <= 1'b0 ? 1'b0 : n85;
/* FF 12  9  1 */ always @(posedge io_0_8_1) if (n2) n4 <= 1'b0 ? 1'b0 : n86;
/* FF 12 10  4 */ always @(posedge io_0_8_1) if (1'b1) n29 <= 1'b0 ? 1'b0 : n87;

endmodule

