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
int main (){
    int a,b,placemin,placeminStart,col,z,mintour,d;
    char memb[13];
    char set[14];
    char minset[14];
    int numbermemb[13];
    char letter[1];
    long length[14][14];//AB,AC,AD,AE...
    long lengthWork[14][14];
    long min=1000000;
    long totallength,mintotallength;
    memb[0]='A';
    memb[1]='B';
    memb[2]='C';
    memb[3]='D';
    memb[4]='E';
    memb[5]='F';
    memb[6]='G';
    memb[7]='H';
    memb[8]='I';
    memb[9]='J';
    memb[10]='K';
    memb[11]='L';
    memb[12]='M';
    numbermemb[0]=0;
    numbermemb[1]=1;
    numbermemb[2]=2;
    numbermemb[3]=3;
    numbermemb[4]=4;
    numbermemb[5]=5;
    numbermemb[6]=6;
    numbermemb[7]=7;
    numbermemb[8]=8;
    numbermemb[9]=9;
    numbermemb[10]=10;
    numbermemb[11]=11;
    numbermemb[12]=12;
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
    mintotallength=1000000;
    for (z=0; z<13;z++){/*Start at all towns for (z=0; z<13;z++){*/
        for (a=0; a<13;a++){
            for (b=0; b<13;b++){lengthWork[a][b]=length[a][b];}
        }
        placemin=z;
        placeminStart=placemin;
        letter[0] = memb[placemin];
        set[0]=memb[placemin];
        totallength=0;
        for (b=0; b<12;b++){/*for (b=0; b<12;b++){*/
            col=placemin;
            min=1000000;
            lengthWork[col][col]=10000;
            for (a=0; a<13;a++){
                if (lengthWork[col][a]<min){
                    min=lengthWork[col][a];placemin=a;
                }
            }
            for (a=0; a<13;a++){lengthWork[a][col]=1000000;}
            letter[0] = memb[placemin];
            set[b+1]= memb[placemin];
            totallength=totallength+min;
        }/*for (b=0; b<12;b++){*/
        letter[0] = memb[placeminStart];
        set[b+1]= memb[placeminStart];
        totallength=totallength+length[placemin][placeminStart];
        printf("length: %ld ",totallength);
        for(d=0;d<14;d++){printf("%c ",set[d]);}
        printf("\n");
        if(totallength<mintotallength){
            mintotallength=totallength;mintour=z;
            for(d=0;d<14;d++){minset[d]=set[d];}
        }
    }/*for (z=0; z<13;z++){*/
    printf("min length: %ld ",mintotallength);
    for(d=0;d<14;d++){printf("%c ",minset[d]);}
    printf("\n");
    return 0;
}


