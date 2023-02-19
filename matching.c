#include <stdio.h>

int obtain_index(int arr1[5], int val){
    for (int i = 0; i < 5; i++){
        if (arr1[i] == val){
            return i;
        }
    }
    return -1;
}

int main(){    
    char file_name[50];
    FILE *file;

    printf("Enter input file name: ");
    scanf("%s", file_name);

    file = fopen(file_name, "r");

    char ab;
    int i = 0, j = 0;

    int progs[5][5];
    int depts[5][5];

    while(ab != EOF){
        ab = fgetc(file);
        if ('0' <= ab && ab <= '9'){
            if (j < 5){
                depts[i++][j] = ab - '0';
            } else {
                progs[i++][j-5] = ab - '0';
            }
            if (i == 5){
                i = 0;
                j++;
            }
        }
    }

    int points[5][5]; 
    int prog_point, dept_point;

    for(int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            prog_point = 5 - obtain_index(progs[j], i+1);
            dept_point = 5 - obtain_index(depts[i], j+1);
            points[i][j] = prog_point + dept_point;
        }
    }

    int matches[5] = {-1,-1,-1,-1,-1}; 
    int max_point = 10, tot_matches = 0;

    while(tot_matches < 5){
        for(int i = 0; i<5; i++){
            for(int j = 0; j<5; j++){
                if (points[i][j] == max_point && matches[i] == -1 && obtain_index(matches, j) == -1){
                    matches[i] = j;
                    tot_matches++;
                }
            }
        }
        max_point--;
    }

    for(int i = 0; i<5; i++){
        printf("Department #%d will get Programmer #%d\n", i+1, matches[i]+1);
    }

    return 0;
}