#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 2

typedef struct {
    int id;
    char name[100];
    float price;
    int quantity;
} Product;
void addProduct(Product inv[],int *count);
void printInventory(const Product inv[],int count);
int main()
{
    Product inventory[MAX_PRODUCTS];
    int productCount = 0;
    addProduct(inventory,&productCount);
    printInventory(inventory,productCount);
    return 0;
}
void addProduct(Product inv[],int *count){
    if(*count >= MAX_PRODUCTS){
        printf("Inventory FULL!!\n");
        return;
    }
    printf("---New Entry---\n");
    printf("Enter ID: ");scanf(" %d",&inv[*count].id);
    while(getchar() != '\n');
    printf("Enter Name: ");fgets(inv[*count].name,100,stdin);
    inv[*count].name[strcspn(inv[*count].name,"\n")] = '\0';
    printf("Enter price: ");scanf(" %f",&inv[*count].price);
    printf("Enter Quantity: ");scanf(" %d",&inv[*count].quantity);
    (*count)++;
}
void printInventory(const Product inv[],int count){
    for(int i=0;i<count;i++){
        printf("ID: %d\n",inv[i].id);    
        printf("Name: %s\n",inv[i].name);
        printf("Price: %f\n",inv[i].price);
        printf("Quantity: %d\n",inv[i].quantity);
    }
}
