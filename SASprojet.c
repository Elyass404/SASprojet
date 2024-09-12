#include <stdio.h>
#include <string.h>

typedef struct {
    char nom[20];
    int  nbr_etudient;
}depart;

typedef struct{
    int jour;
    int mois;
    int annee;

}DATE;

typedef struct{
    int ID ;
    char nom[50];
    char prenom[50];
    DATE date_naissance;
    char departement[50];
    float note_generale;

}etudient;

depart departement_list[100];
int nbr_depart = 0;

etudient etudient_list[100];
int last_id=1 ;
int nbr_etudient =0;



void ajouter_etudient(){
     etudient_list[nbr_etudient].ID = last_id;
     printf("saisez le  nom d'etudient: \n");
     scanf(" %[^\n]",&etudient_list[nbr_etudient].nom);
     printf("saisez le  prenom d'etudient: \n");
     scanf(" %[^\n]",&etudient_list[nbr_etudient].prenom);
     printf("saisez la  date de naissance d'etudient: \n");
     printf("jour: ");
     scanf(" %d",&etudient_list[nbr_etudient].date_naissance.jour);
     printf("mois: ");
     scanf(" %d]",&etudient_list[nbr_etudient].date_naissance.mois);
     printf("annee: ");
     scanf(" %d",&etudient_list[nbr_etudient].date_naissance.annee);
     printf("saisez le departement d'etudient: \n");
     scanf(" %[^\n]",&etudient_list[nbr_etudient].departement);
     printf("saisez le note generale d'etudient: \n");
     scanf(" %f",&etudient_list[nbr_etudient].note_generale);
     printf("Operation fini! l'etudient N%d est saiser avec succee\n",etudient_list[nbr_etudient].ID);
     last_id++;
     nbr_etudient++;

}

void modifier_etudient(){

    int etd_id;
    int found =-1;
    printf("Tapez le ID de l'etudient: \n");
    scanf("%d",&etd_id);
    for(int i = 0; i < nbr_etudient ; i++){
        if (etudient_list[i].ID == etd_id){
        found=i;
        break;}
    }

    if(found != -1 ){
            int choix2;
            printf("Voici les information actuelle d'etudient: \n");
            printf("ID: %d\n",etudient_list[found].ID);
            printf("Nom: %s\n",etudient_list[found].nom);
            printf("Prenom: %s\n",etudient_list[found].prenom);
            printf("Date de Naissance: %d-%d-%d\n",etudient_list[found].date_naissance.jour,etudient_list[found].date_naissance.mois,etudient_list[found].date_naissance.annee);
            printf("Departement: %s\n",etudient_list[found].departement);
            printf("Note generale: %.2f\n",etudient_list[found].note_generale);
            Modif_Menu :
            printf("--------La modification des information--------\n");
            printf("Quelle info tu veux modifier:\n");

            printf("1- Nom d'etudient.\n");
            printf("2- prenom d'etudient.\n");
            printf("3- Date de Naissance d'etudient.\n");
            printf("4- Departemen d'etudient.\n");
            printf("5- Note Generale.\n");
            printf("0- Pour quitter");
            scanf("%d",&choix2);

            switch (choix2) {
            case 1:
                printf("Saisez le nouveau nom: ");
                scanf(" %[^\n]",&etudient_list[found].nom);
                printf("La tache complete! le nouveau nom est: \"%s\"\n",etudient_list[found].nom);
                goto Modif_Menu;
                break;

            case 2:
                printf("Saisez le nouveau prenom: ");
                scanf(" %[^\n]",&etudient_list[found].prenom);
                printf("La tache complete! le nouveau prenom est: \"%s\"\n",etudient_list[found].prenom);
                goto Modif_Menu;
                break;
            case 3:
                printf("Saisez la nouvelle date de naissance: \n");
                printf("jour: ");
                scanf(" %d",&etudient_list[found].date_naissance.jour);
                printf("mois: ");
                scanf(" %d",&etudient_list[found].date_naissance.mois);
                printf("annee: ");
                scanf(" %d",&etudient_list[found].date_naissance.annee);
                printf("La tache complete! la nouvelle date de naissance est: %d-%d-%d\n",etudient_list[found].date_naissance.jour,etudient_list[found].date_naissance.mois,etudient_list[found].date_naissance.annee);
                goto Modif_Menu;
                break;
            case 4:
                printf("Saisez la nouvelle departement: ");
                scanf(" %[^\n]",&etudient_list[found].departement);
                printf("La tache complete! le nouveau nom est: \"%s\"\n",etudient_list[found].departement);
                goto Modif_Menu;
                break;
            case 5:
                printf("Saisez la nouvelle note generale: ");
                scanf(" %f",&etudient_list[found].note_generale);
                printf("La tache complete! le nouveau nom est: \"%.2f\"\n",etudient_list[found].note_generale);
                goto Modif_Menu;
                break;
            default :
                break;
            }


    }else{
            printf("Le numero ID est introvable!\n");
    }
}

