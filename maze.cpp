#include<iostream>
#include<cstdlib>
#include<stdio.h>
using namespace std;

 void drawMaze(int n , char ch[8][8])
 {
     int i,j=0;
     cout<<"\n\n\n\n\n";
     for(i=0;i<n;i++)
     {
         cout<<"\t   "<<(i+1)<<"  ";
     }
     cout<<"\n";
    for(i=0;i<n;i++)
     {
         cout<<"\t  ___  ";
     }
     cout<<"\n";
     while(j<n)
     {
        for(i=0;i<n;i++)
        {
            if(ch[i][j]!=' ')
                printf("\t| _%c_ |",ch[i][j]);
            else
                cout<<"\t| ___ |";
        }
        cout<<"\n";
        j++;
     }
    cout<<"\n\n\n\n\n";
 }

 /*char* randomObstructions(char maze[8][8],int n)
 {
    int c=(.25*n*n);
    while(c<8)
    {
        int i=rand()%8;
        int j=rand()%8;
        if(maze[i][j]!='X' && (i!=0&&j!=0)||(i!=8 && j!=8))
          {
            maze[i][j]='X';
            c++;
        }
    }
    return maze;
 }*/

 void move(char arr[8][8] ,int size, int x,int y)
 {
     char ch;
     do
     {
         cout<<"\nUP....'W'";
         cout<<"\nLEFT....'A'";
         cout<<"\nDOWN....'S'";
         cout<<"\nRIGHT....'D'";
         cout<<"\nEnter Your next Move:- ";
         cin>>ch;
         switch(ch)
         {
         case 'W':
             {
                 if(y>0 && arr[x][y-1]!='X')
                   {
                     arr[x][y]='_';
                     y-=1;
                     arr[x][y] = '@';
                   }
                else
                    cout<<"\nCan't Move up";
                break;
             }
         case 'A':
             {
                 if(x>0 && arr[x-1][y]!='X')
                    {
                        arr[x][y]='_';
                        x-=1;
                        arr[x][y] = '@';
                    }
                else
                    cout<<"\nCan't Move left";
                break;
             }
        case 'S':
             {
                 if(y>=0 &&y<size && arr[x][y+1]!='X')
                    {
                        arr[x][y]='_';
                        y+=1;
                        arr[x][y] = '@';
                    }
                else
                    cout<<"\nCan't Move Down";
                break;
             }

        case 'D':
             {
                 if(x>=0 && x<size && arr[x+1][y]!='X')
                    {
                        arr[x][y]='_';
                        x+=1;
                        arr[x][y] = '@';
                    }
                else
                    cout<<"\nCan't Move Right";
                break;
             }
        }
        system("clear");
        drawMaze(size,arr);
        cout<<"\nPress Y to continue or N:-";
        cin>>ch;

    }while(ch=='Y');
 }
 int main()
 {
     int n=8;
     char arr[8][8];

     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
            arr[i][j]=' ';
     }
     //arr = randomObstructions(arr,n);
     arr[0][0]='@';
     arr[n-1][n-1]='#';
     arr[3][4] = 'X';
     arr[1][7] = 'X';
     arr[2][4] = 'X';
     arr[6][6] = 'X';
     arr[7][5] = 'X';
     drawMaze(n,arr);
     move(arr,n,0,0);
     return 0;
 }