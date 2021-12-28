//
//  main.c
//  Learning and forgetting
//
//  Created by 游明睿 on 2021/4/21.
//

#include <stdio.h>


void trans(unsigned set){
    //printf("succeed\n");
    int i=0;
    int count =0;
    while ((1 << i)<=set){
        if ((set & (1 << i))>0){
            //printf("%u\n",set & ~(1 << i));
            //printf("learn %d ",i);
            count ++;
        }
        i++;
    }
    //printf("%d\n",i);
    printf("%d\n",count);
    return ;
}

int main(int argc, const char * argv[]) {
    
    
    int s1,s2,s3;
    scanf("%d %d %d",&s1,&s2,&s3);
    
    unsigned n1,n2,n3;
    n1 = 1 << s1;
    n2 = 1 << s2;
    n3 = 1 << s3;
    unsigned set1 = n1 ^ n2 ^ n3;
    //printf("%u\n",set1);
    //trans(set1);
    int s4,s5,s6;
    scanf("%d %d %d",&s4,&s5,&s6);
    
    unsigned n4,n5,n6;
    n4 = 1 << s4;
    n5 = 1 << s5;
    n6 = 1 << s6;
    unsigned set2 = n4 ^ n5 ^ n6 ^ set1;
    //trans(set2);
    int s7,s8,s9;
    scanf("%d %d %d",&s7,&s8,&s9);
    
    unsigned n7,n8,n9;
    n7 = 1 << s7;
    n8 = 1 << s8;
    n9 = 1 << s9;
    unsigned set3 = n7 ^ n8 ^ n9;
    int s10,s11,s12;
    scanf("%d %d %d",&s10,&s11,&s12);
    
    unsigned n10,n11,n12;
    n10 = 1 << s10;
    n11 = 1 << s11;
    n12 = 1 << s12;
    unsigned set4 = n10 ^ n11 ^ n12;
    //printf("set3 ||set4= %u\n",set3|set4);
    unsigned set5 = ( set4 ^ (set3 | set4) );
    //trans (set5);
    int s13,s14,s15;
    scanf("%d %d %d",&s13,&s14,&s15);
    unsigned n13,n14,n15;
    n13 = 1 << s13;
    n14 = 1 << s14;
    n15 = 1 << s15;
    unsigned set6 = n13 + n14 + n15;
    trans(set2);
    trans (set5);
    printf("%u",set6);
    return 0;
    
    
}
