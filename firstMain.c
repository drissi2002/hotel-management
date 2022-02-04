#include"structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void allocationclient(person** client)
{
    *client = (person*)malloc(sizeof(person));
    if (!*client) exit(-1);
}
void allocationchambre(room** chambre)
{
    *chambre = (room*)malloc(sizeof(room));
    if (!*chambre) exit(-2);
}
void allocationreserve(reservation**reserve)
{
    *reserve = (reservation*)malloc(sizeof(reservation));
    if (!*reserve) exit(-4);
}

void ajoutclient(person* client,int n)
{
    printf("Donner le nom de client : ");
    scanf("%s",(client+n)->nom);
    printf("Donner le prenom de client :");
    scanf("%s",(client+n)->prenom);
    printf("Donner le CIN de client : ");
    scanf("%li",&(client+n)->id);
    printf("Donner le numero de telephone de client : ");
    scanf("%li",&(client+n)->telephone);

    }
void supprimerclient(person *client , int n)
{ int id_sup,pos,i,j;
     printf("Donner L'ID de client a supprimer  : ");
scanf("%li",&id_sup);
    for (i=0;i<n;i++)
if(&client[i].id==id_sup)
    pos=i;
if(pos==n)
    n--;
else
    for(j=pos;j<n;j++)
    {client[j]=client[j+1];}
n--;
    printf("Client avec l'ID %li  est supprimee ",id_sup);
}
void modifierclient(person * client , int n)
{ int id_mod,pos,i,j,choix;
      printf("Client a modifier par ID : ");
    scanf("%li",&id_mod);
    for (i=0;i<n;i++)
    {if(client[i].id==id_mod)
        pos=i;}
        printf("Modification : \n 1/Modifier Nom \n 2/Modifier Prenom \n 3/Modifier ID \n 4/Modifier Telephone \n");
        printf("Votre choix : ");
        scanf("%d",&choix);
        if (choix==1)
            {printf("Nouveau Nom : ");
            scanf("%s",&client[pos].nom);}
              if (choix==2)
            {printf("Nouveau Prenom : ");
            scanf("%s",&client[pos].prenom);}
              if (choix==3)
            {printf("Nouveau ID : ");
            scanf("%s",&client[pos].id);}
              if (choix==4)
            {printf("Nouveau Telephone: ");
            scanf("%s",&client[pos].telephone);}

}

void affichageclients(person * client, int n)
{

    for (int i=0;i<n;i++)
   { //Liste des clients
       printf("Client n %d \n Nom : %s \n Prenom : %s  \n ID : %d \n Telephone : %d",i+1,client[i].nom,client[i].prenom,client[i].id,client[i].telephone);
       printf("\n \n ");
   }


}


void ajoutchambre(room *chambre , int m)
{
     printf("Donner le numero de chambre  :  ");
    scanf("%d",&chambre[m].numero);
    printf("Donner le nombre de lits  :  ");
    scanf("%d",&chambre[m].num_lits);
    printf("Donner le prix du chambre :  ");
    scanf("%f",&chambre[m].prix);
chambre[m].dispo=true;
}
void supprimerchambre(room * chambre , int m)
{ int num,i,pos,j;
            printf("Donner Le numero du chambre a supprimer  : ");
scanf("%d",&num);
    for (i=0;i<m;i++)
if(chambre[i].numero==num)
    pos=i;
if(pos==m)
    m--;
else
    for(j=pos;j<m;j++)
    { chambre[j]=chambre[j+1];}
    printf("Chambre avec le numero %d  est supprimee ",num);
}

