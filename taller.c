#include<stdio.h>
#include<stdlib.h>
//prototipos
void captura_datos();
void quien_gano(int desicion, int *canelowin, int *floydwin, int *canelolose, int *floydlose);
void quien_toco_lona();
void juicio(int contador,int juez1C, int juez1F, int juez2C, int juez2F, int juez3C, int juez3F, int *caso, int *ganador);
void recompensa(int tipo, int ganador, int canelowin, int floydwin);

//func and proc
void recompensa(int tipo, int ganador, int canelowin, int floydwin){
    float bolsa=100000,aux=0;
    switch(tipo){
        case 0:
            if(ganador==0){
                aux=bolsa;
                bolsa=bolsa*0.05;
                bolsa=bolsa*canelowin;
                bolsa=bolsa+aux;
                printf("el ganador es canelo alvarez por UD\n");
                printf("monto ganado %.1f $$$$",bolsa);
                printf("mayweather jr gana 60000 por su participacion\n");
            }
            else{
                aux=bolsa;
                bolsa=bolsa*0.5;
                bolsa=bolsa*floydwin;
                bolsa=bolsa+aux;
                printf("el ganador es mayweather jr por UD\n");
                printf("monto ganado %.1f $$$$",bolsa);
                printf("canelo alvarez gana 60000 por su participacion");
            }
        case 1:
            if(ganador==0){
                aux=bolsa;
                bolsa=bolsa*0.1;
                bolsa=bolsa*canelowin;
                bolsa=bolsa+aux;
                printf("el ganador es canelo alvarez por SD\n");
                printf("monto ganado %.1f $$$$",bolsa);
                printf("mayweather jr gana 60000 por su participacion\n");
            }
            else{
                aux=bolsa;
                bolsa=bolsa*0.1;
                bolsa=bolsa*floydwin;
                bolsa=bolsa+aux;
                printf("el ganador es mayweather jr por SD\n");
                printf("monto ganado %.1f $$$$",bolsa);
                printf("canelo alvarez gana 60000 por su participacion");
            }
            break;
        case 2:
            if(ganador==0){ 
                aux=bolsa;
                bolsa=bolsa*0.15;
                bolsa=bolsa*canelowin;
                bolsa=bolsa+aux;
                printf("el ganador es canelo alvarez por MD\n");
                printf("monto ganado %.1f $$$$",bolsa);
                printf("mayweather jr gana 60000 por su participacion\n");
            }
            else{
                aux=bolsa;
                bolsa=bolsa*0.15;
                bolsa=bolsa*floydwin;
                bolsa=bolsa+aux;
                printf("el ganador es mayweather jr por MD\n");
                printf("monto ganado %.1f $$$$",bolsa);
                printf("canelo alvarez gana 60000 por su participacion");

            }


            break;


    }



}
void juicio(int contador,int juez1C, int juez1F, int juez2C, int juez2F, int juez3C, int juez3F, int *caso, int *ganador){
    switch(contador){
        case 0:
            if((juez1C>juez1F)&&(juez2C>juez2F)&&(juez3C>juez3F)){ 
                *caso=0;
                *ganador=0;
            }
            else{
                if((juez1C<juez1F)&&(juez2C<juez2F)&&(juez3C<juez3F)){   
                    *caso=0;
                    *ganador=1;
                }
                else{
                    *caso=100;
                    *ganador=100;
                }
               
            }
            break;
        case 1:
            if((juez1C>juez1F)&&(juez2C>juez2F)&&(juez3C<juez3F)){
                if((juez3F==juez1F)||(juez3F==juez2F)){        
                    *caso=2;
                    *ganador=0;
                }
                else{
                   *caso=1;
                    *ganador=0;
                }
            }
            else{
                if((juez1C<juez1F)&&(juez2C<juez2F)&&(juez3C>juez3F)){
                    if((juez3C==juez1C)||(juez3C==juez2C)){              
                        *caso=2;
                        *ganador=1;
                    }
                    else{                   
                        *caso=1;
                        *ganador=1;
                    }
                }
                else{
                    *caso=100;
                    *ganador=100;
                }         
            }
            break;
        case 2:
            if((juez2C>juez2F)&&(juez3C>juez3F)&&(juez1C<juez1F)){
                if((juez1F==juez2F)||(juez1F==juez3F)){               
                    *caso=2;
                    *ganador=0;
                }
                else{                        
                    *caso=1;
                    *ganador=0;
                }
            }
            else{
                if((juez2C<juez2F)&&(juez3C<juez3F)&&(juez1C>juez1F)){
                    if((juez1C==juez2C)||(juez1C==juez3C)){                  
                        *caso=2;
                        *ganador=1;
                    }
                    else{                   
                        *caso=1;
                        *ganador=1;
                    }
                }
                else{
                    *caso=100;
                    *ganador=100;
                }                                      
            }
            break;
        case 3:
            if((juez1C>juez1F)&&(juez3C>juez3F)&&(juez2C<juez2F)){
                if((juez2F==juez1F)||(juez2F==juez3F)){                  
                    *caso=2;
                    *ganador=0;
                }
                else{                   
                    *caso=1;
                    *ganador=0;
                }
            }
            else{
                if((juez1C<juez1F)&&(juez3C<juez3F)&&(juez2C>juez2F)){
                    if((juez2C==juez1C)||(juez2C==juez3C)){               
                        *caso=2;
                        *ganador=1;
                    }
                    else{                    
                        *caso=1;
                        *ganador=1;
                    }
                }
                else{
                    *caso=100;
                    *ganador=100;
                }
            }
            break;
            default:
                break;
    }
}
void quien_gano(int desicion, int *canelowin, int *floydwin, int *canelolose, int *floydlose ){
   switch(desicion){
        case 1:
            *canelowin+=1;
            *floydlose+=1;
            break;
        case 2:
            *canelolose+=1;
            *floydwin+=1;
            break;
        default:
            break;
    }
    
}
void quien_toco_lona(int *canelolona, int *floydlona){
    int ganador;
    printf("algun luchador toco lona si=1 no=2\n?");
    scanf("%d",&ganador);
    if(ganador==1){
        printf("quien toco lona canelo=1 floyd=2\n");
        scanf("%d",&ganador);
        switch(ganador){
            case 1:
                *canelolona+=1;
                break;
            case 2:
                *floydlona+=1;
                break;
        }
    }
}





