#include <stdio.h>

// water fire earth wind physical
float multiplier[5][5] = {{1., 2, 0.5, 1.1,1}, {0.5, 1., 1.1, 2,1}, {2, 0.5, 1, 1.1,1}, {2, 0.5, 1.1, 1,1},{1,1,1,1,1}};

typedef struct{
    char attack_name[20];
    float inflict;
    int ep_cost;
    int type;
} damage;

typedef struct
{
    float hp;
    int pok_type;
    int ep;
    damage atk[4];
} pokemon;

float inflict_damage(pokemon a, pokemon b, int attack_number)
{
    // pokemon a attacks b

    float rdamage = a.atk[attack_number].inflict *multiplier[a.atk[attack_number].type ][b.pok_type ];

    if (b.hp > 0 && a.hp > 0){
    if (a.ep >= a.atk[attack_number].ep_cost){
          printf("received damage is %f\n", rdamage);
          b.hp -= rdamage;
          a.ep -= a.atk[attack_number].ep_cost;
    }else{
        printf("not enough energy points");
    }
    }
    else
    {
        printf("he dead");
    }
}

int main(void)
{
    pokemon pika = {.atk={{.attack_name= "physical",.ep_cost=10 ,.inflict =200 ,.type =4},
                    {.attack_name= "nrm1",.ep_cost=10 ,.inflict =150 ,.type =1},
                    {.attack_name= "nrm2",.ep_cost=15 ,.inflict =200 ,.type =1},
                    {.attack_name= "nrm3",.ep_cost=15 ,.inflict =200 ,.type =1},
                    {.attack_name= "nrm4",.ep_cost=15 ,.inflict =200 ,.type =1}},
                .ep = 100,.hp =2000 , .pok_type =1 };
pokemon piko = {.atk={{.attack_name= "physical",.ep_cost=10 ,.inflict =200 ,.type =4},
                    {.attack_name= "nrm1",.ep_cost=10 ,.inflict =150 ,.type =2},
                    {.attack_name= "nrm2",.ep_cost=15 ,.inflict =200 ,.type =2},
                    {.attack_name= "nrm3",.ep_cost=15 ,.inflict =200 ,.type =2},
                    {.attack_name= "nrm4",.ep_cost=15 ,.inflict =200 ,.type =2}},
                .ep = 100,.hp =2000 , .pok_type =1 };

    inflict_damage(pika, piko, 2);
    printf(" piko has %.2f pika has %d energy left", piko.hp, pika.ep);

    return 0;
}