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
    char pok_name[20];
    float hp;
    int pok_type;
    int ep;
    damage atk[5];
} pokemon;

void inflict_damage(pokemon *a, pokemon *b, int attack_number)
{
    // pokemon a attacks b

    float rdamage = a->atk[attack_number].inflict *multiplier[a->atk[attack_number].type ][b->pok_type ];

    if (b->hp > 0 && a->hp > 0){
    if (a->ep >= a->atk[attack_number].ep_cost){
          printf("received damage is %f\n", rdamage);
          b->hp -= rdamage;
          a->ep -= a->atk[attack_number].ep_cost;
    }else{
        printf("not enough energy points");
    }
    }
    else
    {
        printf("he dead");
    }
}
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


void fill_pokemon(){
    printf("how many pokemons do you want (max 50) \n");
    int pok_numb;
    scanf("%d",&pok_numb);
    pokemon pokemon_list[pok_numb];
    for(int i=0; i<=pok_numb; i++){
        int numb_atk,energy_point, energy_cost;
        printf("what would you name your character \n");
        scanf("%c",&pokemon_list[i].pok_name);
        printf("\ngive health points \n");
        scanf("%f",&pokemon_list[i].hp);
        printf("\ngive energy points \n");
        scanf("%d",&pokemon_list[i].ep);
        printf("\ngive pokemon type water:0 fire:1 earth:2 wind:3  \n");
        scanf("%d",&pokemon_list[i].pok_type);
        printf("\nhow many attacks does %c have \n",pokemon_list[i].pok_name);
        scanf("%d",&numb_atk);
        printf("whats the pokemon type \n0 water\n1 fire\n2 earth\n3 wind\n ");
        scanf("%d",pokemon_list[i].pok_type);
        


        printf("how many attacks does he have\n");
        scanf("%d",&numb_atk);
        for(int j=0; i<=pok_numb; j++){
            printf("attack name\n");
            scanf("%c",pokemon_list[i].atk->attack_name);
            printf("attack damage type\n0 water\n1 fire\n2 earth\n3 wind");
            scanf("%d",pokemon_list[i].atk->type);
            printf("attack damage\n");
            scanf("%d",pokemon_list[i].atk->inflict);
            printf("attack energy cost\n");
            scanf("%d",pokemon_list[i].atk->ep_cost);
            
            }

    }



}


void pokemon2conf_file(){
        







}

int main(void)
{


    inflict_damage(&pika, &piko, 1);
    printf(" piko has %.2f pika has %d energy left", piko.hp, pika.ep);

    return 0;
}