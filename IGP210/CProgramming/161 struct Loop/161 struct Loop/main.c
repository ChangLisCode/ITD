//
//  main.c
//  161
//
//  Created by Chang on 2023-04-06.
//

#include <stdio.h>

struct cars {
    int VIN;
    char make[50];
    char model[50];
    int year;
    char engine[20];
    char color[20];
    char interior_color[20];
    char equipment_group[20];
    int display_size;
    int rim;
    char rim_type[20];
    float mileage;
};

int main() {
    struct cars car[10];
    
    for (int i = 0; i < 10; i++) {
        printf("please input car number - %d information is:\n", i+1);
        printf("please input VIN.\n");
        scanf("%d", &car[i].VIN);
        printf("please input make.\n");
        scanf("%s", car[i].make);
        printf("please input model.\n");
        scanf("%s", car[i].model);
        printf("please input year.\n");
        scanf("%d", &car[i].year);
        printf("please input engine.\n");
        scanf("%s", car[i].engine);
        printf("please input color.\n");
        scanf("%s", car[i].color);
        printf("please input seat_color.\n");
        scanf("%s", car[i].interior_color);
        printf("please input group .\n");
        scanf("%s", car[i].equipment_group);
        printf("please input display size.\n");
        scanf("%d", &car[i].display_size);
        printf("please input rim size.\n");
        scanf("%d", &car[i].rim);
        printf("please input rim type.\n");
        scanf("%s", car[i].rim_type);
        printf("please input mileage.\n");
        scanf("%f", &car[i].mileage);
     }

    for (int i = 0; i < 10; i++) {
        printf("car number - %d information is:\n", i+1);
        printf("  VIN: %d\n", car[i].VIN);
        printf("  Model: %s\n", car[i].model);
        printf("  Make: %s\n", car[i].make);
        printf("  Color: %s\n", car[i].color);
        printf("  Year: %d\n", car[i].year);
        printf("  engine: %s\n", car[i].engine);
        printf("  seat_color: %s\n", car[i].interior_color);
        printf("  group: %s\n", car[i].equipment_group);
        printf("  display size: %d\n", car[i].display_size);
        printf("  rim size: %d\n", car[i].rim);
        printf("  rim type: %s\n", car[i].rim_type);
        printf("  Mileage: %.2f\n", car[i].mileage);
    }
    return 0;
}