void modifierchambre(room * chambre , int m)
{ int id_mod,i,choix,pos;
     printf("Chambre a modifier : ");
    scanf("%li",&id_mod);
    for (i=0;i<m;i++)
    {if(chambre[i].numero==id_mod)
        pos=i;}
        printf("Modification : \n 1/Modifier Numero \n 2/Modifier le nombre de lits \n 3/Modifier le Prix \n ");
        printf("Votre choix : ");
        scanf("%d",&choix);
        if (choix==1)
            {printf("Nouveau numero : ");
            scanf("%d",&chambre[pos].numero);}
              if (choix==2)
            {printf("Nouveau nombre de lits : ");
            scanf("%d",&chambre[pos].num_lits);}
              if (choix==3)
            {printf("Nouveau prix : ");
            scanf("%f",&chambre[pos].prix);}
}

void affichagechambre(room * chambre , int m)
{ int i,pos;
char verif;
      for (int i=0;i<m;i++)
   { //Liste des chambres
   if(chambre[i].dispo)
    verif='O';
   else
    verif='N';
       printf(" Numero de chambre : %d \n Nombre de lits : %d  \n Prix : %5.2f  \n Disponibilite : %c",chambre[i].numero,chambre[i].num_lits,chambre[i].prix,verif);
       printf("\n \n ");
   }
}

void ajoutreservation(reservation * reserve ,room * chambre , int u , int m)
{ int num_reserve,id_client,num_chambre,i,pos,pos_reserve=-1;
     printf("Donner le numero de reservation : \n");
    scanf("%d",&num_reserve);
    printf("Donner L'ID du client : ");
    scanf("%li",&id_client);
    printf("Donner le numero de chambre : ");
    scanf("%d",&num_chambre);
    for (i=0;i<m;i++)
        {if((num_chambre==chambre[i].numero)&&(chambre[i].dispo==true))

            pos_reserve=i;
        }
        reserve[u].id_client=id_client;
        reserve[u].numero_room=num_chambre;
        reserve[u].num=num_reserve;
        chambre[pos_reserve].dispo=false;
        if(pos_reserve==-1)
        {printf("Chambre numero %d est deja reservee",num_chambre);
        }

        }



void supprimerreservation(reservation * reserve , int u)
{ int nrs,i,nrs_pos,pos,j;
     printf("Donner le numero de reservation a supprimer : ");
scanf("%d",&nrs);
    for(i=0;i<u;i++)
if(reserve[i].num==nrs)
    nrs_pos=i;
    if(nrs_pos==u)
    u--;
else
    for(j=nrs_pos;j<u;j++)
    { reserve[j]=reserve[j+1];}
u--;
    printf("Reservation numero  %d  est supprimee ",nrs);
}
void modifierreservation ( reservation * reserve , int u)
{ int modif_res,choixy,pos_res,i;
    printf("Donner le numero de reservation a modifier : ");
    scanf("%d",&modif_res);
     printf("Modification : \n 1/Modifier Numero de reservation  \n 2/Modifier l'Id du client reserve \n 3/Modifier le numero de chambre reserve \n ");
        printf("Votre choix : ");
        scanf("%d",&choixy);
        for(i=0;i<u;i++)
            if(reserve[i].num==modif_res)
                pos_res=i;
        if (choixy==1)
            {printf("Nouveau numero de reservation  : ");
            scanf("%d",&reserve[pos_res].num);}
              if (choixy==2)
            {printf("Nouveau ID du client : ");
            scanf("%d",&reserve[pos_res].id_client);}
              if (choixy==3)
            {printf("Nouveau numero de chambre : ");
            scanf("%d",&reserve[pos_res].numero_room);}
}
void affichagereservation(reservation * reserve , int u,room * chambre)
{ int i;
    printf("********************** List Des reservations ********************** \n");
    // afficher les reservations
    for(i=0;i<u;i++)
    {  if((chambre[i].dispo==false) &&(chambre[i].numero==reserve[i].numero_room))
         {printf("Reservation numero : %d \n",reserve[i].num);
        printf("L'ID du Client : %d \n",reserve[i].id_client);
        printf("Numero de chambre : %d \n",reserve[i].numero_room);}
        printf("\n ****************************************** \n");
    }

}