void supprime_etudient(){

    int etd_id;
    int found = -1;
    printf("Saisez le ID d'etudient a supprime: ");
    scanf(" %d",&etd_id);

   for(int i=0 ; i<nbr_etudient ; i++){
        if(etudient_list[i].ID == etd_id){
            found = i;
            break;

        }
   }

   if(found!= -1){
        for ( int j = found ; j < nbr_etudient -1 ; j++){
               etudient_list[j] = etudient_list[j+1];
         }nbr_etudient--;
    }else{
            printf("Le numero ID est introvable!\n.");
        }

        printf("Suppression complete! l'etudient a ete supprimer");

}

void afficher_tous(){
    int counter = 1;
    for(int i=0; i<nbr_etudient;i++){

        printf("L'etudient N%d\n",counter);
        printf("    Nom: %s\n",etudient_list[i].nom);
        printf("    Prenom: %s\n",etudient_list[i].prenom);
        printf("    Date de naissance: %d-%d-%d\n",etudient_list[i].date_naissance.jour,etudient_list[i].date_naissance.mois,etudient_list[i].date_naissance.annee);
        printf("    Departement: %s\n",etudient_list[i].departement);
        printf("    Note generale: %.2f\n",etudient_list[i].note_generale);
        counter++;
    }

}

void afficher_moyenne_generale(){
    int countDep=0;
    char departemets[20][50];

  for(int i = 0; i < nbr_etudient; i++){
    int deja_inserer = 0;
    for (int j = 0; j < i; j++){
      if (strcmp(etudient_list[i].departement, etudient_list[j].departement) == 0){
        deja_inserer = 1;
        break;
      }
    }
    if (deja_inserer==0)
    {
      printf("%s\n", etudient_list[i].departement);
      strcpy(departemets[countDep], etudient_list[i].departement);
      countDep++;
    }
  }

  for (int i = 0; i < countDep; i++){
    float somme = 0;
    int departement_length = 0;

    for (int j = 0; j < nbr_etudient; j++){
      if (strcmp(departemets[i], etudient_list[j].departement) == 0){
        somme += etudient_list[j].note_generale;
        departement_length++;
      }
    }
    printf("La moyenne generale pour la departement \"%s\": %.2f \n ", etudient_list[i].departement, somme / departement_length);
  }
}


