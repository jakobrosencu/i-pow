#include "iPow.h"

#include "LUsolve.h"





// =========================================================================
// M A I N   P R O G R A M
// =========================================================================

int main(int argc, char *argv[])
{
  int m; // number of rows
  int n; // number of columns

  #include "setCase.h"

  // ---------------------------------------------
  // Set up Inverse Power Method
  // ---------------------------------------------

  int    iter      =
  int    maxIter   =
  int    converged =
  double tol       =
  double mu;
  double mu_old    = 
  double lambda;

  double x[n];     // Used during Inverse Power Method Iteration, see class notes
  double xhat[n];  //   "   "       "       "      "      "        "    "     "

  // Compute initial guess at x
  
  for ( ____________________ ) x[ ___  ] = 

 // Save new A = (A - alpha*I) in Asave:

  iLOOP       A    [i][j] = 
  iLOOP jLOOP Asave[i][j] 


  // Print (A - alpha*I)
  
  printSystem(    ......  )
  
  // ---------------------------------------------
  // Perform LU factorization of new A
  // ---------------------------------------------
  
  #include "LU.h"

  // A now stores what.?  Point to the upper triangular A with  U:

    double **U = ......

  // ---------------------------------------------
  // Inverse Power Method Iterations
  // ---------------------------------------------

  while (  converged != 1 )
    {

      // Max iteration check
      
      if (        )    {  cout << "Max iterations exceeded." << endl;  exit(0); }

      // Step 2a: Compute xhat (Solve  (A - alpha I) * xhat = x)

      LUsolve(L , U , xhat , x , m , n , Asave );   // Asave is passed to check solution
      
      // Step 2b: Scale xhat so that the largest value = 1

      // ...

      // ...

      // Step 2c: Check for convergence and update mu)old

      // ...
      
      // ...

      cout << "iter = " << iter << " mu = " << mu << endl;
      
    }

  // Compute final estimate for eigenvalue of original A, Aoriginal:

    lambda = alpha + 1/mu;
  
    cout << caseName << ": Inverse Power Method Converged in " << iter << " iterations." << endl;
    cout << caseName << ": =========================== Results " << endl;
    cout << caseName << ": mu = " << mu << endl;
    cout << caseName << ": lambda = " << lambda << endl;
    cout << caseName << ": ===========================         " << endl;
  
  
  // ---------------------------------------------
  // Test Eigenvalue/Eigenvector
  // ---------------------------------------------

    // Print eigenvector and Aoriginal * eigenvector, computing the ratio
    // to see how consistent that ratio is.

    double Ax[m];  iLOOP jLOOP // .....

    iLOOP jLOOP Ax[i] += // ...... 
   
    iLOOP printf("%s: E-vector Check:     x[%d] = %5.2f     Ax[%d] = %5.2f     ratio = %s\n",
		 caseName.c_str(), .....   );

    
    
  
}

