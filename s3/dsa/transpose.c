#include <stdio.h>

int main(){
    int r1,c1;
    printf("Input no of row and column\n");
    scanf("%d",&r1);
    scanf("%d",&c1);
    printf("Input matrix elements\n");
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

    int st[s1[0][2]+1][3];
    st[0][0] = s1[0][1];
    st[0][1] = s1[0][0];
    st[0][2] = s1[0][2];

    int i =1,j =0, k =s1[0][2];
    while(i<=k){
        for(int m = 1;m<=k;m++){
            if(s1[m][1] == j){
                st[i][0] = s1[m][1];
                st[i][1] = s1[m][0];
                st[i][2] = s1[m][2];
                i++;
            }
        }
        j++;
    }

    printf("Result :\n");
    for(int i =0;i<=k;i++){
        for(int j =0;j<3;j++){
            printf("%d ",st[i][j]);
        }
        printf("\n");
    }
    return 0;
}