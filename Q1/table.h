typedef enum BOOL { false, true } Boolean;

// Linked list node definition
typedef struct NODE Node;

struct NODE
{
  char *string;
  Node *next;
};
//***********************************
// Prototypes
//***********************************

//returns the number of the nodes in the tabel
int size();

//insert an item in the table
Boolean insert( char const * const new_string );

//delete an item from the table
Boolean delete( char const * const target );

//Search for an item in the table
Boolean search( char const * const target );

//returns the first item of the table
char * firstItem();

//gets the next node of the table
char * nextItem();