/**
Final Assignment using Stack, Queue and Tree
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

// player Structure
struct player 
{
	int playerRank;
	char playerName[30];
	float playerAverage;
	struct player *nextPtr;
};
typedef struct player Player;
typedef Player *playerPtr;

// Team Structure
struct team
{
	int teamPoistion;
	char teamName[30];
	float teamPts;
	struct team *nextPtr;
};
typedef struct team Team;
typedef Team *teamPtr;

// Tree Structure
struct treeNode { 
   struct treeNode *leftPtr; // pointer to left subtree
	int playerRank;
	char playerName[30];
	float playerAverage;
   struct treeNode *rightPtr; // pointer to right subtree 
};
typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

//Function Prototypes for Trees
void insertNode(TreeNodePtr *treePtr, int value ,char name[30], float average);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);
void deleteNodeTree (TreeNodePtr *treePtr, int value);
void searchNodeTree (TreeNodePtr *treePtr, int value, TreeNodePtr *parentPtr, TreeNodePtr *tempNodePtr, int *found);
void printNodeTree(TreeNodePtr treePtr);

// Function Prototypes for Stacks
void push(playerPtr *topPtr, int rank, char name[30], float average); 
void pop(playerPtr *topPtr);
void printStack(playerPtr currentPtr);
void printTopStack(playerPtr currentPtr);

// Function Prototypes for Queues
void enqueue(teamPtr *headPtr, teamPtr *tailPtr, int positon, char name[30], float points);
void dequeue(teamPtr *headPtr, teamPtr *tailPtr);
void printQueue(teamPtr currentPtr);
void printHeadQueue(teamPtr currentPtr);
void printTailQueue(teamPtr currentPtr);

// Other Important Function Prototypes
void defaultInstructions(void);
void stackInstructions(void);
void queuesInstructions(void);
void treesInstructions(void);
int isStackEmpty(playerPtr topPtr);
int isQueueEmpty(teamPtr headPtr);
int choice;



// Main Menu With all user interaction
int main(void) 
{
	// Variables for pointers to Team and player structures
    teamPtr head = NULL, tail = NULL; // Pointer Varaibles to head and tail of Queue.
    playerPtr top = NULL; //Pointer that points to top of the Structure
    TreeNodePtr rootPtr = NULL;   
    int item; /* random value to insert in tree */

    // Variables for Players
    int id = 0;
    char name[30];
    float average;

    // Variables for Teams
    int position = 0;
    char teamName[30];
    float points;

    bool ranking = FALSE;
    bool isnotchar = FALSE;

    defaultInstructions();

    while(choice != 4) // Starting Main Menu 
    {
    	switch(choice) // User Selects Menu Item
    	{
			case 1: // printing top values of the stack
			printf("\n Entering Player Menu.....\n\n\n");
			stackInstructions();
			while(choice != 5) 
			{
				switch(choice) 
				{
				case 1: // Printing Player from top of the stack
					printTopStack(top);
					break;
				case 2: // Add a New player to the stack
					id++;
					printf("\n");
					printf("\n Enter Player Name: ");
					scanf(" %s", name);
					printf("\n Enter Player Average: ");
					scanf("%f", &average);
					push(&top, id, name, average);
					printStack(top);
					break;
				case 3:
					if(!isStackEmpty(top)) 
					{
						printf("The Player removed is\n");
						pop(&top);
					}
					printStack(top);
					break;
				case 4:
					printStack(top);
					break;
				default:
					printf("Invalid choice.\nPlease select the correct menu item\n\n");
					stackInstructions();
					break;
				}
			stackInstructions();
			}
//			printf("Enter Menu Item: ");
			//return 0;
			break;
		case 2: 
			printf("\nEntering Team Menu...\n\n\n");
			queuesInstructions();
			while(choice != 6)
			{
				switch(choice)
				{
					case 1: // Print team in head of queue
						printHeadQueue(head);
						break;
					case 2: // Print team in tail of queue
						printTailQueue(head);
						break;
					case 3: // Add Team to the tail of the queue, using enqueue
						position++;
						printf("\n");
						printf("\n Enter Team Name: ");
						scanf(" %s", name);
						printf("\n Enter Team Overall Points: ");
						scanf("%f", &average);
						enqueue(&head, &tail, position, name, average); //pass user input and place in the tail of the Queue
						printQueue(head);
						break;
					case 4: // Delete First Team entered in the queue
						if(!isQueueEmpty(head)) // Queue is NOT empty
						{
							dequeue(&head, &tail);
						}
						else // Queue IS empty
						{
							printf("No Team Data exisits\n\n");
						}
						break;
					case 5: // Print List of Entire Team
						printQueue(head);
						break;
					default:
						printf("Invalid choice.\nPlease Select the correct menu item\n\n");
						queuesInstructions();
						break;
				}// end switch
				queuesInstructions();
			}// end while loop
	
//			printf("Enter Menu Item: ");
			//return 0;
			break;
		case 3:
			printf("Your Programm is Running Using Tree");
			treesInstructions();
			while(choice != 6)
			{
				switch(choice)
				{
					case 1: // Add Player Leaf to the Tree
						printf("Enter the Rank of Player: ");
						scanf("%d",&id);
						printf("\n Enter Player Name: ");
						scanf(" %s", name);
						printf("\n Enter Player average: ");
						scanf("%f", &average);
						insertNode(&rootPtr,id,name,average); //pass user input and place in the tail of the Queue
						printNodeTree(rootPtr);
						break;
					case 2: // Delete a Player Leaf from the Tree
						printf("\n Enter an Item-Key to be deleted: ");
						scanf("%d",&item);
						deleteNodeTree(&rootPtr,item);
						break;
					case 3: // Pre Order Traversal Through Rank
						printf("The values in Pre-Order Traversal");
						puts("\npre-Order traversal");   
						preOrder(rootPtr);
						break;
					case 4: // Post Order Traversal Through Rank
						printf("The values in Post-Order Traversal");
						puts("\npost-Order traversal");  
						postOrder(rootPtr); 
						break;
					case 5: // In Order Traversal Through Rank
						printf("The values in In-Order Traversal");
						puts("\nIn-Order traversal");   
						inOrder(rootPtr);
						break;
					default:
						printf("Invalid choice.\nPlease Select the correct menu item\n\n");
						treesInstructions();
						break;
				}// end switch
				treesInstructions();
			}// end while loop
	//		printf("Enter Menu Item: ");
			//return 0;
			break;
		default:
			printf("\nInvalid choice.\nPlease select correct menu item\n\n");
			defaultInstructions();
			break;
		}// end switch
		defaultInstructions();
	} // end while
	//sprintf("Enter Menu Item: ");
	return 0;
}// End Main



