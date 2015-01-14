#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Using DP and the (n,m) th element (n>=m) is the problem of m queen with rectangle.

vector<vector<string> > generateColSol(int n)
{
    vector<vector<string> > output;
    string temp {"."};
    vector<string> solutionTemplate;
    for (int k=0; k<n; k++)
    {
        solutionTemplate.push_back(temp);
    }
    for (int k=0; k<n; k++)
    {
        solutionTemplate[k]="Q";
        output.push_back(solutionTemplate);
        solutionTemplate[k]=".";
    }
    return output;
}

void display(vector<vector<string> > input)
{
    cout << "[" << endl;
    for (int k=0; k<input.size(); k++)
    {
        cout << "[";
        for (int j=0; j<input[k].size(); j++)
        {
            cout << "\"" << input[k][j] << "\"";
            if (!(j==input[k].size()-1))
                cout << "," << endl << " ";
        }
        cout << "]";
        if (!(k==input.size()-1))
            cout << ","<< endl;
        cout << endl;

    }
    cout << "]" << endl;
}

bool hasQ(string s)
{
    int l(s.size());
    if  (l==0)
        return false;
    for (int k=0; k<l; k++)
    {
        if (s[k]=='Q')
            return true;
    }
    return false;

}
vector<vector<string> > solveNQueens2(int n)
{
    vector<vector<string> > result;
    if (n==1)
    {
        vector<string > oneS;
        oneS.push_back("Q");
        result.push_back(oneS);
        return result;
    }
    if (n<4)
    {
        return {};
    }

    vector<vector<string> > generalSolutions[n+1][n+1];
    for (int k=1; k<= n; k++)
    {
        generalSolutions[k][0]= {{}};
        generalSolutions[k][1]=generateColSol(k);
    }
    string stringTemplate {""};
    for (int k=0; k<n; k++)
    {
        stringTemplate.push_back('.');
    }
    for (int nr=2; nr<n+1; nr++)
    {
        for (int nc=2; nc<=nr; nc++)
        {

            for (int leftCol=0; leftCol<nc; leftCol++)
            {
                vector<vector<string> >  lhs = generalSolutions[nr-1][leftCol];
                vector<vector<string> >  rhs = generalSolutions[nr-1][nc-leftCol-1];
                for (int i=0; i<lhs.size(); i++)
                {
                    for (int j=0; j<rhs.size(); j++)
                    {
                        vector<string> lSol(lhs[i]);
                        vector<string> rSol(rhs[j]);
                        if ((lSol.empty()||lSol[0][leftCol-1]!='Q')&&(rSol.empty()||rSol[0][0]!='Q'))
                        {
                            vector<string> concS;
                            string firstRow = stringTemplate.substr(0,nc);
                            firstRow[leftCol]='Q';
                            concS.push_back(firstRow);
                            bool valid(true);

                            string otherRow("");
                            if (lSol.empty())
                            {

                                for (int r=0; r<nr-1; r++)
                                {
                                    otherRow = "."+rSol[r];
                                    concS.push_back(otherRow);
                                }


                            }
                            else if (rSol.empty())
                            {
                                for (int r=0; r<nr-1; r++)
                                {
                                    otherRow=lSol[r]+".";
                                    concS.push_back(otherRow);
                                }

                            }

                            else
                            {
                                for (int r=0; r<nr-1; r++)
                                {
                                    if(hasQ(lSol[r]) and hasQ(rSol[r]))
                                    {
                                        valid = false;
                                        break;
                                    }
                                    otherRow = lSol[r]+"."+rSol[r];
                                    concS.push_back(otherRow);
                                }

                            }
                            if (valid)
                            {
                                generalSolutions[nr][nc].push_back(concS);
                            }
                        }
                    }
                }
            }
        }
    }
    return generalSolutions[n][n];
}


bool isValidQ(vector<string> board, int row, int col)
{
    int n(board.size());
    if(n==0)
        return true;
    for (int k=0; k<n; k++)
    {
        if (k!=row&&board[k][col]=='Q')
            return false;
        if(k!=0&&row>=k&&col>=k&&board[row-k][col-k]=='Q')
            return false;
        if(k!=0&&row>=k&&col<n-k&&board[row-k][col+k]=='Q')
            return false;
//            don't have to try the column either
//        if (k!=col&&board[row][k]=='Q')
//            return false;
    }


//        I'm going row per row so don't need to check these:
//    if(row!=n-1&&col!=n-1&&board[row+1][col+1]=='Q')
//        return false;
//    if(row!=n-1&&col!=0&&board[row+1][col-1]=='Q')
//        return false;
    return true;

}


void solveBacktrack(vector<string> &board, int n,int currentRow,vector<vector<string> > &solutions)
{
    if (currentRow==n)
    {
        solutions.push_back(board);
        return;
    }
    for (int k=0; k<n; k++)
    {
        board[currentRow][k]='Q';
        if(isValidQ(board,currentRow,k))
        {
            solveBacktrack(board, n,currentRow+1,solutions);
        }
        board[currentRow][k]='.';
    }
    return;
}

vector<vector<string> > solveNQueens(int n)
{
    if (n==0)
        return {{}};

    vector<vector<string> > solutions;
    vector<string> board(n, string(n, '.'));
    solveBacktrack(board,n,0,solutions);
    return solutions;

}

void totalBacktrack(vector<string> &board, int n,int currentRow,int &count)
{
    if (currentRow==n)
    {
        count++;
        return;
    }
    for (int k=0; k<n; k++)
    {
        board[currentRow][k]='Q';
        if(isValidQ(board,currentRow,k))
        {
            totalBacktrack(board, n,currentRow+1,count);
        }
        board[currentRow][k]='.';
    }
    return;
}
 int totalNQueens(int n) {
      if (n==0)
        return 1;

    int count(0);
    vector<string> board(n, string(n, '.'));
    totalBacktrack(board,n,0,count);
    return count;

    }


int main()
{
    vector<vector<string> > result(solveNQueens(1));
//    display(result);
    cout << result.size() << endl;
    cout << "count function: " << totalNQueens(1);

    return 0;
}
