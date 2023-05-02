typedef 
	struct _tree_node {
		char * elem ;
		struct _tree_node * parent ;
		struct _tree_node * next ; // sibling
		struct _tree_node * child ; // head of the children linked list
	} 
	tree_node ;


tree_node * tree_alloc (char * s) ;
void tree_free (tree_node * t) ;

tree_node * tree_child_add (tree_node * parent, tree_node * child) ;


int tree_node_degree (tree_node * t) ;
int tree_degree (tree_node * t) ;
int tree_node_depth (tree_node * t) ;
int tree_height (tree_node * t) ;

int tree_contains (tree_node * t, char * s) ;

void tree_travel_preorder (tree_node * t, void (* node_op)(tree_node * n)) ;
void tree_travel_postorder (tree_node * t, void (* node_op)(tree_node * n)) ;

void tree_print (tree_node * t) ;

