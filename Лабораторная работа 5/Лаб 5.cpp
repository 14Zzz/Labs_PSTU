#include<iostream>

using namespace std;

// Функция
int sedlovie (int matr[][3], int M, int N)
{
  int min,max,i,j,y,x;
  for (i=0;i<N;i++) 
  {
     min=matr[i][0];
     for (x=0;x<M;x++)
     {
        if ( matr[i][x]>min )
        {
           min=matr[i][x]; 
        }
     }
     for( j=0;j<M;j++)
     {
         if ( matr[i][j]==min)
         {  
            max=matr[0][j];
            for (y=0;y<N;y++) 
            {
                if ( matr[y][j]<max) 
                { 
                    max = matr[y][j];
                }
            }
                   if (matr[i][j]==max)
                   { 
                      cout << "Седловая точка: " << (matr[i][j]) << endl;
                   }
         }
     }
  }
  
  // То же самое, но "<" меняем на ">", что бы выполнялось "наибольшее в строке, наименьшее в столбце"
  for (i=0;i<N;i++) 
  {
     min = matr[i][0];
     for (x=0;x<M;x++)
     {
        if ( matr[i][x]<min)
        {
           min = matr[i][x]; 
        }
     }
     for( j=0;j<M;j++)
     {
         if ( matr[i][j]==min)
         {  
            max=matr[0][j];
            for (y=0;y<N;y++) 
            {
                if ( matr[y][j]>max) 
                { 
                    max= matr[y][j];
                }
            }
                   if (matr[i][j]==max)
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

    int matr[][3] = {{1,2,3},{4,5,6},{7,8,9}};
    
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
