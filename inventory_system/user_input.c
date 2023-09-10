#include "inventory_implementation.c"

void getItemName(char name[]){
    printf("Please enter the item's name:\n");
    fgets(name, MAX_STR_LEN, stdin);
}

void getItemType(char type[]){
    printf("Please enter the item's type:\n");
    fgets(type, MAX_STR_LEN, stdin);
}

void getItemDescription(char description[]){
    printf("Please enter the item's description:\n");
    fgets(description, MAX_STR_LEN, stdin);
}

void getItemRarity(int *rarity){
    printf("Please enter the item's rarity:\n");
    scanf("%d", rarity);
    getchar();
}

void getItemAmount(int *amount){
    printf("Please enter the item's amount:\n");
    scanf("%d", amount);
    getchar();
}

int main(){
    Inventory_node *inv_head = NULL;
    Inventory_node *temp = NULL;
    int choice = 0;
    char name[MAX_STR_LEN];
    char type[MAX_STR_LEN];
    char description[MAX_STR_LEN];
    int rarity, count;

    while (true)
    {
        printf("Please choose one of the following options:\n");
        printf("1 - Add a new item.\n");
        printf("2 - Search an item by name.\n");
        printf("3 - Search an item by description.\n");
        printf("4 - Query items by type.\n");
        printf("5 - Query items by rarity (show items that are greater than equal to the rarity you type in).\n");
        printf("6 - Modify an existing item.\n");
        printf("7 - Delete an item.\n");
        printf("8 - Print out the list of items.\n");
        printf("9 - Sort items in alphabetical order.\n");
        printf("10 - Delete all items in inventory and exit.\n");
        scanf("%d", &choice);
        getchar();

        // Read in review information from terminal where needed.
        if (choice == 1 || choice == 6 || choice == 7)
        {
            getItemName(name);
        }
        if (choice == 1 || choice == 6)
        {
            getItemDescription(description);
        }
        if (choice == 1)
        {
            getItemType(type);
        }
        if (choice == 1 || choice == 6 || choice == 7)
        {
            getItemRarity(&rarity);
        }
        if (choice == 1)
        {
            getItemAmount(&count);
        }

        if (choice == 1){
            inv_head = addItem(name, type, description, rarity, count, inv_head);
        }
        else if (choice == 2){
            printf("Enter the name of the item you are searching for:\n");
            fgets(name, MAX_STR_LEN, stdin);
            filteritembyname(name, inv_head);
        }
        else if (choice == 3){
            printf("Enter the description of the item you are searching for:\n");
            fgets(description, MAX_STR_LEN, stdin);
            filteritembydescription(description, inv_head);
        }
        else if (choice == 4){
            printf("Enter the type of the item you are searching for:\n");
            fgets(type, MAX_STR_LEN, stdin);
            filteritembytype(type, inv_head);
        }
        else if (choice == 5){
            printf("Enter the minimum rarity of the items you want to see:\n");
            scanf("%d", &rarity);
            getchar();
            filteritembyrarity(rarity, inv_head);
        }
        else if (choice == 6){
            updateItem(name, description, rarity, inv_head);
        }
        else if (choice == 7){
            inv_head = deleteItem(name, rarity, inv_head);
        }
        else if (choice == 8){
            printItems(inv_head);
        }
        else if (choice == 9){
            printf("Sorting items in alphabetical order:\n");
            inv_head = sortItemsByName(inv_head);
        }
        else if (choice == 10) break;
    }

    inv_head = deleteInventory(inv_head);
    printf("Done!\n");
    return 0;
}
