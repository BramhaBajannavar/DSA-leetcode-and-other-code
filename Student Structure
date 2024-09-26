
#include <stdio.h>

struct student {
    char name[50];
    char usn[10];
    int mobile_no;
};


int main(){
    printf("Enter how many students: \n");
    int n;
    scanf("%d",&n);
    struct student stud[n];
    for (int i=0;i<n;++i){
        printf("Enter the name of student %d:",i+1);
        scanf("%s", stud[i].name);
        printf("Enter the USN of student %d:",i+1);
        scanf("%s", stud[i].usn);
        printf("Enter the mobile number of student %d:",i+1);
        scanf("%d", &stud[i].mobile_no);
    }
    
    for (int i=0;i<n;++i){
        printf ("The name of student 1 is : %s  \n", stud[i].name);
        printf ("The USN of student 1 is : %s  \n", stud[i].usn);
        printf ("The mobile number of student 1 is : %d    \n", stud[i].mobile_no);
    }
}