// defaultInstruction is a void functions that will print the Main Menu
void defaultInstructions(void)
{
	printf("\n\nEnter Option:\n 1.): Go To Player Menu.  \n 2.): Go to Team Menu. \n 3.): Go To Player Menu(V2.0).\n 4.): Exit Application\n\n\n");
	printf("Enter Choice: ");
	scanf("%d", &choice);		
} // end defaultInstructions

// stackInstructions is a void function that will print Player Menu
void stackInstructions(void)
{
	printf("Enter Option:\n 1.): See The Top Rank of Players  \n 2.): Enter Player Name and average .\n 3.): Delete the last player added to the Stack.\n 4.): See All The Top Player List \n 5.): Back to Main Menu.\n");
	printf("Enter Choice: ");
	scanf("%d", &choice);
} // end stackInstructions

// queuesInstructions is a void function that will print Team Menu
void queuesInstructions(void)
{
	printf("\n\nEnter Option:\n 1.): View First Team Inserted.  \n 2.): View Last Team Inserted. \n 3.): Add a Team to the end of the list.\n 4.): Remove Team from end of list. \n 5.): Print List of Teams\n 6.): Back to Main Menu.\n\n\n");
	printf("Enter Choice: ");
	scanf("%d", &choice);	
} // end queuesInstructions

// Void Function that prints the menu for Tree Structure
void treesInstructions(void) 
{
	printf("\n 1.): Add Player into Tree. \n 2.): Remove select player. \n 3.): Pre-order of players. \n 4.): Post-order of players. \n 5.): In-order of players. \n 6.): Back to Main Menu.\n\n\n");
	printf("Enter Choice: ");
	scanf("%d", &choice);
}// end instructions

// Void isQueueEmpty funtion that checks if the queue is empty
int isQueueEmpty(teamPtr headPtr)
{
	return headPtr == NULL;
} // end isQueueEmpty

// Void isStackEmpty funtion that checks if the stack is empty
int isStackEmpty(playerPtr topPtr)
{
	return topPtr == NULL;
} // end isStackEmpty







