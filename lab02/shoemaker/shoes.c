#include <stdio.h>
#include <stdlib.h>
#include <math.h>


long long  a[101];
long long  b[101];
long A[101];
long B[101];
long long as[101];
long long bs[101];

int L,R;

long long LCS[101][101];

int asearch(long long i){

	int low = 0;
	int up  = L;
	int mid;

	while( low < up) {	

		mid = ( low + up ) / 2;
		
		if ( as[mid] < i) {
			low = mid + 1;
		}
		else   {
			up = mid;
		}
	}
	return low;

}

int xsearch(long long i){

	int low = 0;
	int up  = R;
	int mid;

	while( low < up) {	

		mid = ( low + up ) / 2;
		
		if ( bs[mid] < i) {
			low = mid + 1;
		}
		else   {
			up = mid;
		}
	}
	return low;

}


long long Sol( long long i, long long j) {

	int i0,j0,k=0;
	long long d, dx , dy, l ,r,noroute, enroute = 0;
	
	if (i * j == 0) return 0; //
	
	i0 = asearch(i);
	j0 = xsearch(j);	
	
	// d <- min{ i - as[i0 - 1] , j - bs[j0 - 1] }
	
	dx = i - as[i0 - 1];
	dy = j - bs[j0 - 1];
	
	d = dx;
	if ( dy < d ) d = dy;
	
	l = i - d;
	r = j - d;
	
	//
	// 1. petaw ta perisseuoumena papoutsia aka noroute
	noroute = d + LCS [i0-1][j0-1];
	
	// 2. ta krataw kai kanw ti "diadromi" aka enroute
	
	//printf("**Sol(%lld,%lld) - B0 = [%d,%d] - (l,r) = (%lld,%lld)\n",i,j, i0,j0, l,r );
	
	if ( dx == dy )// isia 
	{
		enroute = noroute;
	}
	else if ( dx > dy ) {
		for ( k = j0 - 1; k > 0 ; k --) {
			if ( B[k] == A[i0] ) {
	
	//printf(" *** HIT AT BLOCK[%d,%d] // ST=(%lld,%lld)\n",i0,k,l,bs[k]);
	
				enroute = d + Sol(l , bs[k]); 
			
			break;
			}
		}
	}
	else {
		for ( k = i0 - 1; k > 0 ; k --) {
			if ( A[k] == B[j0] ) {
			
	//printf(" *** HIT AT BLOCK[%d,%d] // ST=(%lld,%lld)\n",k,j0,as[k], r );		
			
				enroute = d + Sol(as[k] , r);
			
			break;
			}
		}
	}
	
	if ( noroute > enroute ) {
		//
		return noroute;
	}
	else {
		return enroute;
	}
	
}


int main() {
	
	int i,j;

	long long tmp1,tmp2;
	
	// ----------- INPUT -------------
	if (scanf("%d %d", &L, &R) == 0) 
		return -1;
	
	as[0] = 0;
	for (i = 1; i <= L; i++) {
		if (scanf("%lld %ld", &a[i] ,&A[i]) == 0) 
			return -1;
		as[i] = a[i] + as[i-1];
	}
	
	bs[0] = 0;
	for (i = 1; i <= R; i++) {
		if (scanf("%lld %ld", &b[i] ,&B[i]) == 0) 
			return -1;
		bs[i] = bs[i-1] + b[i];
	}
	// ----------- INPUT -------------
	
	// ----------- DYNAMIC -----------
	
	// initialisations
	
	for (i = 0 ; i <= L ; i++)
		LCS[i][0] = 0;
	
	for (i = 0 ; i <= R ; i++)
		LCS[0][i] = 0;
		
	// actual work following

	for (i = 1 ; i <= L ; i++) {
		for (j = 1; j <= R ; j++) {
			// --- computing LCS[i][j] ------
			
			if ( A[i] != B[j] ) 	// --mismatch
			{
				tmp1 = LCS [i-1][j];
				tmp2 = LCS [i][j-1];
				
				if (tmp2 > tmp1) tmp1 = tmp2;
				
				LCS [i][j] = tmp1;
				
			}
			else	// --------  match  --------------
			{
				//-------------------------------
				if (a[i] == b[j]) { // idia miki - easy game
					LCS [i][j] = a[i] + LCS [i-1][j-1];
				}
				//-------------------------------
				else {	// diaforetika - tough shit bro
					LCS [i][j] = Sol( as[i] , bs[j] );
				}
				//-------------------------------
				
			}  // END OF --------  match  --------------
			// --- i have hopefully computed the correct LCS[i][j] ---
			//printf("%lld\t",LCS[i][j]);
		}
		//printf("\n");
	}	
	
	
	// ----------- DYNAMIC -----------

		for (i = 1 ; i <= L ; i++) {
		for (j = 1; j <= R ; j++) { printf("%lld\t",LCS[i][j]); }
		printf("\n");
		}

	// ----------- RESULTS -----------
	//printf("%lld\n", LCS[L][R] );
	// ----------- RESULTS -----------
	
	return 0;
}
