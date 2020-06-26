#include "vectorApps.hpp"

void dbg_showMat(vector<vector<int>> vin)
{
    int i;
    i = vin.size();
    cout<<"number of rows : "<<i<<endl;
}

void disp()
{
    cout<<"hello from vector apps";
    // allocate a 2D vector
    vector<int> vx(10, 0); // 10 elements each intialized to 0

    int i;
    for(i = 0; i < 10; i++)
    {
        cout<<vx[i]<<endl;
    }

    typedef vector<vector<int>> Mat;
    typedef vector<vector<vector<int>>> ImgMat;
    vector<vector<int>> mat {
				{ 0, 1, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 }};

    
    // use the typedef
    Mat M1{{1, 1, 1},
        {0, 0, 0},
        {1, 1, 1}};

    ImgMat img1 {   {  
                        {1, 1, 1, 1},
                        {1, 1, 1, 1}, // R channel
                        {1, 1, 1, 1}
                    },
                    {
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}, // G channel
                        {0, 0, 0, 0}
                    },
                    {
                        {1, 1, 1, 1},
                        {1, 0, 1, 0}, // B channel
                        {0, 1, 0}
                    }
                };

    // ImgMat img1 {   {  
    //                 {1, 1, 1},
    //                 {1, 1, 1}, // R channel
    //                 {1, 1, 1}
    //             }
                
    //         };
    
    dbg_showMat(M1);

    cout<<"number of channels : "<<img1.size();
    cout<<"number of rows ; "<<img1[0].size();
    cout<<"number of columns ; "<<img1[0][0].size();

    // create an Mtx object
    Mtx<int> matX(img1);
    //

}