//pro capturador
void captura_datos(int *a1, int *a2, int *b1, int *b2, int *c1, int *c2, int *canelowin, int *floydwin){
    int LIMIT=3;
    int ganador,i;
    int canelo_winW=0,floyd_loseW=0,canelo_loseW=0,floyd_winW=0;
    int canelo_winB=0,floyd_loseB=0,canelo_loseB=0,floyd_winB=0;
    int canelo_winP=0,floyd_loseP=0,canelo_loseP=0,floyd_winP=0;
    int canelo_lonaW=0,floyd_lonaW=0;
    int canelo_lonaB=0,floyd_lonaB=0;
    int canelo_lonaP=0,floyd_lonaP=0;
    int canelo_white[LIMIT],floyd_white[LIMIT];
    int canelo_whiteSCT[LIMIT],floyd_whiteSCT[LIMIT];
    int canelo_blue[LIMIT],floyd_blue[LIMIT];
    int canelo_blueSCT[LIMIT],floyd_blueSCT[LIMIT];
    int canelo_pink[LIMIT],floyd_pink[LIMIT];
    int canelo_pinkSCT[LIMIT],floyd_pinkSCT[LIMIT];
    
    for(i=0;i<LIMIT;i++){
            
        printf("juez weisfield quien gano el round %d.. canelo=1 floyd=2\n",i+1);
        scanf("%d",&ganador);
        quien_gano(ganador,&canelo_winW,&floyd_winW,&canelo_loseW,&floyd_loseW);
        //quien_toco_lona(&canelo_lonaW,&floyd_lonaW);
        switch(ganador){
            case 1:
                canelo_white[i]=10;
                floyd_white[i]=9;
                break;
            case 2:
                canelo_white[i]=9;
                floyd_white[i]=10;
                break;
            default:
                break;
        } 
    }

   for(i=0;i<LIMIT;i++){

        printf("juez lederman quien gano el round %d.. canelo=1 floyd=2 \n",i+1);
        scanf("%d",&ganador);
        quien_gano(ganador,&canelo_winB,&floyd_winB,&canelo_loseB,&floyd_loseB);
        //quien_toco_lona(&canelo_lonaB,&floyd_lonaB);
        switch(ganador){
            case 1:
                canelo_blue[i]=10;
                floyd_blue[i]=9;
                break;
            case 2:
                canelo_blue[i]=9;
                floyd_blue[i]=10;
                break;
            default:
                break;
        }
    }

    for(i=0;i<LIMIT;i++){

        printf("juez cheatman quien gano el round %d..  canelo=1 floyd=2\n",i+1);
        scanf("%d",&ganador);
        quien_gano(ganador,&canelo_winP,&floyd_winP,&canelo_loseP,&floyd_loseP);
        //quien_toco_lona(&canelo_lonaP,&floyd_lonaP);
        switch(ganador){
            case 1:
                canelo_pink[i]=10;
                floyd_pink[i]=9;
                break;
            case 2:
                canelo_pink[i]=9;
                floyd_pink[i]=10;
                break;
            default:
                break;

        }
    
    }

    canelo_lonaW=canelo_lonaW*2;
    floyd_lonaW=floyd_lonaW*2;
    
    canelo_lonaB=canelo_lonaB*2;
    floyd_lonaB=floyd_lonaB*2;
    
    canelo_lonaP=canelo_lonaP*2;
    floyd_lonaP=floyd_lonaP*2;

    canelo_whiteSCT[0]=canelo_white[0];
    canelo_blueSCT[0]=canelo_blue[0];
    canelo_pinkSCT[0]=canelo_pink[0];
    floyd_whiteSCT[0]=floyd_white[0];
    floyd_blueSCT[0]=floyd_blue[0];
    floyd_pinkSCT[0]=floyd_pink[0];
 
    for(i=0;i<LIMIT;i++){
        
        canelo_whiteSCT[i+1]=canelo_whiteSCT[i]+canelo_white[i+1];
        canelo_blueSCT[i+1]=canelo_blueSCT[i]+canelo_blue[i+1];
        canelo_pinkSCT[i+1]=canelo_pinkSCT[i]+canelo_pink[i+1];

        floyd_whiteSCT[i+1]=floyd_whiteSCT[i]+floyd_white[i+1];
        floyd_blueSCT[i+1]=floyd_blueSCT[i]+floyd_blue[i+1];
        floyd_pinkSCT[i+1]=floyd_pinkSCT[i]+floyd_pink[i+1];
        
    }
    canelo_whiteSCT[0]=canelo_white[0];
    canelo_blueSCT[0]=canelo_blue[0];
    canelo_pinkSCT[0]=canelo_pink[0];
    floyd_whiteSCT[0]=floyd_white[0];
    floyd_blueSCT[0]=floyd_blue[0];
    floyd_pinkSCT[0]=floyd_pink[0];



    printf("\t\t\t\t\t\t\t\t******************impresion de resultados******************\n");
    printf("\t\t\t\t\t\t\t\t\t\tNEVADA STATE ATHLETIC COMMISION\t\t\t\n");
    printf("\t\t\t\t\t\t\t\t\t\t\tOFFICIAL SCORE CARD\t\t\t\n");
    printf("title:WBC/WBO/IBF/WBA World Titles \tReferee: Russell Mora\n");
    printf("Date: 10/17/2020\t\t\tCity: Las Vegas\tVeneue:  MGM Conference Center \t\t\t\tPromoter(s): Top Rank,Inc\n");
    printf("\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\tWHITE\n");
    printf("Saul Canelo Avarez \tvs\t floyd maywheather jr\n");
    printf("BLUE corner\t\t12 Rounds\t   corner RED\n");
    printf("round\tpoint\tscore\tround\tscore\tpoint\tround\n");
    printf("score\tdeduc\ttotal\t     \ttotal\tdeduc\tscore\n");
    for(i=0;i<LIMIT;i++){

        printf("%d\t\t%d\t%d\t%d\t\t%d\n",canelo_white[i],canelo_whiteSCT[i],i+1,floyd_whiteSCT[i],floyd_white[i]);
       
    }
    
    printf("FINAL SCORE \t%d\t\t%d\t FINAL SCORE\n",canelo_whiteSCT[LIMIT-1],floyd_whiteSCT[LIMIT-1]);
    printf("canelo rounds win= %d lose= %d\n",canelo_winW,canelo_loseW);
    printf("floyd rounds win= %d lose= %d\n",floyd_winW,floyd_loseW);
    printf("Judge:\t\tSteve Weisflied");
    
    printf("\n");
    printf("\n");

    printf("\t\t\tBLUE\n");
    printf("Saul Canelo Avarez \tvs\t floyd maywheather jr\n");
    printf("BLUE corner\t\t12 Rounds\t   corner RED\n");
    printf("round\tpoint\tscore\tround\tscore\tpoint\tround\n");
    printf("score\tdeduc\ttotal\t     \ttotal\tdeduc\tscore\n");

    for(i=0;i<LIMIT;i++){
        
        printf("%d\t\t%d\t%d\t%d\t\t%d\n",canelo_blue[i],canelo_blueSCT[i],i+1,floyd_blueSCT[i],floyd_blue[i]);
    }
    printf("FINAL SCORE \t%d\t\t%d\t FINAL SCORE\n",canelo_blueSCT[LIMIT-1],floyd_blueSCT[LIMIT-1]);
    printf("canelo rounds win= %d lose=%d\n",canelo_winB,canelo_loseB);
    printf("floyd rounds win= %d lose= %d\n",floyd_winB,floyd_loseB);
    printf("Judge:\t\tJulie Lederman");
    
    printf("\n");
    printf("\n");
   
    printf("\t\t\tPINK\n");
    printf("Saul Canelo Avarez \tvs\t floyd maywheather jr\n");
    printf("BLUE corner\t\t12 Rounds\t   corner RED\n");
    printf("round\tpoint\tscore\tround\tscore\tpoint\tround\n");
    printf("score\tdeduc\ttotal\t     \ttotal\tdeduc\tscore\n");
    
    for(i=0;i<LIMIT;i++){
        
        printf("%d\t\t%d\t%d\t%d\t\t%d\n",canelo_pink[i],canelo_pinkSCT[i],i+1,floyd_pinkSCT[i],floyd_pink[i]);
    }
    printf("FINAL SCORE \t%d\t\t%d\t FINAL SCORE\n",canelo_pinkSCT[LIMIT-1],floyd_pinkSCT[LIMIT-1]);
    printf("canelo rounds win= %d lose=%d\n",canelo_winP,canelo_loseP);
    printf("floyd rounds win= %d lose= %d\n",floyd_winP,floyd_loseP);
    printf("Judge:\t\tTim Cheatman");
    
    printf("\n");
    printf("\n");
    *a1=canelo_whiteSCT[LIMIT-1];
    *a2=floyd_whiteSCT[LIMIT-1];
    *b1=canelo_blueSCT[LIMIT-1];
    *b2=floyd_blueSCT[LIMIT-1];
    *c1=canelo_pinkSCT[LIMIT-1];
    *c2=floyd_pinkSCT[LIMIT-1];
    *canelowin=canelo_winW+canelo_winB+canelo_winP;
    *floydwin=floyd_winW+floyd_winB+floyd_winP;
    

}

int main(){
int bandera=1,canelo1,floyd1,canelo2,floyd2,canelo3,floyd3,contador=0,desicion,boxwin;
int canelow,floydw;
captura_datos(&canelo1,&floyd1,&canelo2,&floyd2,&canelo3,&floyd3,&canelow,&floydw);
   
    while(bandera==1){
        juicio(contador,canelo1,floyd1,canelo2,floyd2,canelo3,floyd3,&desicion,&boxwin);
        if(desicion==100&&boxwin==100){
            contador=contador+1;
        }
        else{
            bandera=2;
        }
    }
    recompensa(desicion,boxwin,canelow,floydw);

    return 0;
}