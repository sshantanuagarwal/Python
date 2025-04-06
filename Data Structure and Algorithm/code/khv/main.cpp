#include <iostream>

using namespace std;
long long int numberOfRows,numberOfColumns,numberOfColors,numberOfCombinations,grid[10][10];
bool leftOK(long long int r, long long int c, long long int n)
    {
        if(c == 0) return true;
        if(grid[r][c - 1] != n) return true;
        return false;
    }

    bool rightOK(long long int r, long long int c, long long int n)
    {
        if(c == numberOfColumns - 1) return true;
        if(grid[r][c + 1] != n) return true;
        return false;
    }

    bool topOK(long long int r, long long int c, long long int n)
    {
        if(r == 0) return true;
        if(grid[r - 1][c] != n) return true;
        return false;
    }

    bool bottomOK(long long int r, long long int c, long long int n)
    {
        if(r == numberOfRows - 1) return true;
        if(grid[r + 1][c] != n) return true;
        return false;
    }
 bool valid(long long int r, long long int c, long long int n)
    {
        return(leftOK(r, c, n) && rightOK(r, c, n) &&  topOK(r, c, n) &&  bottomOK(r, c, n));
    }
     void printBoard()
    {
        for(int i = 0; i < numberOfRows; i++)
        {
            for(int j = 0; j < numberOfColumns; j++)
            {
               cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
void solve(long long int r, long long int c)
    {
        for(long long int i = 1; i <= numberOfColors; i++)
        {
            if(valid(r, c, i))
            {
                grid[r][c] = i;
                if(r == numberOfRows - 1 && c == numberOfColumns - 1)
                {
                    //printBoard();
                    numberOfCombinations++;
                }
                else if(r == numberOfRows - 1) solve(0, c + 1);
                else solve(r + 1, c);
            }
        }
        grid[r][c] = 0;
    }
int main()
{long long int T,i,j;
    cin>>T;
    while(T--)
    {
        cin>>numberOfRows>>numberOfColumns>>numberOfColors;
        numberOfCombinations=0;
        for(i=0;i<numberOfRows;i++)
            for(j=0;j<numberOfColumns;j++)
            grid[i][j]=0;
        solve(0,0);
        cout<<numberOfCombinations<<endl;
    }
    return 0;
}
