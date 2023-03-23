#include<stdio.h>
#define NCARDS 52
#define NSUITS 4
char values[]="23456789TJKQA";
char suits[]="CDHS";
int rank_card(char value,char suit){
    for(int i=0;i<NCARDS/NSUITS;i++){
        if(values[i]==value){
            for(int j=0;j<NSUITS;j++){
                if(suits[j]==suit){
                    return (i*NSUITS+j);
                }
            }
        }
    }
}
char suit(int card){
    return suits[card%4];
}
char value(int card){
    return values[card/NSUITS];
}
int main(){
    printf("Rank of D7 is : %d\n",rank_card('7','D'));
    printf("%d is this card: %c%c",21,suit(21),value(21));
}
