#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

int choixMenu;
int index=0;
int s=0;
char test[10];
int i,n,tri,j;
float myn;
int quantite;
char code[50];
int pos;
char line[73]="|---------------------------------------------------------------------|\n";
struct medicament{
    char nom[20],code[10];
    int quantite;
	float prix;
	};
struct medicament tab[1000];
struct dateDachat{
  int jour;
  int mois[12];
  int anne;
};
struct ststic{

  char nomPrdvendu[50];
  float prix;
  float totalTTC;
  char dateDachat[50];
};
struct ststic stat[100];
void Alimenter_le_stock(){
         printf("\t1) Alimenter le stock.\n");
         printf("\t2) Pour returne au la menu.\n");
         printf("\nVotre Choix : ");
         scanf("%d",&tri);
           if(tri==2){
               affichageMenu();
           }else{
                   //demander le code

                   printf("entrer le code:\n") ;
                   scanf(" %s",code);
                    // demander la quantite

                    printf("entrer la quantite:\n");
                    scanf("%d",&quantite);
                    int i , j=0;
                    // verifier si le produit exist
                    for(i=0;i<index;i++){
                        if(strcmp(tab[i].code,code)==0){
                            tab[i].quantite+=quantite;
                            printf("Stock alimenter\n");
                            j=1;
                        }
                    }
             }
    if(j=0){
    printf("le stock non alimente\n");
    }
   printf("\nenter return to go back to the menu:");
        scanf("%s",&test);
}
void aff_ststic(){
        float MIN,MAX=0,total=0;
        MIN = stat[0].prix;
        printf("\n");
        printf("+=================+============================+=================+============\n");
        printf("|   NOM PRO       |         PRIX PROD          |    DATE ACHAT       |\n");
        printf("+=================+============================+=================+============\n");
        for(i=0;i<s;i++)
            {
            total+=stat[i].totalTTC;

              printf("| %s           | %.2f                    |      %s    |\n",stat[i].nomPrdvendu,stat[i].prix,stat[i].dateDachat);
            if(MAX <stat[i].prix)
                 {
                    MAX=stat[i].prix;
            }
            if(MIN>stat[i].prix)
                {
                    MIN=stat[i].prix;
            }
        }
        myn=total/s;
    printf("+=================+=================+=================+==============+========\n");
    printf("\n");
    printf("LE PRIX MAX DES PRODUIT VENDUS EST : %.2f DH \n",MAX);
    printf("LE PRIX MIN DES PRODUIT VENDUS EST : %.2f DH \n",MIN);
    printf("TOTAL DES PRODUIT VENDUS EST : %.2f DH \n",total);
    printf("LE PRIX MOYENNE DES PRODUIT VENDUS EST : %.2f DH \n",myn);
    printf("\nenter return to go back to the menu: ");
            scanf("%s",test);

}
void Achatdeproduit(){

         printf("\t1) Acheter un produit.\n");
         printf("\t2) Pour returne au la menu.\n");
         printf("\nVotre Choix : ");
         scanf("%d",&tri);
           if(tri==2){
               affichageMenu();
           }else{
                           //demander le code
            dla7:
            printf("\nentrer le code:\n") ;
            scanf(" %s",code);
                // demander la quantite

            printf("entrer la quantite:\n");
            scanf("%d",&quantite);
                int i , j=0;
                // verifier si le produit exist
                    for(i=0;i<index;i++){
                        if(strcmp(tab[i].code,code)==0){
                            tab[i].quantite-=quantite;
                            printf("achat faite\n");
                            j=1;
                            strcpy(stat[s].nomPrdvendu,tab[i].nom);
                            stat[s].prix=tab[i].prix;
                            time_t t=time(NULL);
                            strcpy(stat[s].dateDachat,ctime(&t));

                            stat[s].totalTTC = quantite*(tab[i].prix*1.15);
                            s++;
                        }

                    }
                    if(j==0){
            printf("le produit n exist pas");
            goto dla7;
          }


}
        printf("\nenter return to go back to the menu:");
        scanf("%s",&test);
}
void tri_nom(){
    struct medicament temp;
    int i,j;
    for(i=0;i<index-1;i++){
        for(j=i+1;j<index;j++)
        if(strcasecmp(tab[i].nom,tab[j].nom)>0){
              temp=tab[i];
              tab[i]=tab[j];
              tab[j]=temp;
            }
    }
              printf("----------------Liste des produits----------------\n");
        printf("Tout les produits dans le stock:\n\n");
        printf("|Nom               |prix            |Prix TTC       |Quantite\n");
		printf("%s",line);
    for(i=0;i<index;i++){
         printf("%s",line);

        printf("| %s            | %.2f        | %.2f        |%d\n",tab[i].nom,tab[i].prix,tab[i].prix*1.15,tab[i].quantite);
        printf("%s",line);
    }

printf("enter return to go back to the menu:");
        scanf("%s",&test);


  }
