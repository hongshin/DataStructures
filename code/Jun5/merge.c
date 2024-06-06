
int * merge (int * a, int n_a, int * b, int n_b)
{
		int * c = malloc((n_a + n_b) * sizeof(int)) ;

		int i ;
		int n_c = n_a + n_b ;
		
		int top_a = 0 ;
		int top_b = 0 ;

		for (i = 0 ; i < n_c ; i++) {
			//c[i] = ??
			//     if (top of remaining a < top of remaining b)
			//			c[i] = top of remaining a 
			//		else
			//			c[i] = top of remaining b

			if (top_b == n_b || (top_a < n_a && a[top_a] < b[top_b])) {
				c[i] = a[top_a] ;
				top_a++ ;
			}
			else /* b[top_b] < a[top_a] */ {
				c[i] = b[top_b] ;
				top_b++ ;
			}
		}


		return c ;
}