//Functions for Stacks
// void push function that adds player information inside the stack
void push(playerPtr *topPtr, int rank, char name[30], float average) 
{
	playerPtr newPtr;
	newPtr = (playerPtr)malloc(sizeof(Player));
	if(newPtr != NULL) 
	{
		newPtr->playerRank = rank;
		strcpy(newPtr->playerName,name);
		newPtr->playerAverage = average;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	} // end if 
	else 
	{
		printf("%d not inserted. No memory available.\n", rank);
	} // end else
} // end push

//integer pop funtion that removes the last player inserted
void pop(playerPtr *topPtr) 
{
	int popValue;
	char nameValue[30];
	float averageValue;
	playerPtr tempPtr;

	tempPtr = *topPtr;
	popValue = (*topPtr)->playerRank;
	strcpy(nameValue,(*topPtr)->playerName);
	averageValue = (*topPtr)->playerAverage;
	*topPtr = (*topPtr)->nextPtr;
	printf("Removed Player:\n\nPlayer Rank: %d Player Name: %s Player Average: %f \n", popValue, nameValue, averageValue);
	free(tempPtr);
} // end pop

// void printStack function that prints the entire stack
void printStack(playerPtr currentPtr)
 {
	if(currentPtr == NULL) 
	{
		printf("The list of players is empty.\n\n");
	} // end if
	else 
	{
		printf("The list of players are is:\n");
		while(currentPtr != NULL) 
		{
			printf("%d --> ", currentPtr->playerRank);
			printf("Player ID: %d   Name: %s   Player Average: %f \n", currentPtr->playerRank, &currentPtr->playerName, currentPtr->playerAverage);
			currentPtr = currentPtr->nextPtr;
		} // end while
		printf("\n\n");
	} // end else
} // end printStack

// void printTopStack function that will print the player in the top of the stack
void printTopStack(playerPtr currentPtr)
{
	if(currentPtr == NULL) 
	{
		printf("The list of players is empty.\n\n");
	} // end if 
	else 
	{
		printf("The list of players are is:\n");
		printf("%d --> ", currentPtr->playerRank);
		printf("Player ID: %d   Name: %s   Player Average: %f \n", currentPtr->playerRank, &currentPtr->playerName, currentPtr->playerAverage);
		currentPtr = currentPtr->nextPtr;
		printf("\n\n");
	} // end else
} // end printTopStack







// Functions for Queues
// void enqueue function that adds a team into the queue
void enqueue(teamPtr *headPtr, teamPtr *tailPtr, int positon, char name[30], float points)
{
	teamPtr newPtr = (teamPtr)malloc(sizeof(Team)); 
	
	if(newPtr != NULL)
	{
		newPtr->teamPoistion = positon;
		strcpy(newPtr->teamName,name);
		newPtr->teamPts = points;
		newPtr->nextPtr = NULL;
		//*topPtr = newPtr;

		if(isQueueEmpty(*headPtr)) // Queue is Empty
		{
			*headPtr = newPtr;
		} // end if
		else //Queue is not Empty
		{
			(*tailPtr)->nextPtr = newPtr;
		} // end else
		*tailPtr = newPtr; // insert to end of node
	} // end if
	else
	{
		printf("%d not inserted. No memory available.\n", positon);
	} // end else
}// end enqueue

// Void Function that Removes node from head, and frees memeory space
void dequeue(teamPtr *headPtr, teamPtr *tailPtr)
{
	int positonValue;
	char nameValue[30];
	float pointsValue;
	teamPtr tempPtr;
	
	positonValue = (*headPtr)->teamPoistion;
	strcpy(nameValue,(*headPtr)->teamName);
	pointsValue = (*headPtr)->teamPts;
	tempPtr = *headPtr;
	*headPtr=(*headPtr)->nextPtr;
	
	if(*headPtr == NULL)
	{
		*tailPtr == NULL;
	}// end if
	printf("Removed Team:\n\nTeam ID: %d Team Name: %s Team Points: %f \n", positonValue, nameValue, pointsValue);
	free(tempPtr);
}// end dequeue

// void printQueue function that prints the list of teams
void printQueue(teamPtr currentPtr)
{
	if(currentPtr == NULL) // Queue is Empty
	{
		printf("No Team Data exisits\n\n");	
	} // end if
	else
	{
		printf("The Teams are: \n");
		while(currentPtr != NULL)
		{
			printf("--> Position: %d Name: %s   Points: %.2f \n", currentPtr->teamPoistion, &currentPtr->teamName, currentPtr->teamPts);
			currentPtr = currentPtr->nextPtr;
		} // end while
		printf( "NULL\n" );
	} // end else
} // end printQueue


