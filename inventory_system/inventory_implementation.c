#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

typedef struct item_struct{    
	char name[MAX_STR_LEN];
	char type[MAX_STR_LEN];
    char description[MAX_STR_LEN]; 
    int rarity; 
} Item_node;

typedef struct inventory_struct{
	int count; 
	Item_node item; 
    struct inventory_struct *next; 
} Inventory_node;

Inventory_node *newInventoryNode(){
    /*
     * This function allocates an empty item, and initializes the
     * contents of the item for this node to reasonable (uninitialized) values.
     * The fields in the item should be set to:
     *  name =""
     *  type =""
     *  description = ""
     *  count = 0
     *  rarity = 0
     *  *next = NULL;
     * 
     * The *next pointer for the new node MUST be set to NULL*/
    Inventory_node *newItem = NULL;
    newItem = (Inventory_node*)calloc(1, sizeof(Inventory_node));
    strcpy(newItem->item.name, "");
    strcpy(newItem->item.type, "");
    strcpy(newItem->item.description, "");
    newItem->item.rarity = 0;
    newItem->count = 0;
    newItem->next = NULL;
    return newItem; 
}

Inventory_node *addItem(char name[], char type[], char description[], int rarity, int amount, Inventory_node *head) {
    
    //check if the item already exists in the inventory, and increasing count by 1 if it does. There should only be one item with the same name & rarity.
    Inventory_node *p = NULL;
	p = head; 
	
	while (p != NULL){
		if ((strcmp(p->item.name, name)==0)&&(rarity == p->item.rarity)){
			p->count += amount; 
            return head; 
		}
		p=p->next;
	}
	
    //create new item for the inventory
    //if there are no items in the inventory yet
	Inventory_node *newItem = newInventoryNode();
	if (head==NULL){
        head = newItem;
		strcpy(head->item.name, name);
		strcpy(head->item.type, type);
        strcpy(head->item.description, description);
        head->item.rarity = rarity;
		head->count = amount;
		head->next = NULL; 		
		return head;
	}
	
    //adding new item to the beginning of the linked list if there are more than 1 items in the inventory already, returning the new head
	strcpy(newItem->item.name, name);
	strcpy(newItem->item.type, type);
    strcpy(newItem->item.description, description);
    newItem->item.rarity = rarity;
	newItem->count += amount;
	newItem->next = head;
	return newItem; 
}

void filteritembyname(char name[MAX_STR_LEN], Inventory_node *head){
    /*
     * This function searches through the linked list for a item that matches the description and prints the type, description, and name out. 
     * 
     * If no such review is found, this function prints "Sorry, no such item exists in your inventory"
     */
    Inventory_node *p = NULL;
	p = head; 
	
	while (p!=NULL){
		if ((strstr(p->item.name, name) != NULL)){
			printf("name: %s\n", p->item.name);
            printf("type: %s\n", p->item.type);
            printf("description: %s\n", p->item.description);
            printf("rarity: %d\n", p->item.rarity);
            printf("amount: %d\n", p->count);
            printf("*******************\n");
		p=p->next;
		}
	}
}

void filteritembydescription(char description[MAX_STR_LEN], Inventory_node *head){
    /*
     * This function searches through the linked list for a item that matches the description and prints the type, description, and name out. 
     * 
     * If no such review is found, this function prints "Sorry, no such item exists in your inventory"
     */
    Inventory_node *p = NULL;
	p = head; 
	
	while (p!=NULL){
		if ((strstr(p->item.description, description) != NULL)){
			printf("name: %s\n", p->item.name);
            printf("type: %s\n", p->item.type);
            printf("description: %s\n", p->item.description);
            printf("rarity: %d\n", p->item.rarity);
            printf("amount: %d\n", p->count);
            printf("*******************\n");
		}
		p=p->next;
	} 
}

void filteritembytype(char type[MAX_STR_LEN], Inventory_node *head){
    /*
     * This function searches through the linked list for a item that matches the type and prints the type, description, and name out. 
     * 
     * If no such review is found, this function prints "Sorry, no such item exists in your inventory"
     */
    Inventory_node *p = NULL;
	p = head; 
	
	while (p!=NULL){
		if ((strstr(p->item.type, type) != NULL)){
			printf("name: %s\n", p->item.name);
            printf("type: %s\n", p->item.type);
            printf("description: %s\n", p->item.description);
            printf("rarity: %d\n", p->item.rarity);
            printf("amount: %d\n", p->count);
            printf("*******************\n");
		}
		p=p->next;
	}
}

void filteritembyrarity(int rarity, Inventory_node *head){
    /*
     * This function searches through the linked list for a item that is equal or greater to the rarity
     * 
     * If no such review is found, this function prints "Sorry, no such item exists in your inventory"
     */
    Inventory_node *p = NULL;
	p = head; 
	
	while (p!=NULL){
		if (p->item.rarity >= rarity){
			printf("name: %s\n", p->item.name);
            printf("type: %s\n", p->item.type);
            printf("description: %s\n", p->item.description);
            printf("rarity: %d\n", p->item.rarity);
            printf("amount: %d\n", p->count);
            printf("*******************\n");
		}
		p=p->next;
	}
}


