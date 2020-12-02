// Q.  Perform all database operations using File Handling.

#include <stdio.h>

struct employee {
    char name[30];
    int ID, fg;
    float salary;
};

void insert(FILE *fp);
void display(FILE *fp);
void modify(FILE *fp);
void del_logical(FILE *fp);
void delete(FILE *fp, FILE *fs);
void search(FILE *fp);

void insert(FILE *fp) {
    struct employee e;
    int ch;
    fp = fopen("employee.txt","a+");
    if (fp==NULL) {
        printf("\n File cannot be opened......\n");
        return;
    }
    do {
        printf("Enter name of employee : ");
        scanf("%s",e.name);
        printf("Enter employee ID : ");
        scanf("%d",&e.ID);
        printf("Enter employee salary : ");
        scanf("%f",&e.salary);
        fwrite(&e, sizeof(e), 1, fp);
        printf("\nDo U want to add more records? (0/1) : ");
        scanf("%d", &ch);
        e.fg=0;
    }while (ch==1);
    fclose(fp);
}

void display(FILE *fp) {
    struct employee e;
    int i=0;
    fp = fopen("employee.txt","r");
    if (fp==NULL) {
        printf("\n File cannot be opened......\n");
        return;
    }
    while (fread(&e, sizeof(e), 1, fp)) {
        printf("\nDetails of record %d :\n",i+1);
        printf("Name : %s\n", e.name);
        printf("ID : %d\n", e.ID);
        printf("Salary : %f\n", e.salary);
        i++;
    }
    fclose(fp);
}

void modify(FILE *fp) {
    struct employee e;
    int n, i=0, flag=0;
    fp = fopen("employee.txt","r+");
    if (fp==NULL) {
        printf("\n File cannot be opened......\n");
        return;
    }
    printf("\nEnter the ID of the employee to be modified : ");
    scanf("%d", &n);
    while (fread(&e, sizeof(e), 1, fp)) {
        if (e.ID==n) {
            printf("Record found at location %d", i+1);
            printf("\nEnter new parameters :\n");
            printf("Enter the name : ");
            scanf("%s", e.name);
            printf("\nEnter ID : ");
            scanf("%d", &e.ID);
            printf("\nEnter the salary : ");
            scanf("%f", &e.salary);

            fseek(fp, (-1)*sizeof(e), SEEK_CUR);
            fwrite(&e, sizeof(e), 1, fp);

            printf("\nRecord modified successfully\n");
            flag=1;
            break;
        }
        i++;
    }
    if (flag==0) {
        printf("\nRecord not found\n");
    }
    fclose(fp);
}

int main() {
    FILE *fp, *fs;
    int choice;
    do {
        printf("\nEnter : \n");
        printf("1 for adding employee details\n2 for displaying\n3 for searching\n4 for deleting\n5 for modifying\n6 for Exiting\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1 :
                insert(fp);
                break;
            case 2 :
                display(fp);
                break;
            case 3 :
                search(fp);
                break;
            case 4 :
                delete(fp, fs);
                break;
            case 5 :
                modify(fp);
                break;
            default :
                printf("\nU have entered a wrong choice\nPlz enter a valid choice\n");    
        }
    }while(choice!=6);
    printf("\n\t*********Program exited successfully***********\n");
    return 0;
}

void del_logical(FILE *fp) {
    struct employee e;
    int n, i=0, flag=0;
    fp = fopen("employee.txt","r+");
    if (fp==NULL) {
        printf("\n File cannot be opened......\n");
        return;
    }
    printf("\nEnter employee ID : ");
    scanf("%d", &n);
    while (fread(&e, sizeof(e), 1, fp)) {
        if (e.ID==n && e.fg==0) {
            printf("Record found at location %d\n", i+1);
            e.fg=1;

            fseek(fp, (-1)*sizeof(e), SEEK_CUR);
            fwrite(&e, sizeof(e), 1, fp);

            printf("\nRecord deleted successfully\n");
            flag=1;
            break;
        }
        i++;
    }
    if (flag==0) {
        printf("\nRecord not found\n");
    }
}

void search(FILE *fp) {
    struct employee e;
    int n, i=0, flag=0;
    fp = fopen("employee.txt","r");
    if (fp==NULL) {
        printf("\n File cannot be opened......\n");
        return;
    }
    printf("Enter employee ID to search : ");
    scanf("%d", &n);
    while(fread(&e, sizeof(e), 1, fp)) {
        if (e.ID==n && e.fg==0) {
            printf("Record found at location %d\n", i+1);
            printf("Name : %s\n", e.name);
            printf("ID : %d\n", e.ID);
            printf("Salary : %f\n", e.salary);
        }
        i++;
    }
    if (flag==1) {
        printf("\nRecord not found\n");
    }
    fclose(fp);
}

void delete(FILE *fp, FILE *fs) {
    struct employee e;
    int n, i=0, flag=0;
    fp = fopen("employee.txt","r+");
    if (fp==NULL) {
        printf("\n File cannot be opened......\n");
        return;
    }
    fs = fopen("text.txt", "w+");
    if(fs==NULL) {
        printf("\nFile cannot be opened\n");
        return;
    }
    printf("\nEnter employee ID : ");
    scanf("%d", &n);
    while (fread(&e, sizeof(e), 1, fp)) {
        if (e.ID==n) {
            printf("\nRecord %d deleted\n", i+1);
            printf("Deleted record is :\n");
            printf("Name : %s\n", e.name);
            printf("ID : %d\n", e.ID);
            printf("Salary : %f\n", e.salary);
            flag=1;
        }
        i++;
    }
    if (flag==0) {
        printf("\nRecord not found\n");
    }
    fclose(fp);
}
