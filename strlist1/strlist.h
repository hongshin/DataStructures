class StrListNode {
	private:
		char * elem ; 
		StrListNode * prev ;
		StrListNode * next ;

		void print () ;

		friend class StrList ;
		friend std::ostream& operator<<(std::ostream&, const StrListNode&) ;

	public:
		StrListNode () ;
		StrListNode (const char * elem) ;
		~StrListNode () ;
} ;

class StrList {
	private:
		StrListNode head ;
		StrListNode tail ;
		int length ;
		
	
	public:
		StrList() ;
		~StrList() ;

		int addFirst (const char * s) ;
		int addLast (const char * s) ;

		int removeFirst (char * &s) ;
		int removeLast (char * &s) ;

		void print () ;
} ;
