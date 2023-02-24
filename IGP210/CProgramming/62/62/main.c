//
//  main.c
//  62
//
//  Created by Chang on 2023-02-13.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int number = 0;
    int i, k;
    
    //    char teamTypeOne[50][50] = {"Jeff", "David", "Kevin", "Sean", "Bill"};
    
    struct Player {
//        char name[100];
//        char role[100];
        
        char name[50];
        char role[50];
        
        int age;
        int experience;
    };
    struct Player team[number];
    
    
    
    // input part
    
    printf("how many soccer is in your team?\n");
    scanf("%d", &number);
    
    if (number >= 1 && number <= 22){
//        number -= 1;
        for(i=0; i<number; i++){
            
            printf("please input your player %d 's name?\n", i+1);
            scanf("%s", &team[i].name);
            
            printf("please input your player %d 's role?\n", i+1);
            scanf("%s", &team[i].role);
            
            printf("what is your player %d 's age?\n", i+1);
            scanf("%d", &team[i].age);
            
            
            //  age check
            
            if(team[i].age == false){
                
                for(k=1; k<2; k++){
                    
                    printf("wrong enter, please repeat?\n");
                    scanf("%d", &team[i].age);
                    
                    if (k == 2 ){
                        printf(" wrong times is more than two times wrongly, you are defined as a robot and spam and will not be allowed to enter.\n");
                        
                        break;
                    }
                }
            }
            
            printf("please input your player %d 's experience?\n", i+1);
            scanf("%d", &team[i].experience);
            
        }
        
        printf("\n\n\n");
        
        // array check
        
        
        //      sort by age and print
        
        for (int i = 0; i < number - 1; i++) {
            for (int j = 0; j < number - i - 1; j++) {
                if (team[j].age > team[j + 1].age) {
                    struct Player temp = team[j];
                    team[j] = team[j + 1];
                    team[j + 1] = temp;
                }
            }
        }
        
        
        for(i=0; i<number; i++){
            printf("player %d 's name is %s, his role is %s, his age is %d, his experience is %d.\n", i+1, team[i].name, team[i].role, team[i].age, team[i].experience);
        }
        
        //     sort by experience and print
        
        for (int i = 0; i < number - 1; i++) {
            for (int j = 0; j < number - i - 1; j++) {
                if (team[j].experience > team[j + 1].experience) {
                    struct Player temp = team[j];
                    team[j] = team[j + 1];
                    team[j + 1] = temp;
                }
            }
        }
        
        for(i=0; i<number; i++){
            printf("player %d 's name is %s, his role is %s, his age is %d, his experience is %d..\n", i+1, team[i].name, team[i].role, team[i].age, team[i].experience);
        }
        
        //     sort by name and print
        
        for (int i = 0; i < number - 1; i++) {
            for (int j = 0; j < number - i - 1; j++) {
                if (strcmp(team[j].name, team[j + 1].name) > 0) {
                    struct Player temp = team[j];
                    team[j] = team[j + 1];
                    team[j + 1] = temp;
                }
            }
        }
        
        for(i=0; i<number; i++){
            printf("player %d 's name is %s, his role is %s, his age is %d, his experience is %d.\n", i+1, team[i].name, team[i].role, team[i].age, team[i].experience);
        }
        
        return 0;
    }
    
}