void tri_prix(){
    struct medicament temp;
    int i,j;
    for(i=index-1;i>=0;i--){
        for(j=i;j>=0;j--)
        if((tab[i].prix>tab[j].prix)){
              temp=tab[i];
              tab[i]=tab[j];
              tab[j]=temp;
        }
    }
      printf("----------------Liste des produits----------------\n");
        printf("Tout les produits dans le stock:\n\n");
        printf("|Nom               |prix           |Prix TTC       |Quantite\n");
		printf("%s",line);
    for(i=0;i<index;i++){
         printf("%s",line);

        printf("| %s            | %.2f        | %.2f        |%d\n",tab[i].nom,tab[i].prix,tab[i].prix*1.15,tab[i].quantite);
        printf("%s",line);
    }

  printf("enter return to go back to the menu:");
        scanf("%s",&test);
}
void list(){
 printf("----------------Liste des produits----------------\n");
        printf("Tout les produits dans le stock:\n\n");
        printf("|Nom            |CodeBar        |Prix TTC       |Prix      |Quantite |\n");
		printf("%s",line);
    for(i=0;i<index;i++){
         printf("%s",line);

        printf("| %s            | %s        | %.2f       |%.2f       |%d \n",tab[i].nom,tab[i].code,tab[i].prix*1.15,tab[i].prix,tab[i].quantite);
        printf("%s",line);
    }

printf("enter return to go back to the menu:");
        scanf("%s",&test);
}
void ajt(int nbr){

         printf("\t1) Ajouter produit.\n");
         printf("\t2) Pour returne au la menu.\n");
         printf("\nVotre Choix : ");
         scanf("%d",&tri);
           if(tri==2){
               affichageMenu();
           }else{
               for(i=0;i<nbr;i++){
            printf("Entrer le nom de produit : \n");
            scanf("%s",tab[index].nom);
            printf("Entrer le code de produit : \n");
            scanf("%s",tab[index].code);
            do {
                 printf("Entrer le quantite de produit : \n");
            scanf("%d",&tab[index].quantite);
            printf("Entrer le prix de produit : \n");

            }while(tab[index].quantite<0);
           do{
             scanf("%f",&tab[index].prix);
            printf("produit %d\n\n",i+1);
           }while(tab[index].prix<0);
            index++;
                 }
            }



}
int affichageMenu(void){
 int nbr;
  while(true){
       tafe7:
       system("cls");
    printf("*----------------------Gestion de Pharmacie-------------------------*\n\n");
    printf("\t----------------------Menu----------------------\n\n");
    printf("\t1) Ajouter un nouveau produit.\n");
    printf("\t2) Ajouter plusieurs produits.\n");
    printf("\t3) Listage des produits\n");
    printf("\t4) Supprimer un produit.\n");
    printf("\t5) Acheter un produit.\n");
    printf("\t6) Etat du stock.\n");
    printf("\t7) Alimenter le stock.\n");
    printf("\t8) Afficher Statistique.\n");
    printf("\t9) Exit.\n");
    printf("\nVotre choix?\n");
    scanf("%d", &choixMenu);
    system("cls");
    switch (choixMenu)
    {
        case 1:
            printf("----------------Ajouter un nouveau produit----------------\n");
            ajt(1);
            printf("enter return to go back to the menu:");
            scanf("%s",&test);
            break;
        case 2:
            printf("----------------Ajouter plusieurs produits----------------\n");
            printf("Entrer le nombre de produit a ajouter:");
            scanf("%d",&n);
            ajt(n);

            break;
        case 3:
            do{
                printf("1) Trier par nom .\n");
                printf("2) trier par prix.\n");
                printf("0) Pour returne au la menu\n");
                printf("Voulez vous trier les produits par nom ou par prix: ");
                scanf("%d",&tri);

                if(tri==1){
                    tri_nom();
                }else if(tri==2){
                    tri_prix();
                }else{
                goto tafe7;
                }
            }while(tri < 1 || tri > 2);
            break;
        case 4:
            printf("----------------Supprimer un produit----------------\n");
            Suprd();
            printf("\nLe produit que tu as choisi etait supprime \n");
            printf("\nenter return to go back to the menu: ");
            scanf("%s",test);
            break;
        case 5:
            printf("----------------Acheter un produit----------------\n");
            Achatdeproduit();
            break;
        case 6:
            printf("----------------Etat du stock----------------\n");
            do{
                printf("\n\t1) Liste des produits\n");
                printf("\t2) recherche un produit\n");
                printf("\t3) Pour returne au la menu\n\n");
                printf("Voulez vous voir la liste des produits ou rechercher un produit ou Menu: ");
                scanf("%d",&tri);
            }while(tri<1||tri>3);
                switch(tri)
                {
                    case 1:
                        list();
                        break;
                    case 2:{
                        do{
                            int RechercheDeProduit;
                            char code[50];
                            printf("1Recherche par code .\n");
                            printf("2)Recherche par quantite .\n");
                            printf("3)Recherche par Etat de stock. \n");
                            printf("0)Recherche ni code ni quantite ni Etat de stock.\n");
                            printf("\nchoisisez?\n");
                            scanf("%d",&RechercheDeProduit);
                            switch(RechercheDeProduit){
                                case 1:
                                    printf("veuillez entrer le code: ");
                                    scanf("%s",code);
                                    for(int i=0;i<index;i++){
                                        if(strcmp(tab[i].code,code)==0){
                                            printf("---------------------------------\n");
                                            printf("nom             prix        prix TTC \n");
                                            printf("%s        %.2f        %.2f\n\n",tab[i].nom,tab[i].prix,tab[i].prix*1.15);
                                        }
                                    }
                                    printf("enter return to go back to the menu:");
                                    scanf("%s",test);
                                    break;

                                case 2:
                                    printf("veuillez entrer la quantite: ");
                                    scanf("%d",&quantite);
                                    for(int i=0;i<index;i++){
                                            if(tab[i].quantite==quantite){
                                            printf("---------------------------------\n");
                                            printf("nom            prix          prix TTC \n");
                                            printf("%s         %.2f         %.2f\n\n",tab[i].nom,tab[i].prix,tab[i].prix*1.15);
                                            }
                                    }
                                    printf("enter return to go back to the menu:");
                                    scanf("%s",test);
                                    break;

                                case 0:
                                    affichageMenu();
                                    break;

                                case 3:
                                            printf("--------------------------------------\n");
                                            printf("nom            prix          prix TTC \n");
                                    for(int i=0;i<index;i++){
                                        if(tab[i].quantite<3){
                                      printf("%s         %.2f         %.2f\n\n",tab[i].nom,tab[i].prix,tab[i].prix*1.15);
                                      printf("-------------------------------\n");
                                       }
                                    }
                                }
                                    printf("enter return to go back to the menu:");
                                    scanf("%s",test);
                                    break;
                                default :
                                    break;

                            }while(tri!=0||tri>3);
                      }
                         break;
                    case 3:
                           affichageMenu();
                         break;
              }
               break;
        case 7:
                Alimenter_le_stock();
            break;
        case 8:
          aff_ststic();
            break;
        case 9:
            exprt_sts();
            exprt_Prd();
            exit(1);
            break;
  }
 }
}
void Suprd(){
    int i , k=0;
     printf("\t1) Supprimer un produit .\n");
     printf("\t2) Pour returne au la menu.\n");
     printf("\nVotre Choix : ");
     scanf("%d",&tri);
           if(tri==2){
               affichageMenu();
           }else{
               printf("\nentrer le code: ") ;
               scanf(" %s",code);
               // verifier si le produit exist
                   for(i=0;i<index;i++){
                        if(strcmp(tab[i].code,code)==0){
                            k=1;
                            for(j=i;j<index;j++)
                            tab[j]=tab[j+1];
                            index--;
                        }
                   }
           }

    if(k=0){
    printf("le produit n exist pas");
    }

}
void import_sts(){
 FILE *statistique;
    statistique = fopen("statistique.txt", "r");
    while (1)
    {
        fscanf(statistique, "\n%[^,] , %f , %f, %s", &stat[s].nomPrdvendu,&stat[s].totalTTC, &tab[index].prix,stat[s].dateDachat);

        if (strlen(stat[s].nomPrdvendu) == 0){
            fprintf(statistique,"Ligne vide");
        } else
            s++;
        if (feof(statistique))  //end of file
        {
            break;
        }
    }
    fclose(statistique);
}
void import_Prd(){


  FILE *Products;
    Products = fopen("products.txt", "r");
    while (1)
    {
        fscanf(Products, "\n%[^,] , %s , %d , %f", tab[index].nom, tab[index].code, &tab[index].quantite, &tab[index].prix);

        if (strlen(tab[index].code) == 0){
            fprintf(Products,"Ligne vide");
        } else
            index++;
        if (feof(Products))  //end of file
        {
            break;
        }
    }
    fclose(Products);
}
void exprt_sts(){
 FILE *statistique;
            statistique = fopen("statistique.txt", "w");
            for (int i = 0 ; i < s ; i++)
            {
                fprintf(statistique,"%s,%.2f,%.2f,%s\n", stat[i].nomPrdvendu, stat[i].totalTTC,stat[i].prix,stat[i].dateDachat);
            }
            fclose(statistique);
}
void exprt_Prd(){
        FILE *products;
            products = fopen("products.txt", "w");
            for (int i = 0 ; i < index ; i++)
            {
                fprintf(products, "%s, %s , %d , %.2f\n", tab[i].nom, tab[i].code, tab[i].quantite, tab[i].prix);
            }
            fclose(products);
}

int main()
{
    import_sts();
     import_Prd();
     int i;
     affichageMenu();
    return 0;
}
