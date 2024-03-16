#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <time.h>       /* time */
//path cd /Users/dragonhead/Documents/eec_prog
//compile gcc -Wall -o 01TSMant01 01TSMant01.c
int main (){
    int num_of_new_ants_starts=8;/*number how often ants are placed at 13 towns after pheromone 0.01 and random*/
    int town=13;
    double length[town][town];
    int ant=13;
    int a,b,j,stop,r,ant_no_move,t,num_of_towns_ant_has_vis;
    int c,go_to,e,best_ant,it,from,to,best_gamma_run, best_it;
    int best_best_ant;
    int rl,counter_rl;
    int random[ant];
    int tabu_best[town];
    int tabu_ant[num_of_new_ants_starts][ant][town];
    double transition_probability_new[town][town];
    double tau_t_ij_old[town][town];
    double tau_t_ij_new[town][town];
    double delta_tau_ij_k_ant;
    double evap=0.7;
    double alpha,beta;
    double visibility_ij_pow_beta[town][town];
    double nominator_new[town][town];
    double denominator_new;
    double visibility_ij;
    int not_visited_list[ant][town];
    double transition_probability_max,tour_lenth[ant];
    double tour_lenth_min[num_of_new_ants_starts];
    int alpha_run,beta_run,gamma_run;
    int alpha_run_max=1;
    int beta_run_max=1;
    int gamma_run_max=75;/*number of new start with new random and new 0.01 pheromone*/
    double lenth_min_const_alpha_beta[alpha_run_max][beta_run_max];
    double q=10000;
    double sum_of_tour_lenth_min,sum_lenth_min_const_alpha_beta[alpha_run_max][beta_run_max];
    int output=0;
    int divisor_on=1;
    int min_length_at_END;
    double minlgthofallgams_conalbelgth[alpha_run_max][beta_run_max];
    int tabu_list_of_best_ant_of_const_alpha_beta[alpha_run_max][beta_run_max][town];
    time_t tim;
    length[0][0]=0;/*AA*/
    length[0][1]=360;/*AB*/
    length[0][2]=1117;/*AC*/
    length[0][3]=4570;/*AD*/
    length[0][4]=834;/*AE*/
    length[0][5]=701;/*AF*/
    length[0][6]=4254;/*AG*/
    length[0][7]=4432;/*AH*/
    length[0][8]=222;/*AI*/
    length[0][9]=2253;/*AJ*/
    length[0][10]=2682;/*AK*/
    length[0][11]=2437;/*AL*/
    length[0][12]=1738;/*AM*/
    length[1][0]=360;/*BA*/
    length[1][1]=0;/*BB*/
    length[1][2]=1262;/*BC*/
    length[1][3]=4650;/*BD*/
    length[1][4]=1022;/*BE*/
    length[1][5]=347;/*BF*/
    length[1][6]=4443;/*G*/
    length[1][7]=4544;/*H*/
    length[1][8]=155;/*I*/
    length[1][9]=2605;/*J*/
    length[1][10]=2845;/*K*/
    length[1][11]=2789;/*L*/
    length[1][12]=2090;/*M*/
    length[2][0]=1117;/*CA*/
    length[2][1]=1262;/*CB*/
    length[2][2]=0   ;/*CC*/
    length[2][3]=3410;/*CD*/
    length[2][4]=474; /*CE*/
    length[2][5]=1574;/*CF*/
    length[2][6]=3022;/*G*/
    length[2][7]=3302;/*H*/
    length[2][8]=1214;/*I*/
    length[2][9]=1715;/*J*/
    length[2][10]=1605;/*K*/
    length[2][11]=1792;/*L*/
    length[2][12]=1482;/*M*/
    length[3][0]=4570;/*DA*/
    length[3][1]=4650;/*DB*/
    length[3][2]=3410;/*DC*/
    length[3][3]=   0;/*DD*/
    length[3][4]=3814;/*DE*/
    length[3][5]=4958;/*DF*/
    length[3][6]=613;/*G*/
    length[3][7]=1291;/*H*/
    length[3][8]=4600;/*I*/
    length[3][9]=3085;/*J*/
    length[3][10]=2005;/*K*/
    length[3][11]=2813;/*L*/
    length[3][12]=3640;/*M*/
    length[4][0]=834;/*EA*/
    length[4][1]=1022;/*EB*/
    length[4][2]=474; /*EC*/
    length[4][3]=3814;/*ED*/
    length[4][4]=0   ;/*EE*/
    length[4][5]=1392;/*EF*/
    length[4][6]=3480;/*G*/
    length[4][7]=3725;/*H*/
    length[4][8]=915;/*I*/
    length[4][9]=1678;/*J*/
    length[4][10]=1907 ;/*K*/
    length[4][11]=1806;/*L*/
    length[4][12]=1290;/*M*/
    length[5][0]=701;/*FA*/
    length[5][1]=347;/*FB*/
    length[5][2]=1574;/*FC*/
    length[5][3]=4958;/*FD*/
    length[5][4]=1392;/*FE*/
    length[5][5]=0   ;/*FE*/
    length[5][6]=4773;/*G*/
    length[5][7]=4886;/*H*/
    length[5][8]=310;/*I*/
    length[5][9]=2957;/*J*/
    length[5][10]=3154;/*K*/
    length[5][11]=3141;/*L*/
    length[5][12]=2442;/*M*/
    length[6][0]=4254;/*Ga*/
    length[6][1]=4443;/*Gb*/
    length[6][2]=3022;/*Gc*/
    length[6][3]=613;/*Gd*/
    length[6][4]=3480;/*Ge*/
    length[6][5]=4773;/*Gf*/
    length[6][6]=0;/*Gg*/
    length[6][7]=1816;/*Gh*/
    length[6][8]=4342;/*Gi*/
    length[6][9]=2477;/*Gj*/
    length[6][10]=1626;/*Gk*/
    length[6][11]=2205;/*Gl*/
    length[6][12]=3174;/*Gm*/
    length[7][0]=4432;/*Ha*/
    length[7][1]=4544;/*Hb*/
    length[7][2]=3302;/*Hc*/
    length[7][3]=1291;/*Hd*/
    length[7][4]=3725;/*He*/
    length[7][5]=4886;/*Hf*/
    length[7][6]=1816;/*Hg*/
    length[7][7]=0;/*Hh*/
    length[7][8]=4514;/*Hi*/
    length[7][9]=3710;/*Hj*/
    length[7][10]=2093;/*Hk*/
    length[7][11]=3392;/*Hl*/
    length[7][12]=4138;/*Hm*/
    length[8][0]=222;/*Ia*/
    length[8][1]=155;/*Ib*/
    length[8][2]=1214;/*Ic*/
    length[8][3]=4600;/*Id*/
    length[8][4]=915;/*Ie*/
    length[8][5]=310;/*If*/
    length[8][6]=4342;/*Ig*/
    length[8][7]=4514;/*Ih*/
    length[8][8]=0;/*Ii*/
    length[8][9]=2475;/*Ij*/
    length[8][10]=2765;/*Ik*/
    length[8][11]=2659;/*Il*/
    length[8][12]=1960;/*Im*/
    length[9][0]=2253;/*Ja*/
    length[9][1]=2605;/*Jb*/
    length[9][2]=1715;/*Jc*/
    length[9][3]=3085;/*Jd*/
    length[9][4]=1678;/*Je*/
    length[9][5]=2957;/*Jf*/
    length[9][6]=2477;/*Jg*/
    length[9][7]=3710;/*Jh*/
    length[9][8]=2475;/*Ji*/
    length[9][9]=0;/*Jj*/
    length[9][10]=1646;/*Jk*/
    length[9][11]=259;/*Jl*/
    length[9][12]=557;/*Jm*/
    length[10][0]=2682;/*Ka*/
    length[10][1]=2845;/*Kb*/
    length[10][2]=1605;/*Kc*/
    length[10][3]=2005;/*Kd*/
    length[10][4]=1907;/*Ke*/
    length[10][5]=3154;/*Kf*/
    length[10][6]=1626;/*Kg*/
    length[10][7]=2093;/*Kh*/
    length[10][8]=2765;/*Ki*/
    length[10][9]=1646;/*Kj*/
    length[10][10]=0;/*Kk*/
    length[10][11]=1466;/*Kl*/
    length[10][12]=2077;/*Km*/
    length[11][0]=2437;/*La*/
    length[11][1]=2789;/*Lb*/
    length[11][2]=1792;/*Lc*/
    length[11][3]=2813;/*Ld*/
    length[11][4]=1806;/*Le*/
    length[11][5]=3141;/*Lf*/
    length[11][6]=2205;/*Lg*/
    length[11][7]=3392;/*Lh*/
    length[11][8]=2659;/*Li*/
    length[11][9]=259;/*Lj*/
    length[11][10]=1466;/*Lk*/
    length[11][11]=0;/*Ll*/
    length[11][12]=818;/*Lm*/
    
    length[12][0]=1738;/*Ma*/
    length[12][1]=2090;/*Mb*/
    length[12][2]=1482;/*Mc*/
    length[12][3]=3640;/*Md*/
    length[12][4]=1290;/*Me*/
    length[12][5]=2442;/*Mf*/
    length[12][6]=3174;/*Mg*/
    length[12][7]=4138;/*Mh*/
    length[12][8]=1960;/*Mi*/
    length[12][9]=557;/*Mj*/
    length[12][10]=2077;/*Mk*/
    length[12][11]=818;/*Ml*/
    length[12][12]=0;/*Mm*/
    srand((unsigned) time(&tim));
    printf("Divisor_on: %2d \n", divisor_on);
    printf("towns:%2d ants:%2d Q1:%8.1f num of ants' starts:%2d number of new starts %2d \n",town,ant, q,num_of_new_ants_starts,gamma_run_max);
    beta=0.9;
    for (beta_run=0; beta_run<beta_run_max; beta_run++) {/*b run*/
        beta=beta+0.1;
        for (a=0; a<town; a++) {/*for (t=0; t<town; t++) {*/
            for (b=0; b<town; b++) {
                if(a!=b){
                visibility_ij=1/length[a][b];
                visibility_ij_pow_beta[a][b]=pow(visibility_ij,beta);
                }
                else{
                    visibility_ij_pow_beta[a][b]=0;
                }
            }
        }/*for (t=0; t<town; t++) {*/
        alpha=0.9;
        for (alpha_run=0; alpha_run<alpha_run_max; alpha_run++) {/*a run*/
            alpha=alpha+0.1;
            printf("evapo: %4.2f alpha: %4.2f beta : %4.2f \n",evap,alpha,beta);
            minlgthofallgams_conalbelgth[alpha_run][beta_run]=1000000;
            best_gamma_run=0;
            best_best_ant=100;
            sum_lenth_min_const_alpha_beta[alpha_run][beta_run]=0;;
for (gamma_run=0; gamma_run<gamma_run_max; gamma_run++) {/*for (gamma_run=0; gamma_run<numb_of_new_exp; gamma_run++) {*/
    sum_of_tour_lenth_min=0;
            //init for cost alpha and beta
            lenth_min_const_alpha_beta[alpha_run][beta_run]=1000000;
            for (a=0; a<town; a++) {/*for (t=0; t<town; t++) {*/
                for (b=0; b<town; b++) {
                    tau_t_ij_new[a][b]=0.01;/*not needed*/
                }
            }/*for (t=0; t<town; t++) {*/
            it=0;
            num_of_towns_ant_has_vis=0;
            if(output==1){printf("ncycle%2d: \n",num_of_towns_ant_has_vis);}
            //place ant on town and first next town is random
            for (a=0; a<ant; a++) {/*for (a=0; a<ant; a++) {*/
                tabu_ant[it][a][num_of_towns_ant_has_vis]=a;/*ant a at town t */
                for (j=1; j<town; j++) {tabu_ant[it][a][j]=a;}//tabulist filled with initial town
            }/*for (i=0; i<ant; i++) {*/
            //ant1 is at town1,ant2 is at town2......ant1 is at town1,ant2 is at town2......ant1 is at town1,ant2 is at town2......ant1 is at town1,ant2 is at town2......
            
            ant_no_move=0;
            while(ant_no_move==0){/*while(ant_no_move==0){*/
                ant_no_move=1;
                stop=0;
                while (stop==0) {/*while (stop==0)*/
                    for (r=0; r<town; r++) {/*or (a=0; a<13; a++) {*/
                        rl=rand()%town;
                        random[r]=rl;
                        
                    }/*or (a=0; a<13; a++) {*/
                    stop=1;
                    for (a=0; a<town; a++) {/*or (a=0; a<13; a++) {*/
                        counter_rl=0;
                        for (b=0; b<town; b++) {/*for (b=0; b<13; b++) {*/
                            if(random[a]==random[b]){counter_rl++;}
                        }/*for (b=0; b<13; b++) {*/
                        if(2<=counter_rl){/*2<=counter_rl no number is double*/
                            stop=0;
                        }/*2<=counter_rl no number is double*/
                    }/*or (a=0; a<town; a++) {*/
                }/*while (stop==0)*/
                
                for (a=0; a<town; a++) {/*or (a=0; a<13; a++) {*/
                    if(tabu_ant[it][a][0]==random[a]){
                        ant_no_move=0;
                    }
                    else{tabu_ant[it][a][1]=random[a];}
                }/*or (a=0; a<13; a++) {*/
            }/*while(ant_no_move==0){*/
//ant1 is at town random1.....ant2 is at town random2.....ant3 is at town random3.....
            
            num_of_towns_ant_has_vis=1;
            if(output==1){printf("mcycle%2d: \n",num_of_towns_ant_has_vis);}
            //transition_probability adjust
            
            //evaporation for all town
            for (a=0; a<town; a++) {
                for (b=0; b<town; b++){
                    tau_t_ij_old[a][b]=tau_t_ij_new[a][b];
                    tau_t_ij_new[a][b]=evap*tau_t_ij_old[a][b];
                }
            }
            for (a=0; a<ant; a++) {/*or (a=0; a<13; a++) {*/
                from=tabu_ant[it][a][num_of_towns_ant_has_vis-1];
                to=  tabu_ant[it][a][num_of_towns_ant_has_vis];
                delta_tau_ij_k_ant = q/length[from][to];
                tau_t_ij_new[from][to]=tau_t_ij_new[from][to]+delta_tau_ij_k_ant;
            }/*or (a=0; a<13; a++) {*/
            denominator_new=0;
            for (a=0; a<town; a++) {/*for (t=0; t<town; t++) {*/
                for (b=0; b<town; b++) {
                        nominator_new[a][b]=pow(tau_t_ij_new[a][b],alpha)*visibility_ij_pow_beta[a][b];
                        denominator_new=denominator_new+nominator_new[a][b];
                }

            }
            for (a=0; a<town; a++) {/*for (t=0; t<town; t++) {*/
                for (b=0; b<town; b++) {
                    if(divisor_on==1){transition_probability_new[a][b]=nominator_new[a][b]/denominator_new;}
                    else{transition_probability_new[a][b]=nominator_new[a][b];}

                }

            }
            for (num_of_towns_ant_has_vis=2; num_of_towns_ant_has_vis<town; num_of_towns_ant_has_vis++){/*for (num_of_towns_ant_has_vis=2;*/
                for (a=0; a<ant; a++){/*for (a=0; a<ant; a++){*/
                    for (c=0; c<town; c++){not_visited_list[a][c]=c;}
                    for (b=0; b<num_of_towns_ant_has_vis; b++){/*for (b=0; b<town; b++){*/
                        for (t=0; t<town-b; t++){/*or (t=0; t<town; t++){*/
                            if(not_visited_list[a][t]==tabu_ant[it][a][b]){/*if(t==tabu_ant[it][a][b]){*/
                                not_visited_list[a][t]=100;
                                for (e=t; e<town-1; e++){not_visited_list[a][e]=not_visited_list[a][e+1];}
                            }/*if(t==tabu_ant[it][a][b]){*/
                        }/*or (t=0; t<town; t++){*/
                    }/*for (b=0; b<town; b++){*/
                }/*for (a=0; a<ant; a++){*/
                for (a=0; a<ant; a++){/*for (a=0; a<ant; a++){*/
                    transition_probability_max=0;go_to=100;
                    for (t=0; t<town-num_of_towns_ant_has_vis; t++){/*for (t=0; t<town-b-1; t++){*/
                        if(transition_probability_max<transition_probability_new[tabu_ant[it][a][num_of_towns_ant_has_vis-1]][  not_visited_list[a][t]  ]){
                            transition_probability_max=transition_probability_new[tabu_ant[it][a][num_of_towns_ant_has_vis-1]][  not_visited_list[a][t]  ];
                            //write_to_cons_sh(transition_probability[tabu_ant[it][a][num_of_towns_ant_has_vis-1]][  not_visited_list[a][t]  ]);
                            go_to = not_visited_list[a][t] ;
                        }
                        
                    }/*for (t=0; t<town-b-1; t++){*/
                    if(go_to==100){
                        //happens in pairs when antx goes to y and anty goes to x
                        transition_probability_max=0;go_to=100;
                        rl=rand()%(town-num_of_towns_ant_has_vis);
                        
                        go_to=not_visited_list[a][rl];
                        
                    }
                    tabu_ant[it][a][num_of_towns_ant_has_vis]=go_to;
                    
                }/*for (a=0; a<ant; a++){*/

                
                
                
                for (a=0; a<town; a++) {
                    for (b=0; b<town; b++){
                        tau_t_ij_old[a][b]=tau_t_ij_new[a][b];
                        tau_t_ij_new[a][b]=evap*tau_t_ij_old[a][b];
                    }
                }
                for (a=0; a<ant; a++) {/*or (a=0; a<13; a++) {*/
                    from=tabu_ant[it][a][num_of_towns_ant_has_vis-1];
                    to=  tabu_ant[it][a][num_of_towns_ant_has_vis];
                    delta_tau_ij_k_ant = q/length[from][to];
                    tau_t_ij_new[from][to]=tau_t_ij_new[from][to]+delta_tau_ij_k_ant;
                }/*or (a=0; a<13; a++) {*/
                denominator_new=0;
                for (a=0; a<town; a++) {/*for (t=0; t<town; t++) {*/
                    for (b=0; b<town; b++) {
                        nominator_new[a][b]=pow(tau_t_ij_new[a][b],alpha)*visibility_ij_pow_beta[a][b];
                        denominator_new=denominator_new+nominator_new[a][b];
                    }
                    
                }
                for (a=0; a<town; a++) {/*for (t=0; t<town; t++) {*/
                    for (b=0; b<town; b++) {
                        if(divisor_on==1){transition_probability_new[a][b]=nominator_new[a][b]/denominator_new;}
                        else{transition_probability_new[a][b]=nominator_new[a][b];}
                    }

                }
            }/*for (num_of_towns_ant_has_vis=2; num_of_towns_ant_has_vis<5; num_of_towns_ant_has_vis++){*/
            if(output==1){printf("ants reset %2d times: \n",it);}
            tour_lenth_min[it]=1000000;
            for (a=0; a<ant; a++) {/*or (a=0; a<13; a++) {*/

                tour_lenth[a]=0;
                for (b=0; b<town-1; b++) {
                    tour_lenth[a]=tour_lenth[a]+length[tabu_ant[it][a][b]][tabu_ant[it][a][b+1]];
                }
                tour_lenth[a]=tour_lenth[a]+length[tabu_ant[it][a][b]][tabu_ant[it][a][0]];

                if(tour_lenth[a]<tour_lenth_min[it]){
                    tour_lenth_min[it]=tour_lenth[a]; best_ant=a;
                }
            }/*or (a=0; a<13; a++) {*/
            if(output==1){printf("best ant%2d: ",best_ant);}
                for (b=0; b<town; b++) {
                    tabu_best[b]=tabu_ant[it][best_ant][b];
                    if(output==1){printf("%2d ",tabu_best[b]);}
                }
            if(output==1){printf("length it: %8.1f \n",tour_lenth_min[it]);}
            if(tour_lenth_min[it]<=lenth_min_const_alpha_beta[alpha_run][beta_run]){lenth_min_const_alpha_beta[alpha_run][beta_run]=tour_lenth_min[it];}
            sum_of_tour_lenth_min=sum_of_tour_lenth_min+tour_lenth_min[it];
            best_it=0;
            for (it=1; it<num_of_new_ants_starts; it++){/*for (it=0; it<num_of_new_ants_starts; it++)*/
                min_length_at_END=0;
                num_of_towns_ant_has_vis=0;
                for (a=0; a<ant; a++) {/*for (a=0; a<ant; a++) {*/
                    for (j=0; j<town; j++) {tabu_ant[it][a][j]=a;}//tabulist filled with initial town
                }/*for (i=0; i<ant; i++) {*/
                
                for (num_of_towns_ant_has_vis=1; num_of_towns_ant_has_vis<13; num_of_towns_ant_has_vis++){/*for (num_of_towns_ant_has_vis=2; */
                    for (a=0; a<ant; a++){/*for (a=0; a<ant; a++){*/
                        for (c=0; c<town; c++){not_visited_list[a][c]=c;}
                        for (b=0; b<num_of_towns_ant_has_vis; b++){/*for (b=0; b<town; b++){*/
                            for (t=0; t<town-b; t++){/*or (t=0; t<town; t++){*/
                                if(not_visited_list[a][t]==tabu_ant[it][a][b]){/*if(t==tabu_ant[it][a][b]){*/
                                    not_visited_list[a][t]=100;
                                    for (e=t; e<town-1; e++){not_visited_list[a][e]=not_visited_list[a][e+1];}
                                }/*if(t==tabu_ant[it][a][b]){*/
                            }/*or (t=0; t<town; t++){*/
                        }/*for (b=0; b<town; b++){*/
                    }/*for (a=0; a<ant; a++){*/
                    
                    
                    for (a=0; a<ant; a++){/*for (a=0; a<ant; a++){*/
                        transition_probability_max=0;go_to=100;
                        for (t=0; t<town-num_of_towns_ant_has_vis; t++){/*for (t=0; t<town-b-1; t++){*/
                            if(transition_probability_max<transition_probability_new[tabu_ant[it][a][num_of_towns_ant_has_vis-1]][  not_visited_list[a][t]  ]){
                                transition_probability_max=transition_probability_new[tabu_ant[it][a][num_of_towns_ant_has_vis-1]][  not_visited_list[a][t]  ];
                                //write_to_cons_sh(transition_probability[tabu_ant[it][a][num_of_towns_ant_has_vis-1]][  not_visited_list[a][t]  ]);
                                go_to = not_visited_list[a][t] ;
                            }
                            
                        }/*for (t=0; t<town-b-1; t++){*/
                        if(go_to==100){
                            //happens in pairs when antx goes to y and anty goes to x
                            printf("second prob");
                            transition_probability_max=0;go_to=100;
                            rl=rand()%(town-num_of_towns_ant_has_vis);
                            
                            go_to=not_visited_list[a][rl];
                            
                        }
                        tabu_ant[it][a][num_of_towns_ant_has_vis]=go_to;
                        
                    }/*for (a=0; a<ant; a++){*/
                    for (a=0; a<town; a++) {
                        for (b=0; b<town; b++){
                            tau_t_ij_old[a][b]=tau_t_ij_new[a][b];
                            tau_t_ij_new[a][b]=evap*tau_t_ij_old[a][b];
                        }
                    }
                    for (a=0; a<ant; a++) {/*or (a=0; a<13; a++) {*/
                        from=tabu_ant[it][a][num_of_towns_ant_has_vis-1];
                        to=  tabu_ant[it][a][num_of_towns_ant_has_vis];
                        delta_tau_ij_k_ant = q/length[from][to];
                        tau_t_ij_new[from][to]=tau_t_ij_new[from][to]+delta_tau_ij_k_ant;
                    }/*or (a=0; a<13; a++) {*/
                    denominator_new=0;
                    for (a=0; a<town; a++) {/*for (t=0; t<town; t++) {*/
                        for (b=0; b<town; b++) {
                            nominator_new[a][b]=pow(tau_t_ij_new[a][b],alpha)*visibility_ij_pow_beta[a][b];
                            denominator_new=denominator_new+nominator_new[a][b];
                        }
                        
                    }
                    for (a=0; a<town; a++) {/*for (t=0; t<town; t++) {*/
                        for (b=0; b<town; b++) {
                            if(divisor_on==1){transition_probability_new[a][b]=nominator_new[a][b]/denominator_new;}
                            else{transition_probability_new[a][b]=nominator_new[a][b];}
                        }
                    }
                }/*for (num_of_towns_ant_has_vis=1; num_of_towns_ant_has_vis<5; num_of_towns_ant_has_vis++){*/
                if(output==1){printf("ants reset %2d times: \n",it);}
                tour_lenth_min[it]=1000000;
                for (a=0; a<ant; a++) {/*or (a=0; a<13; a++) {*/
                    tour_lenth[a]=0;
                    for (b=0; b<town-1; b++) {
                        tour_lenth[a]=tour_lenth[a]+length[tabu_ant[it][a][b]][tabu_ant[it][a][b+1]];
                    }
                    tour_lenth[a]=tour_lenth[a]+length[tabu_ant[it][a][b]][tabu_ant[it][a][0]];
                    if(tour_lenth[a]<tour_lenth_min[it]){
                        tour_lenth_min[it]=tour_lenth[a]; best_ant=a;
                    }
                }/*or (a=0; a<13; a++) {*/
output=0;
                if(output==1){printf("best ant%2d: ",best_ant);}
                
                for (b=0; b<town; b++) {/*for (b=0; b<town; b++) {*/
                    tabu_best[b]=tabu_ant[it][best_ant][b];
                    if(output==1){printf("%2d ",tabu_best[b]);}
                }/*for (b=0; b<town; b++) {*/
                if(output==1){printf("length it %2d: %8.1f \n",it,tour_lenth_min[it]);}
                 output=0;
                tour_lenth[a]=0;
                if(output==1){printf(" length: %8.1f \n",tour_lenth[a]);}
                for (b=0; b<town-1; b++) {
                    tour_lenth[a]=tour_lenth[a]+length[tabu_ant[it][best_ant][b]][tabu_ant[it][best_ant][b+1]];
                    if(output==1){printf(" length: %8.1f \n",tour_lenth[a]);}
                }
                tour_lenth[a]=tour_lenth[a]+length[tabu_ant[it][best_ant][b]][tabu_ant[it][best_ant][0]];
                if(output==1){printf(" length: %8.1f \n",tour_lenth[a]);}
                sum_of_tour_lenth_min=sum_of_tour_lenth_min+tour_lenth_min[it];
                if(tour_lenth_min[it]<=lenth_min_const_alpha_beta[alpha_run][beta_run]){
                    lenth_min_const_alpha_beta[alpha_run][beta_run]=tour_lenth_min[it];
                    best_it=it;
                    best_best_ant=best_ant;

                }
            }/*for (it=0; it<num_of_new_ants_starts; it++)*/
    
output=1;
    if(output==1){/*if(output==1){*/
            printf("g run: %2d it: %2d ant: %2d lenth: %8.1f  ",gamma_run,best_it,best_best_ant,lenth_min_const_alpha_beta[alpha_run][beta_run]);
            for (b=0; b<town; b++) {
                //printf("%2d ",tabu_best[b]);
            printf("%c ",tabu_best[b]+65);
            
            }
            printf("\n");
    }/*if(output==1){*/
output=0;
    if(lenth_min_const_alpha_beta[alpha_run][beta_run]<minlgthofallgams_conalbelgth[alpha_run][beta_run]){
        minlgthofallgams_conalbelgth[alpha_run][beta_run]=lenth_min_const_alpha_beta[alpha_run][beta_run];
        for (b=0; b<town; b++) {tabu_list_of_best_ant_of_const_alpha_beta[alpha_run][beta_run][b]=tabu_best[b];}
        best_gamma_run=gamma_run;
    }
    sum_lenth_min_const_alpha_beta[alpha_run][beta_run]=sum_lenth_min_const_alpha_beta[alpha_run][beta_run]+lenth_min_const_alpha_beta[alpha_run][beta_run];
            //loop ant restart
            
            //write to disc for every alpha beta
//            printf("alpha: %6.2f",alpha);printf("beta: %6.2f",beta);printf("beta: %6.2f \n",lenth_min_const_alpha_beta[alpha_run][beta_run]);
//            fds = open ("res02.txt",O_APPEND |O_CREAT | O_WRONLY,0644);
//            if(fds > 0){/*if(fd > 0){if(fd > 0){if(fd > 0){*/
//                res=alpha*1000;write_to_disc(res,fds);res=beta*1000;write_to_disc(res,fds);write_to_disc(lenth_min_const_alpha_beta[alpha_run][beta_run],fds);
//                for (b=0; b<town; b++) {write_to_disc_sh(tabu_best[b],fds);}
//                write(fds,"\n",2);
//            }/*if(fd > 0){if(fd > 0){if(fd > 0){*/
//            close(fds);
            //write to disc for every alpha beta
    
}/*for (gamma_run=0; gamma_run<numb_of_new_exp; gamma_run++) {*/

//printf("minlgthofallgams_conalbelgth: %8.1f  ",minlgthofallgams_conalbelgth[alpha_run][beta_run]);
//            printf("sum of all min length: %12.1f  ",sum_of_tour_lenth_min);
            
        
            printf("min length: %8.1f at g cycle %d  ",minlgthofallgams_conalbelgth[alpha_run][beta_run],best_gamma_run);
            printf("list: ");
//for (b=0; b<town; b++) {printf("%2d ",tabu_list_of_best_ant_of_const_alpha_beta[alpha_run][beta_run][b]);}
//            printf("or ");

            
//            letter=tabu_list_of_best_ant_of_const_alpha_beta[alpha_run][beta_run][b]+65;
            for (b=0; b<town; b++) {printf("%c ",tabu_list_of_best_ant_of_const_alpha_beta[alpha_run][beta_run][b]+65);}
                    //printf("%c ",tabu_list_of_best_ant_of_const_alpha_beta[alpha_run][beta_run][0]+65);
            
                        printf("\n");
            printf("sum: %10.1f \n",sum_lenth_min_const_alpha_beta[alpha_run][beta_run]);
    
        }/*a run*/
    }/*b run*/
    
    return 0;
}
