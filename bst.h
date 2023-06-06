typedef int Key ;
typedef char * Value ;

class Node {
	private:
		Key k ;
		Value v ;

		Node * parent ;
		Node * left ;
		Node * right ;

		void print (int indent) ;

		friend class BST ;

	public:
		Node (): k(), v(), parent(NULL), left(NULL), right(NULL) { }
		Node (Key k, Value v) ;
		~Node () {} 

		bool addLeft (Node * n) ;
		bool addRight (Node * n) ;

		bool isInternal () ;
} ;

class BST {
	private:
		Node * root ;
		int nNodes ;

	public:
		BST (): root(NULL), nNodes(0) { }
		~BST () ;


		Value find (Key k) ;
		bool erase (Key k) ;
		bool insert (Key k, Value v) ;

		void print () ;
} ;
