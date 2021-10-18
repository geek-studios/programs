class Matrixmultiplication{ 
public static void main(String[] args){ 
int arr1[][] = {{1,2,3},{4,5,6},{7,8,9}}; 
int arr2[][] = {{9,8,7},{6,5,4},{3,2,1}}; 
int[][] product = new int[3][3]; 
int i=0,j=0,k=0; 
for(i=0;i<3;i++){ 
for(j=0;j<3;j++){ 
for(k=0;k<3;k++){ 
product[i][j] += arr1[i][k] * arr2[k][j]; 
} 
} 
} 
System.out.println("First Array : "); 
for(i=0;i<3;i++){ 
for(j=0;j<3;j++){ 
System.out.print(arr1[i][j]+" "); 
} 
System.out.println(); 
} 
System.out.println(); 
System.out.println("Second Array : "); 
for(i=0;i<3;i++){ 
for(j=0;j<3;j++){ 
System.out.print(arr2[i][j]+" "); 
} 
System.out.println(); 
} 
System.out.println(); 
System.out.println("Array After Multiplication : "); for(i=0;i<3;i++){ 
for(j=0;j<3;j++){ 
System.out.print(product[i][j]+" "); 
} 
System.out.println(); 
} 
} 
}
