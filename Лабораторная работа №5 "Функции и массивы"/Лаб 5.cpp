#include<iostream>

using namespace std;

// Функция
int sedlovie (int matr[][3], int M, int N)
{
  int minr,maxc,i,j,y,x;
  for (i=0;i<N;i++) 
  {
     minr=matr[i][0];
     for (x=0;x<M;x++)
     {
        if ( matr[i][x]<minr )
        {
           minr=matr[i][x]; 
        }
     }
     for( j=0;j<M;j++)
     {
         if ( matr[i][j]==minr)
         {  
            maxc=matr[0][j];
            for (y=0;y<N;y++) 
            {
                if ( matr[y][j]>maxc ) 
                { 
                    maxc= matr[y][j];
                }
            }
                   if (matr[i][j]==maxc)
                   { 
                      cout << "Седловая точка: " << (matr[i][j]) << endl;

                   }
         }
     }
  } 
return (0);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    
    int const stolbcov = 3, strok = 3;

    int matr[][3] = {{1,2,2},{4,2,2},{7,8,9}};
    
    // Вывод матрицы
    for (int j = 0; j < strok; j++)
    {
        for (int i = 0; i < stolbcov; i++)
        {
            cout << matr[j][i] << " ";
        }
        cout << endl;
    }
    
    // Передача матрицы в функцию
    cout << sedlovie (matr, strok, stolbcov);
}
