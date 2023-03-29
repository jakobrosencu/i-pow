
// ---------------------------------------------
// Solve (A - labmda I) xhat = x
// ---------------------------------------------

// A = LU, so solve the above system in a 2-step process

void LUsolve(double **L,
	     double **U,
	     double *Sol,
	     double *RHS, int m, int n, double **A) {
    double y[n];

    // Solve L*y = RHS

    for (int i = 0; i < m; i++) {
        y[i] = RHS[i];
    }

    for (int j = 0; j < n; j++) {
        int pivotRow = j;
        for (int i = pivotRow + 1; i < m; i++) {
            double fac = L[i][j];
            y[i] -= y[pivotRow] * fac;
        }
    }

    // Solve U*Sol = y

    for (int i = 0; i < m; i++) {
        Sol[i] = y[i];
    }

    for (int j = n - 1; j >= 0; j--) {
        int pivotRow = j;
        double fac = U[pivotRow][j];
        Sol[pivotRow] /= fac;
        for (int i = pivotRow - 1; i >= 0; i--) {
            fac = U[i][j];
            Sol[i] -= Sol[pivotRow] * fac;
        }
    }

    // Check solution LU * Sol = RHS, or Asave*Sol = RHS

    if (n == m) {  // Must be true for there to be a unique solution

        for (int i = 0; i < m; ++i) {
            double error = RHS[i];
            for (int j = 0; j < n; ++j) {
                error -= A[i][j]*Sol[j];
            }

            if (fabs(error) > 1.e-10 ) {
                cout << "LU Solve failed\n";
                exit(0);
            }
        }
    }
}

