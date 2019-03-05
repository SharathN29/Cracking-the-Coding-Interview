/* Cracking the coding interview, Chapter 1 Problem 7
 * Rotate Matrix: Given an image represented by an NxN matrix, 
 * where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees.
 * 
 * Approach 1: Take a transpose of the matrix and reverse the rows for clockwise rotation
 * If we reverse the column instead of rows, we will get antoclockwise rotation.
 * 
 * Approach 2: Rotate individual elements layer by layer as mentioned in the book.
 * 
 * Author: Sharath Nagendra
 */

#include<iostream>

void transposeMatrix(int **matrix, int n){
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            if(i != j)
                std::swap(matrix[i][j], matrix[j][i]);
}

void reverseMatrix(int * row, int n){
    for(int i = 0; i< n/2; i++)
        std::swap(row[i], row[n-i-1]);
}

void rotate1(int ** matrix, int n){
    transposeMatrix(matrix, n);
    for(int i = 0; i < n; i++)
        reverseMatrix(matrix[i], n);
}

void rotate2(int ** matrix, int n){
    for(int i = 0; i < n/2; i++)
        for(int j = i; j < n-i-1; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][n-i-1];
            matrix[j][n-i-1] = matrix[n-i-1][n-j-1];
            matrix[n-i-1][n-j-1] = matrix[n-j-1][i];
            matrix[n-j-1][i] = temp;
        }
}

void printMatrix(int ** matrix, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout<<matrix[i][j]<< " ";
        }
        std::cout<<std::endl;
    }
}

int main(){
    int n;
    std::cout << "Enter n for n*n matrix: ";
    std::cin >> n;
    int ** matrix = new int*[n];
    for(int i = 0; i< n; i++)
        matrix[i] = new int[n];
    
    for(int i = 0; i< n; i++)
        for(int j = 0; j < n; j++)
            std::cin>>matrix[i][j];

    std::cout<<"Rotating the matrix clockwise by 90 degree: \n";
    rotate1(matrix, n);
    printMatrix(matrix, n);

    std::cout<<"Rotating the matrix anticlockwise by 90 degree: \n";
    rotate2(matrix, n);
    printMatrix(matrix, n);

    return 0;
}

