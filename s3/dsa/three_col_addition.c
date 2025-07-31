#include <stdio.h>

int main(){
    printf("Matrix 1\n");
    int r1,c1;
    printf("Input no of row and column\n");
    scanf("%d",&r1);
    scanf("%d",&c1);
    printf("Input matrix 1 elements\n");
    int arr1[100][100];
    for(int i =0;i<r1;i++){
        for(int j =0;j<c1;j++){
            scanf("%d",&arr1[i][j]);
        }
    }

    int count1 =0;
    for(int i =0;i<r1;i++){
        for(int j =0;j<c1;j++){
            if(arr1[i][j]!=0){
                count1++;
            }
        }
    }

    int s1[count1+1][3];
    s1[0][0] = r1;
    s1[0][1] = c1;
    s1[0][2] = count1;

    int k1 = 1;
    for(int i =0;i<r1;i++){
        for(int j =0;j<c1;j++){
            if(arr1[i][j]!=0){
                s1[k1][0] = i;
                s1[k1][1] = j;
                s1[k1][2] = arr1[i][j];
                k1++;
            }
        }
    }


   



    printf("Matrix 2\n");
    int r2,c2;
    printf("Input no of row and column\n");
    scanf("%d",&r2);
    scanf("%d",&c2);
    printf("Input matrix 2 elements\n");
    int arr2[100][100];
    for(int i =0;i<r2;i++){
        for(int j =0;j<c2;j++){
            scanf("%d",&arr2[i][j]);
        }
    }

    int count2 =0;
    for(int i =0;i<r2;i++){
        for(int j =0;j<c2;j++){
            if(arr2[i][j]!=0){
                count2++;
            }
        }
    }

    int s2[count2+1][3];
    s2[0][0] = r2;
    s2[0][1] = c2;
    s2[0][2] = count2;

    int k2 = 1;
    for(int i =0;i<r2;i++){
        for(int j =0;j<c2;j++){
            if(arr2[i][j]!=0){
                s2[k2][0] = i;
                s2[k2][1] = j;
                s2[k2][2] = arr2[i][j];
                k2++;
            }
        }
    }


    if((r1!=r2) || (c1!=c2)){
        printf("Addition not possible!\n");
        return 0;
    }

    int s3_row = s1[0][2]+s2[0][2];
    int s3[s3_row][3];
    s3[0][0] = r1;
    s3[0][1] = c1;
    
    int i =1,j=1,k=1;
    
    while(i<=s1[0][2] && j<=s2[0][2]){
        if((s1[i][0]<s2[j][0]) || (s1[i][0]==s2[j][0] && s1[i][1]<s2[j][1])){
            s3[k][0] = s1[i][0]; 
            s3[k][1] = s1[i][1]; 
            s3[k][2] = s1[i][2]; 
            i++;
        }
        else if((s2[j][0]<s1[i][0]) || (s1[i][0]==s2[j][0] && s2[j][1]<s1[i][1])){
            s3[k][0] = s2[j][0]; 
            s3[k][1] = s2[j][1]; 
            s3[k][2] = s2[j][2]; 
            j++;
        }
        else{
            int sum = s1[i][2] + s2[j][2];
            if(sum!=0){
                s3[k][0] = s1[i][0]; 
                s3[k][1] = s2[j][1]; 
                s3[k][2] = sum; 
            }
            else{
                k--;
            }
            i++;
            j++;
        }
        k++;
    }

    while(i <= s1[0][2]){
        s3[k][0] = s1[i][0];
        s3[k][1] = s1[i][1];
        s3[k][2] = s1[i][2];
        i++;
        k++;
    }

    while(j <= s2[0][2]){
        s3[k][0] = s2[j][0];
        s3[k][1] = s2[j][1];
        s3[k][2] = s2[j][2];
        j++;
        k++;
    }

    s3[0][2] = k-1;
    printf("Result :\n");
    for(int i =0;i<k;i++){
        for(int j =0;j<3;j++){
            printf("%d ",s3[i][j]);
        }
        printf("\n");
    }

    

    
    return 0;
}