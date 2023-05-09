typedef int Elem ;

class Node {
	private:
		Elem elem ;

		Node * parent ;
		Node * left ;
		Node * right ;

		friend class Tree ;

	public:
		Node (): elem(), parent(NULL), left(NULL), right(NULL) { }
		Node (Elem e) ;
		~Node () ;

		bool addLeft (Node * n) ;
		bool addRight (Node * n) ;
		bool isAncestor (Node * n) ;
		bool isDescendant (Node * n) ;
} ;

class Tree {
	private:
		Node * root ;

		//FIXME

	public:
		Tree (): root(NULL) { }
		Tree (Node * n) ;
		~Tree () ;

		bool isValid () ;
		bool isProper () ;
		bool isFull () ;
		bool isComplete () ;

		int height () ;
		int numNodes () ;
} ;
