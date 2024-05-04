#include <iostream>  
#include <iomanip>
#include <cstring>
using namespace std;

int main() {
    int rows, cols, r1, r2, c1, c2;
    cout << "Enter rows in mat1: ";
    cin >> r1;
    cout << "Enter columns in mat1: ";
    cin >> c1;
    cout << "Enter rows in mat2: ";
    cin >> r2;
    cout << "Enter columns in mat2: ";
    cin >> c2;

    if ((r1 == r2) && (c1 == c2)) {
        rows = r1;
        cols = c1;
        int mat1[rows][cols];
        int mat2[rows][cols];
        cout << "Processing .... \n";

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << "Enter value for (MAT1) " << i+1 << " X " << j+1 << setw(5) << ": ";
                cin >> mat1[i][j];
            }
        }
        cout<<"MAT2"<<endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << "Enter value for (MAT2) " << i+1 << " X " << j+1 << setw(5) << ": ";
                cin >> mat2[i][j];
            }
        }
        
        int mat3[rows][cols];
        cout<<"Processing..."<<endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat3[i][j] = mat1[i][j] + mat2[i][j];
            }
        }
        cout<<"Answer is "<<endl<<endl<<endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout<<setw(3)<<mat3[i][j]<<setw(3);
            }
            cout<<endl;
        }
        
        }
     
	else {
        cout << "Invalid input/dimensions" << endl;
        exit(0);
    }

    return 0;
}


