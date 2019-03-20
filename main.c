#include "workbench.h"
#include <unistd.h>

int main(int argc, char *argv[])
{

	init();
	Note *head = getNotes();
	char opt;
	char outputfmt[5];

	unsigned int ID;
	char cmd[100];

	Note *context;

	while((opt = getopt(argc, argv, "n:ldief:p")) != -1){
		switch (opt) {
			case 'n':
				newNote(head, optarg);
				writeNotes(head);
				sprintf(cmd, "$EDITOR %s.md", optarg);
				system(cmd);
				break;

			case 'l':
				listNotes(head);
				break;
			
			case 'd':
				listNotes(head);
				printf("\nEnter ID to delete: ");
				scanf("%u", &ID);
				if(ID < 1) break;
				delNote(head, ID);
				writeNotes(head);
				break;

			case 'e':
				listNotes(head);
				printf("\nEnter ID to edit: ");
				scanf("%u", &ID);
				if(ID < 1) break;
				context = getNoteByID(head, ID);
				sprintf(cmd, "$EDITOR %s.md", context->title);
				system(cmd);
				break;

			case 'f':
				if(strcmp(optarg, "html") == 0){
					sprintf(outputfmt, "html");
				}
				else if(strcmp(optarg, "pdf")==0){
					sprintf(outputfmt, "pdf");
				}
				else break;
				break;

			case 'p':
				listNotes(head);
				printf("\nEnter ID to publish: ");
				scanf("%u", &ID);
				if(ID < 1) break;
				context = getNoteByID(head, ID);
				sprintf(cmd, "pandoc -s %s.md -o %s.%s", context->title, context->title, outputfmt);
				system(cmd);
				break;

			default:
				printf("Exiting, nothing to do...\n");
				return 1;
				
		}
	}

	return 0;
}
