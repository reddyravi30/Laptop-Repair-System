#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Laptop {
    char owner[50];
    char model[50];
    char problem[100];
    int serviceID;
};

void addRecord(FILE *fp) {
    struct Laptop l;
    printf("Enter Service ID: ");
    scanf("%d", &l.serviceID);
    printf("Enter Owner Name: ");
    scanf(" %[^\n]", l.owner);
    printf("Enter Laptop Model: ");
    scanf(" %[^\n]", l.model);
    printf("Describe the Problem: ");
    scanf(" %[^\n]", l.problem);
    fwrite(&l, sizeof(l), 1, fp);
    printf("Record added successfully!\n");
}

void displayRecords(FILE *fp) {
    struct Laptop l;
    rewind(fp);
    printf("\n--- Laptop Service Records ---\n");
    while (fread(&l, sizeof(l), 1, fp)) {
        printf("ID: %d | Owner: %s | Model: %s | Problem: %s\n", l.serviceID, l.owner, l.model, l.problem);
    }
}

int main() {
    FILE *fp = fopen("laptop_services.dat", "ab+");
    int choice;
    if (!fp) {
        printf("Cannot open file.\n");
        return 1;
    }

    do {
        printf("\n1. Add Record\n2. View Records\n3. Exit\nChoose: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addRecord(fp); break;
            case 2: displayRecords(fp); break;
            case 3: break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 3);

    fclose(fp);
    return 0;
}
