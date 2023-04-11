class Progression {
	public:
		Progression (long f = 0) : first(f), cur(f) { }
		virtual ~Progression() { } ;
		virtual void printProgression (int n) ;

	protected:
		virtual long firstValue () ;
		virtual long nextValue () ;

		long first ;
		long cur ;
} ;
