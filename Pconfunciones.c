/* Alexis Aguirre Rojas
Proyecto Final Laboratorio
20 de novimebre de 2024*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define p printf
#define s scanf

    void ini_matriz(int arr[100][8]){
    int i, j;
        for (i = 0; i < 100; i++){
            for (j = 0; j < 8; j++){
                arr[i][j] = 0;
            }
        }
        p("\n\n\tMatriz inicializada");
    }
    void full_matriz(int arr[100][8]){
        int i, var1, var2;
        for(i = 0; i < 100; i++){
            p("\n\n\tDame la bebida del pueblo %d: ", i);
            s("%d", &var1);
            while (var1 != -1){
                p("\n\n\tCuantos litros necesitas: ");
                s("%d", &var2);
                arr[i][var1] = var2;
                p("\n\n\tDame otra bebida: ");
                s("%d", &var1);
            }
        }
    }
    void b_consumida(int arr[100][8], int total[8]){
        int i, j, max = 0, bebida;
        for(j = 0; j < 8; j++){ //total de cada bebida
            total[j] = 0;
            for(i = 0; i < 100; i++){
                total [j] += arr [i][j]; 
            }
        }
        for(i = 0; i < 8; i++){ //bebida mas consumida
            if (max < total[i]){
                max = total [i];
                bebida = i;
            }
        }
        p("\n\n\tLa bebida que mas se consume es %d con %d litros", bebida, max);
    }
    void v_sin_alcohol (int arr[100][8], int total2[8]){
        int i, j, acum = 0;
        for (i = 0; i < 8; i++){
            if(i != 1 && i != 6){
                for(j = 0; j < 100; j++){
                    acum += arr[j][i];
                }
                total2[i] = acum;
            }
        }
        int max2 = 0, bebida2;
        for(i = 0; i < 8; i++){ // Excluir refrescos y bebidas energeticas
            if(max2 < total2[i]){
                max2 = total2[i];
                bebida2 = i;
            }
        }
        p("\n\n\tLa bebida que mas se consume es %d con %d litros", bebida2, max2);
    }
    void p_alcoholico (int arr[100][8], int total3[100]){
        int i, j, max3 = 0, acum2 = 0, pueblo;
        for(i = 0; i < 100; i++){
            total3[i] = 0;
            for(j = 0; j < 8; j++){
                if(j != 1 && j != 6){
                    acum2 += arr[i][j];
                }
            }
            total3[i] = acum2;
        }
        for(i = 0; i < 100; i++){
            if(max3 < total3[i]){
                max3 = total3[i];
                pueblo = i;
            }
        }
        p("\n\n\tEl pueblo %d consume mas alcohol con %d litros", pueblo, max3);
    }

    int main()
    {
        int arr[100][8],;
        int total[8] = {0,0,0,0,0,0,0,0}; 
        int total2[8] = {0,0,0,0,0,0,0,0} ;
        int total3 [100];
        
        ini_matriz(arr);
        full_matriz(arr);
        b_consumida(arr, total);
        v_sin_alcohol(arr, total2);
        p_alcoholico(arr,total3);
        
        return 0;
    }