int countitems(Inventory_node *head){
    //This function returns the number of items.
    
	int counter = 0;
	Inventory_node *p = NULL;
	p = head; 
	
	while (p!=NULL){
		counter=counter+1;
		p=p->next;
	}
	return counter; 
}

void updateItem(char name[MAX_STR_LEN], char description[MAX_STR_LEN], int rarity, Inventory_node *head){
    /*
     * This function looks for a review matching the name.
     * If such a review is found, then the function updates the description.
     * If no such review is found, the function prints out "Sorry, no such item exists in your inventory"
     */
	Inventory_node *p = NULL;
	p = head; 
	
	while (p!=NULL){
		if ((strcmp(p->item.name, name)==0)&&(rarity == p->item.rarity)){
			strcpy(p->item.description, description);
			break; 
		}
		p=p->next;
	}
	if (p==NULL){
		printf("Sorry, no such movie exists in the database");
	}
}

Inventory_node *deleteItem(char name[MAX_STR_LEN], int rarity, Inventory_node *head){
    /*
     * This function removes a item matching the input from the database. If no such review can
     * be found, it does nothing.
     * 
     * The function returns a pointer to the head of the linked list (which may have changed as a result
     * of the deletion process)
     */
    Inventory_node *tr = NULL; 
	Inventory_node *pre = NULL;

    //if the inventory is empty
	if (head == NULL) return NULL; 
	
    //if the item to be deleted is the head of the linked list
	pre = head; 
	tr = head -> next; 
	if ((strcmp(pre->item.name, name)==0)&&(rarity == pre->item.rarity)){
		free(pre);
		return tr; //new head  
	}
	
    //else
	while(tr!=NULL){
		if ((strcmp(pre->item.name, name)==0)){
			pre->next = tr->next;
			free(tr); 
			break;
		}
		tr=tr->next;
		pre=pre->next;
	}
    return head;
}

float printItems(Inventory_node *head){
    /*
     * This function prints out all the items in the database, one after another, and then return the total number of items in the inventory at the end. 
     * Each field in the item is printed in a separate line, with *no additional text*
     * (that means, the only thing printed is the value of the corresponding field).
     * 
     * Reviews are separated from each other by a line of
     * "*******************"
     */
    Inventory_node *p = NULL;
	p = head;
	float item_tot=0; 
	
	while (p!=NULL){
		item_tot += p->count;
		printf("name: %s\n", p->item.name);
		printf("type: %s\n", p->item.type);
        printf("description: %s\n", p->item.description);
		printf("rarity: %d\n", p->item.rarity);
		printf("amount: %d\n", p->count);
		printf("*******************\n");
		p=p->next;
	}
	return item_tot;
}

Inventory_node *deleteInventory(Inventory_node *head)
{
  /*
   * This function deletes the movie review database, releasing all the
   * memory allocated to the nodes in the linked list.
   * 
   * Returns a NULL pointer so that the head of the list can be set to NULL
   * after deletion.
   */
      
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/    
	Inventory_node *p=NULL; 
	Inventory_node *q=NULL; 
	
	if (head==NULL){
		return head; 
	}
	
	p=head->next; 
	
	while(p!=NULL){
		q=p->next; 
		free(p);
		p=q;
	}
    
	head = NULL; 
    return head;
}

Inventory_node *sortItemsByName(Inventory_node *head)
{
  /*
   * This function sorts the list of items in alphabetical order. If duplicate named items exist, the higher rarity one goes first. 
   * 
   * Returns a pointer to the head node of the sorted list.
   */
	Inventory_node *one = NULL; 
	Inventory_node *two = NULL; 
	char item1[MAX_STR_LEN]; 
	char item2[MAX_STR_LEN]; 
	char item3[MAX_STR_LEN];
	
	one = head; 
	//empty
	if (one==NULL){
		return head; 
	}
	//one entry
	two = one->next; 
	if (two==NULL){
		return head; 
	}
	//multiple
	while (two!=NULL){
		strcpy(item1, one->item.name); 
		strcpy(item2, two->item.name); 
		
		if (strcmp(item1,item2)>0){
			Inventory_node *p = NULL;
			p = head;
				
			//if item2 is first in order
			strcpy(item3, p->item.name);
			if (strcmp(item3,item2)>0){
				one->next = two->next; 
				two->next = p; 
				head = two;
				break;
			}
			
			while (p!=two){
				strcpy(item3, p->item.name);
				if (strcmp(item3,item2)>0){
					one->next = two->next; 
					two->next = p->next; 
					p->next = two; 
					break;
				}
				if (p->next==two){
					break;
				}
				p = p->next; 
			}
		}
		one = two; 
		two = two->next; 
	}
    return head;
}