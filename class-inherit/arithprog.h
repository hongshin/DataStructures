class ArithProgression : public Progression 
{
	public:
		ArithProgression (long i = 1) ;

	protected:
		virtual long nextValue () ;
		long inc ;
} ;