void afficher_statistiques() {
    int choix3;
    float seuil;
    int temp;
    int indexes[100];
    int count = 0;

    Statistique_Menu:
    printf("--------Affichage des statistiques--------\n");
    printf("Quelle statistique tu peux afficher\n");

    printf("1- Afficher le nombre total d'etudiants inscrits.\n");
    printf("2- Afficher le nombre d'etudiants dans chaque departement.\n");
    printf("3- Afficher les etudiants ayant une moyenne generale superieure a un certain seuil.\n");
    printf("4- Afficher les 3 etudiants ayant les meilleures notes.\n");
    printf("5- Afficher le nombre d'etudiants ayant reussi dans chaque departement.\n");
    printf("0- Quitter ce menu vers l'acceuile.\n");
    scanf("%d", &choix3);

    switch (choix3) {
        depart departement_list[100];
        int nbr_depart = 0;
        etudient jst_etudients[100];
        etudient temp;
        case 1:
            printf("Le nombre total des etudiants inscrits est: %d\n", nbr_etudient);
            goto Statistique_Menu;
            break;

        case 2:
            for(int i = 0 ;i <nbr_etudient ; i++){
                int found = 0;
                for (int j=0 ; j < nbr_depart ; j++){
                    if(strcmp(departement_list[j].nom,etudient_list[i].departement)==0){
                        departement_list[j].nbr_etudient++;
                        found++;
                        break;
                    }
                }
                if (found == 0 ){
                    strcpy(departement_list[nbr_depart].nom,etudient_list[i].departement);
                    departement_list[nbr_depart].nbr_etudient=1;
                    nbr_depart++;
                }
            }
            for (int i = 0; i < nbr_depart ; i++){
                printf("Le nombre d'etudients en depaartement \"%s\": %d etudients\n",departement_list[i].nom,departement_list[i].nbr_etudient);
            }
            break;

        case 3:
            printf("Saisir la note que vous souhaitez utiliser comme seuil: ");
            scanf("%f", &seuil);
            for (int i = 0; i < nbr_etudient; i++) {
                if (etudient_list[i].note_generale >= seuil) {
                    printf("%s %s: %.2f\n", etudient_list[i].nom, etudient_list[i].prenom, etudient_list[i].note_generale);
                }else{
                    printf("Personne n’a reussi l’examen\n");//makayn gha lkassol 3la khoh
                    break;
                }
            }
            goto Statistique_Menu;
            break;

        case 4:
            //deja declarina array smito jst_etudinets lli n7to fih nfss ljdwl lassli bach maytbdlch lina l assli
            for(int i= 0; i < nbr_etudient;i++){
                jst_etudients[i]=etudient_list[i];
            }

            for (int i = 0; i < nbr_etudient -1; i++){
                for(int j = i+1; j < nbr_etudient; j++){
                    if(jst_etudients[i].note_generale < jst_etudients[j].note_generale){
                        temp = jst_etudients[i];
                        jst_etudients[i]= jst_etudients[j];
                        jst_etudients[j] = temp;
                    }
                }
            }
            //db ghanbyno dok 3 lwlin lmojtahidin
            printf("Les 3 etudient avec les meilleures notes:\n");
            for(int i = 0 ; i < 3 && i < nbr_etudient; i++){ //khassna nzido dik && bach loop mat3awdch fi 7alat ma3ndnach etudient talt ola tani o talt
                printf("%d- %s %s: %.2f\n",i+1,jst_etudients[i].nom,jst_etudients[i].prenom,jst_etudients[i].note_generale);

            }
            goto Statistique_Menu;
            break;

        case 5:
            for (int i = 0; i < nbr_etudient; i++) {
        int found = 0;
        for (int j = 0; j < nbr_depart; j++) {
            if (strcmp(etudient_list[i].departement, departement_list[j].nom) == 0) {
                if (etudient_list[i].note_generale >= 10) {
                    departement_list[j].nbr_etudient++;
                }
                found = 1;
                break;
            }
        }
        if (found==0) {
            strcpy(departement_list[nbr_depart].nom, etudient_list[i].departement);
            if (etudient_list[i].note_generale >= 10){
                departement_list[nbr_depart].nbr_etudient++; //ila etudient jab 10 ola fatha, ya3ni tzad wahd mn drari lli nj7o mn dik departement
            }
            nbr_depart++;
        }
    }

    //hna sf ghanbyno chhal mn wahd njh mn koula departement
    printf("\n");
    for (int i = 0; i < nbr_depart; i++) {
        printf("Le nombre d'etudients qui onts passe a departement \"%s\": %d\n", departement_list[i].nom,departement_list[i].nbr_etudient);
    }
            goto Statistique_Menu;
            break;

            case 0:
            break;

        default:
            printf("Choix invalide. Veuillez reessayer.\n");
            goto Statistique_Menu;
            break;
    }
}

