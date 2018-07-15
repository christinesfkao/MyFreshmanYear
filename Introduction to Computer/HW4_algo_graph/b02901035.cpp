
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

/************************************
  Note that in general using global
  variables is a bad habit.
  I use globals here because I don't
  want to scare you with "double***"
*************************************/

int m;
int n;
double **v;  // n*(m+1) 2D-array
double **h;  // (n+1)*m 2D-array

// For internal use only. Do not really use them directly
double *real_v;
double *real_h;


void readParameters()
{
    ifstream ifs("input", ifstream::binary);

    ifs.read((char*)&m, sizeof(int));
    ifs.read((char*)&n, sizeof(int));

    real_v = new double[n*(m+1)];
    real_h = new double[(n+1)*m];

    ifs.read((char*)real_v, sizeof(double)*n*(m+1));
    ifs.read((char*)real_h, sizeof(double)*(n+1)*m);

    v = new double*[n];
    for (int i=0; i<n; ++i)
        v[i] = &(real_v[i*(m+1)]);

    h = new double*[n+1];
    for (int i=0; i<n+1; ++i)
        h[i] = &(real_h[i*m]);

    ifs.close();
}

void release()
{

    delete []v;
    delete []h;

    delete []real_v;
    delete []real_h;
}

int main()
{
    readParameters();

    // implement two 2-D arrays for every node to save path length and the nodes it passes
    double **path;
    string **route;

    double *temp_path;
    string *temp_route;

    temp_path = new double[(n + 1) * (m + 1)];
    temp_route = new string[(n + 1) * (m + 1)];

    path = new double*[n + 1];
    for (int i = 0; i <= n; ++i)
        path[i] = &(temp_path[i * (m + 1)]);

    route = new string*[n + 1];
    for (int i = 0; i <= n; ++i)
        route[i] = &(temp_route[i * (m + 1)]);


    //start filling the blanks
    path[0][0] = 0;

    for (int i = 0; i <= n; ++i)
    {
        //starting with margins

        if (i == 0); // skip[i][j]=[0][0]

        else
        {
            //do the first column (j = 0)
            path[i][0] = path[i - 1][0] + v[i - 1][0];
            route[i][0] = route[i - 1][0] + "v";
        }

        //fill each row
        for (int j = 1; j <= m; ++j)
        {
            if (i == 0) //do the first row
            {
                path[0][j] = path[0][j - 1] + h[0][j - 1];
                route[0][j] = route[0][j - 1] + "h";
            }

            else
            {
                if ((path[i - 1][j] + v[i - 1][j]) > (path[i][j - 1] + h[i][j - 1]))
                {
                    path[i][j] = path[i][j - 1] + h[i][j - 1];
                    route[i][j] = route[i][j - 1] + "h";
                }
                else
                {
                    path[i][j] = path[i - 1][j] + v[i - 1][j];
                    route[i][j] = route[i - 1][j] + "v";
                }
            }
        }
    }

    //output the shortest path
    cout << path[n][m] << endl << route[n][m] << endl;

    release();
    return 0;
}

