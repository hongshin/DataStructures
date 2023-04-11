class FibonacciProgression : public Progression
{
	public:
		FibonacciProgression (long f = 0, long s = 1) ;
		void printProgression (int n) ;

	protected:
		virtual long firstValue () ;
		virtual long nextValue () ;

		long second ;
		long prev ;
} ;
