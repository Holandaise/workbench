#include "workbench.h"

void init(void){

	FILE *fh = fopen(DATA_FILE, "rb");

	if(fh == NULL){

		fh = fopen(DATA_FILE, "wb");

		char title[20];

		printf("Initializing workbench in current directory\n");
		printf("Please enter a title for your first file: ");
		scanf("%s", title);

		Note *head = malloc(sizeof(Note));
		head->next = NULL;
		head->noteID = 1;
		strncpy(head->title, title, 20);

		fwrite(head, sizeof(Note), 1, fh);
	}

	fclose(fh);
}

void newNote(Note *head, char *title){

	Note *nt = malloc(sizeof(Note));
	strncpy(nt->title, title, TITLE_MAX);
	unsigned int ID;
	nt->next = NULL;

	while(head->next != NULL){
		head = head->next;
	}

	ID = head->noteID;
	nt->noteID = ID + 1;
	head->next = nt;

}


void publish(Note *n){}



void listNotes(Note *head)
{
	printf("ID\tTitle\n");

	while(head->next != NULL){
		printf("%3d\t%s\n", head->noteID, head->title);
		head = head->next;
	}
	printf("%3d\t%s\n", head->noteID, head->title);
}


Note *getNoteByID(Note *head, unsigned int ID){
	while(head->noteID != ID){
		head = head->next;
	}

	return head;
}



Note *getNotes(void){

	FILE *fh = fopen(DATA_FILE, "rb");

	Note *temp = malloc(sizeof(Note));
	Note *head, *temp2;
	head = temp;

	while(fread(temp, sizeof(Note), 1, fh)){
		temp->next = malloc(sizeof(Note));
		temp2 = temp;
		temp = temp->next;
	}

	temp2->next = NULL;

	fclose(fh);

	return head;
}


void writeNotes(Note *head){

	FILE *fh = fopen(DATA_FILE, "wb");

	while(head->next != NULL){
		fwrite(head, sizeof(Note), 1, fh);
		head = head->next;
	}

	fwrite(head, sizeof(Note), 1, fh);

	fclose(fh);
}


void delNote(Note *head, unsigned int ID){

	Note *temp;

	while(head->noteID != ID){
		temp = head;
		head = head->next;
	}
	temp->next = head->next;
}

void cleanup(Note *head){

	Note *temp;
	while(head){
		temp = head->next;
		free(head);
		head = temp;
	}
}