void afficher_un_etudient(){
    char nom_recherche[50];
    int found = 0;

    printf("Saisez le nom de l'etudiant a rechercher: ");
    scanf(" %[^\n]", nom_recherche);


    for (int i = 0; i < nbr_etudient; i++) {
        if (strcmp(etudient_list[i].nom, nom_recherche) == 0) {
            printf("Voici les onformation pour l'etudient: '%s':\n", nom_recherche);
            printf("    ID: %d\n", etudient_list[i].ID);
            printf("    Nom: %s\n", etudient_list[i].nom);
            printf("    Prenom: %s\n", etudient_list[i].prenom);
            printf("    Date de naissance: %d-%d-%d\n", etudient_list[i].date_naissance.jour, etudient_list[i].date_naissance.mois, etudient_list[i].date_naissance.annee);
            printf("    Departement: %s\n", etudient_list[i].departement);
            printf("    Note generale: %.2f\n", etudient_list[i].note_generale);
            found = 1;
        }
    }

    if (found==0) {
        printf("Le nom est introvable!\n");
    }


}

void afficher_tous_en_departement(){

    char departement_recherche[50];
    int found = 0;

    printf("Saisez le nom du departement: ");
    scanf(" %[^\n]", departement_recherche);

    printf("La Liste des etudients inscrits dans le departement \"%s\":\n", departement_recherche);
    for (int i = 0; i < nbr_etudient; i++) {
        if (strcmp(etudient_list[i].departement, departement_recherche) == 0) {
            printf("  L'etudient N%d\n", i+1);
            printf("    ID: %d\n", etudient_list[i].ID);
            printf("    Nom: %s\n", etudient_list[i].nom);
            printf("    Prenom: %s\n", etudient_list[i].prenom);
            printf("    Date de naissance: %02d/%02d/%04d\n", etudient_list[i].date_naissance.jour, etudient_list[i].date_naissance.mois, etudient_list[i].date_naissance.annee);
            printf("    Note generale: %.2f\n", etudient_list[i].note_generale);
            printf("---------\n");
            found = 1;

        }
    }

    if (found==0) {
        printf("Aucun etudiant trouve dans cette departement de '%s'.\n", departement_recherche);
    }
}


void tri_etudients() {
    int choix;
    etudient temp;

    printf("1- Trier les etudients par nom (A a Z).\n");
    printf("2- Trier les etudients par nom (Z a A).\n");
    printf("3- Trier les etudients par note generale (du plus eleve au plus faible).\n");
    printf("4- Trier les etudients par note generale (du plus faible au plus eleve).\n");
    printf("5- Trier les etudients par statut de reussite (moyenne >= 10/20).\n");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            // les noms mn A htal Z
            for (int i = 0; i < nbr_etudient - 1; i++) {
                for (int j = i + 1; j < nbr_etudient; j++) {
                    if (strcmp(etudient_list[i].nom, etudient_list[j].nom) > 0) {
                        temp = etudient_list[i];
                        etudient_list[i] = etudient_list[j];
                        etudient_list[j] = temp;
                    }
                }
            }
            break;

        case 2:
            // les noms mn Z htal A
            for (int i = 0; i < nbr_etudient - 1; i++) {
                for (int j = i + 1; j < nbr_etudient; j++) {
                    if (strcmp(etudient_list[i].nom, etudient_list[j].nom) < 0) {
                        temp = etudient_list[i];
                        etudient_list[i] = etudient_list[j];
                        etudient_list[j] = temp;
                    }
                }
            }
            break;

        case 3:
            // note general mn lkbir l sghir
            for (int i = 0; i < nbr_etudient - 1; i++) {
                for (int j = i + 1; j < nbr_etudient; j++) {
                    if (etudient_list[i].note_generale < etudient_list[j].note_generale) {
                        temp = etudient_list[i];
                        etudient_list[i] = etudient_list[j];
                        etudient_list[j] = temp;
                    }
                }
            }
            break;

        case 4:
            // note general mn sghir lkbir
            for (int i = 0; i < nbr_etudient - 1; i++) {
                for (int j = i + 1; j < nbr_etudient; j++) {
                    if (etudient_list[i].note_generale > etudient_list[j].note_generale) {
                        temp = etudient_list[i];
                        etudient_list[i] = etudient_list[j];
                        etudient_list[j] = temp;
                    }
                }
            }
            break;

        case 5:
            // les etudients lli najhin  (note generale >= 10)
            for (int i = 0; i < nbr_etudient - 1; i++) {
                for (int j = i + 1; j < nbr_etudient; j++) {
                    if ((etudient_list[i].note_generale >= 10) && (etudient_list[j].note_generale < 10)) {
                        temp = etudient_list[i];
                        etudient_list[i] = etudient_list[j];
                        etudient_list[j] = temp;
                    }
                }
            }
            break;

        default:
            printf("Choix invalide.\n");
            return;
    }

    // Display the sorted list
    printf("Liste des etudiants tries:\n");
    for (int i = 0; i < nbr_etudient; i++) {
        printf("  L'etudiant N%d\n", i + 1);
        printf("    ID: %d\n", etudient_list[i].ID);
        printf("    Nom: %s\n", etudient_list[i].nom);
        printf("    Prenom: %s\n", etudient_list[i].prenom);
        printf("    Date de naissance: %02d/%02d/%04d\n", etudient_list[i].date_naissance.jour, etudient_list[i].date_naissance.mois, etudient_list[i].date_naissance.annee);
        printf("    Note generale: %.2f\n", etudient_list[i].note_generale);
        printf("---------\n");
    }
}





