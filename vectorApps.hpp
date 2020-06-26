#ifndef VECTOR_APPS
#define VECTOR_APPS

#include <iostream>
#include <vector>
#include <cctype>

using namespace std;
void disp();

enum MATEXCP
{
    ROW_MISMATCH = -99,
    COL_MISMATCH
};

// create a template class, it handles multiple types of matrices - int, float, double
template<class MatType>
class Mtx
{
  int shape[3]; // stores row, col, channels
  int channels;
  vector<vector<MatType>> matrix; // the actual matrix to be stored

  public:

    //
    Mtx(); // default constructor

    // parameterized constr - takes any type of matrix with multiple channels (vector of vectors)
    Mtx(vector<vector<vector<MatType>>> inMat)
    {
        int rows, cols, chans, i, j, r0, c0;
        char mat_shape_check_flag = 0;
        chans = inMat.size(); // get the number of channels

        r0 = inMat[0].size();
        c0 = inMat[0][0].size();

        // verify rows and columns are equal in all channels
        for(i = 0; i < chans; i++)
        {
            if (inMat[i].size() != r0)
            {
                cout<<"Size mismatch, number of rows don't match in all channels"<<endl;

                throw(ROW_MISMATCH);
            }

            for(j = 0; j < r0; j++)
            {
                if(inMat[i][j].size() != c0)
                {
                    cout<<"Size mismatch, number of columnns don't match in all channels"<<endl;
                    throw(COL_MISMATCH);
                }
            }

        }

    }
};
#endif