// void printHead function that trints the first player in the queue 
void printHeadQueue(teamPtr currentPtr)
{
	if(currentPtr == NULL) // Queue is Empty
	{
		printf("No Team Data exisits\n\n");	
	} // end if
	else
	{
		//printf("The Team are: \n");
		printf("--> Position: %d Name: %s   Points: %.2f \n", currentPtr->teamPoistion, &currentPtr->teamName, currentPtr->teamPts);
		printf( "NULL\n" );
	} // end else
} // end printQueue


// void printTail function that displays the last player in the queue
void printTailQueue(teamPtr currentPtr)
{
	if(currentPtr == NULL) // Queue is Empty
	{
		printf("No Team Data exisits\n\n");	
	} // end if
	else
	{
		playerPtr currentPtrtmp;
		//printf("The players are: \n");
		while(currentPtr != NULL)
		{
			currentPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		} // end while
		printf("--> Position: %d Name: %s   Points: %.2f \n", currentPtr->teamPoistion, &currentPtr->teamName, currentPtr->teamPts);
		printf( "NULL\n" );
	} // end else
}






// Tree Functions
// void function that inserts player leaf inside the tree structure
void insertNode(TreeNodePtr *treePtr, int value ,char name[30], float average)
{ 
	if (!*treePtr) // Tree is NULL
	{ 
		*treePtr = (TreeNodePtr)malloc(sizeof(TreeNode)); // dynamically allocate memory
		if ( *treePtr ) // if memory was allocated, insert node 
		{ 
			( *treePtr )->playerRank = value;
			strcpy(( *treePtr )->playerName,name);
			( *treePtr )->playerAverage = average;
			( *treePtr )->leftPtr = NULL;
			( *treePtr )->rightPtr = NULL;
      	} // end if
		else
		{
			printf( "%d not inserted. No memory available.\n", value );
    	} // end else
	return; 
   	} // end if
	else // recursively call insertNode
    { 
		if ( value < ( *treePtr )->playerRank ) // insert node in left subtree
		{
			insertNode( &( ( *treePtr )->leftPtr ), value,name,average );
		}// end if
		else if (value > ( *treePtr )->playerRank ) // insert node in right subtree
		{  
	    	insertNode( &( ( *treePtr )->rightPtr ), value ,name,average);
		}// end else
		else // duplicate value
		{ 
			printf("-duplicate");  
		}   
   	} // end else
} // end function insertNode

// traverse the tree inorder
void inOrder(TreeNodePtr treePtr)
{ 
	if (treePtr) //traverse left subtree, print node, traverse right subtree
	{ 
		inOrder( treePtr->leftPtr );
		printf( "\n Id :%3d \n", treePtr->playerRank );
		printf( "Name %s\n", treePtr->playerName );
		printf( "Average %f \n", treePtr->playerAverage );
		inOrder( treePtr->rightPtr );
   	}// end if 
} // end function inOrder

// traverse the tree preorder
void preOrder(TreeNodePtr treePtr)
{ 
	if (treePtr) // print node, traverse left subtree, traverse right subtree
	{ 
		printf( "\n Id :%3d \n", treePtr->playerRank );
		printf( "Name %s\n", treePtr->playerName );
		printf( "Average %f \n", treePtr->playerAverage );
		preOrder( treePtr->leftPtr );
		preOrder( treePtr->rightPtr );
   } // end if
} // end function preOrder

// traverse the tree postorder
void postOrder( TreeNodePtr treePtr )
{ 
	if (treePtr) // traverse left subtree, traverse right subtree, print node
	{ 
		postOrder( treePtr->leftPtr );
		postOrder( treePtr->rightPtr );
		printf( "\n Id :%3d \n", treePtr->playerRank );
		printf( "Name %s\n", treePtr->playerName );
		printf( "Average %f \n", treePtr->playerAverage );
   } // end if
} // end function postOrder



