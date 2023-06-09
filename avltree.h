typedef int Key ;
typedef char * Value ;

class Node {
	private:
		Key k ;
		Value v ;

		Node * parent ;
		Node * left ;
		Node * right ;

		int height ;

		void print (int indent) ;

		friend class AVLTree ;

	public:
		Node (): k(), v(), parent(NULL), left(NULL), right(NULL), height(0) { }
		Node (Key k, Value v) ;
		~Node () {} 

		bool addLeft (Node * n) ;
		bool addRight (Node * n) ;

		bool isInternal () ;
} ;

class AVLTree {
	private:
		Node * root ;
		void restructure (Node * z, Node * a, Node * b, Node * c, Node * T0, Node * T1, Node * T2, Node * T3) ;

	public:
		AVLTree (): root(NULL) { }
		~AVLTree () ;

		Value find (Key k) ;
		bool erase (Key k) ;
		bool insert (Key k, Value v) ;


		void print () ;
} ;