int main(){
int choix ;
etudient_list[0].ID = last_id;
strcpy(etudient_list[0].nom,"habbat");
strcpy(etudient_list[0].prenom,"abdo");
etudient_list[0].date_naissance.jour = 12;
etudient_list[0].date_naissance.mois = 5;
etudient_list[0].date_naissance.annee = 2000;
strcpy(etudient_list[0].departement,"math");
etudient_list[0].note_generale=12.50;
last_id++;
nbr_etudient++;

etudient_list[1].ID = last_id;
strcpy(etudient_list[1].nom,"ilyass");
strcpy(etudient_list[1].prenom,"marghine");
etudient_list[1].date_naissance.jour = 38;
etudient_list[1].date_naissance.mois = 40;
etudient_list[1].date_naissance.annee = 1990;
strcpy(etudient_list[1].departement,"math");
etudient_list[1].note_generale=20;
last_id++;
nbr_etudient++;



The_Menu:
printf("---------Menu des Taches---------\n");
printf("Saisez le nombre du tache tu veux faire parmis les suivants:\n");
printf("1- Ajouter un nouvau etudient.\n");
printf("2- Modifier les info d'un Etudiant.\n");
printf("3- Supprimer un Etudiant.\n");
printf("4- Afficher tous les etudiant.\n");
printf("5- Afficher la moyenne generale de chaque departement.\n");
printf("6- Afficher les statistiques.\n");// fwstha kayn wahd menu akhor
printf("7- Afficher un etudient par son nom.\n");
printf("8- Afficher les etudients d'un departement.\n");
printf("9- trier les etudients.\n");
scanf("%d",&choix);

switch (choix){

case 1 :
    ajouter_etudient();
    goto The_Menu;
break;

case 2 :
    modifier_etudient();
    goto The_Menu;
break;

case 3 :
    supprime_etudient();
    goto The_Menu;
break;

case 4 :
    afficher_tous();
    goto The_Menu;
break;

case 5 :
    afficher_moyenne_generale();
    goto The_Menu;
break;

case 6 :
    afficher_statistiques();
    goto The_Menu;
break;

case 7 :
    afficher_un_etudient();
    goto The_Menu;
break;

case 8 :
    afficher_tous_en_departement();
    goto The_Menu;
break;

case 9 :
    tri_etudients();
    //goto The_Menu;
break;

default:
    printf("Choix invalide. Veuillez reessayer.\n");
    goto The_Menu;
    break;



}

    return 0 ;
}




//system("@cls||clear");