/* deletes a node from the binary search tree */
void deleteNodeTree (TreeNodePtr *treePtr, int value)
{
	int found ;
	TreeNodePtr parentPtr, tempNodePtr, replacementNodePtr ;
	if ( *treePtr == NULL ) // if tree is empty
	{
		printf ("\nTree is empty");
		return;
	} // end if
	parentPtr = NULL ;
	tempNodePtr = NULL;

	searchNodeTree (treePtr, value, &parentPtr, &tempNodePtr, &found); // find the node to be deleted
	if (found == FALSE) // if the node is not found
	{
		printf ("\n Data not found");
		return;
	} // end if
	if (tempNodePtr -> leftPtr != NULL && tempNodePtr -> rightPtr != NULL) // if the node to be deleted has two children
	{
		parentPtr = tempNodePtr ;
		replacementNodePtr = tempNodePtr -> rightPtr ;
		while ( replacementNodePtr -> leftPtr != NULL )
		{
			parentPtr = replacementNodePtr ;
			replacementNodePtr = replacementNodePtr->leftPtr ;
		} // end while
		printf("\n The Record Deleted is : ");
		printf( "\n Id :%3d \n", tempNodePtr->playerRank );
		printf( "Name %s\n", tempNodePtr->playerName );
		printf( "Average %f \n", tempNodePtr->playerAverage );
		tempNodePtr->playerRank = replacementNodePtr->playerRank;     
		tempNodePtr = replacementNodePtr;
		return;
	} // end if
	if (tempNodePtr->leftPtr == NULL && tempNodePtr->rightPtr == NULL ) // if the node to be deleted has no child */
	{
		if ( parentPtr -> rightPtr == tempNodePtr )
			parentPtr -> rightPtr = NULL ;
		else
			parentPtr -> leftPtr = NULL ;
		printf("\n The Record Deleted is :");
		printf("\n Id :%3d \n", tempNodePtr->playerRank );
		printf("Name %s\n", tempNodePtr->playerName );
		printf("Average %f \n", tempNodePtr->playerAverage );
		free(tempNodePtr);
		return;
	} // end if
	if (tempNodePtr->leftPtr == NULL && tempNodePtr->rightPtr != NULL) // if the node to be deleted has only rightPtr
	{
		if (parentPtr->leftPtr == tempNodePtr)
			parentPtr->leftPtr = tempNodePtr -> rightPtr;
		else
			parentPtr->rightPtr = tempNodePtr->rightPtr;
		printf("\n The Record Deleted is : ");
		printf( "\n Id :%3d \n", tempNodePtr->playerRank );
		printf( "Name %s\n", tempNodePtr->playerName );
		printf( "Average %f \n", tempNodePtr->playerAverage );
		free (tempNodePtr);
		return;
	} // end if
	if (tempNodePtr->leftPtr != NULL && tempNodePtr->rightPtr == NULL) // if the node to be deleted has only left child
	{
		if (parentPtr->leftPtr == tempNodePtr)
			parentPtr->leftPtr = tempNodePtr->leftPtr;
		else
			parentPtr->rightPtr = tempNodePtr->leftPtr;
		printf("\n The Record Deleted is : ");
		printf( "\n Id :%3d \n", tempNodePtr->playerRank );
		printf( "Name %s\n", tempNodePtr->playerName );
		printf( "Average %f \n", tempNodePtr->playerAverage );
		free(tempNodePtr);
		return;
	} // end if 
} // end deleteNodeTree

// Void function that searches for specific player from the tree
void searchNodeTree (TreeNodePtr *treePtr, int value, TreeNodePtr *parentPtr, TreeNodePtr *tempNodePtr, int *found)
{
	TreeNodePtr tempPtr;
	tempPtr = *treePtr;
	*found = FALSE;
	*parentPtr = NULL;		
	while(tempPtr != NULL)
	{
		if(tempPtr->playerRank == value)
		{
			*found = TRUE;
			*tempNodePtr = tempPtr;
			return;
		} // end if
		*parentPtr = tempPtr;
		if (tempPtr->playerRank > value)
			tempPtr = tempPtr->leftPtr;
		else
			tempPtr = tempPtr->rightPtr;
	} // end while
} // end searchNodeTree

// void function that will print a specific Player from the Tree
void printNodeTree(TreeNodePtr treePtr)
{ 
	if (treePtr) // traverse left subtree, print node, traverse right subtree
	{ 
		printNodeTree(treePtr->leftPtr);
		printf( "\n Id :%3d \n", treePtr->playerRank );
		printf( "Name %s\n", treePtr->playerName );
		printf( "Average %f \n", treePtr->playerAverage );
		printNodeTree(treePtr->rightPtr);
   } // end if 
} // end printNodeTree

