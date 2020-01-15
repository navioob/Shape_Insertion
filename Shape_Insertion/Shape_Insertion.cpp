/**************|**************|**************|
Program: TC02_A1_BOO_EE_KEIN_IVAN.cpp
Course: OOPDS
Year: 2018/2019 Trimester 2
Name: Boo Ee Kein Ivan
ID: 1161104032
Lecture Section: TC02
Tutorial : TT03
Email: 1161104032@student.mmu.edu.my
Phone: 017-3070870
*************|***************|***************/

#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;

/*------------------------|
|--------Classes----------|
|------------------------*/

class Shape //Abstract Parent Class
{
public:
    static int lengthArea;
    static int widthArea;
    static char shapeName;
    static int randX;
    static int randY;
    virtual void fit(char** arr, int& success)=0;
};

class Square:public Shape //Derived class
{
private:
    int SqLength;
public:
    Square(int SqLength):SqLength(SqLength){}
    void fit(char** arr, int& success)
    {
        /*Does checking of the area of random point if it is
        available for fitting in the shape. If it is available
        then it will fit it into a 2D array*, if it is unavailable,
        then it will break form the loop*/

        bool available = true;
        int nowX = randX+SqLength;
        int nowY = randY+SqLength;
        if(nowY<widthArea && nowX<lengthArea && arr[randY][randX]=='.')
        {
            for(int i=randY; i<nowY; i++)
            {
                for(int j=randX; j<nowX; j++)
                {
                    if (arr[i][j]!='.')
                    {
                        available = false;
                        break;
                    }
                }

                if(!available)
                {
                    break;
                }
            }

            if(available)
            {
                for(int i=randY; i<nowY; i++)
                {
                    for(int j=randX; j<nowX; j++)
                    {
                        arr[i][j]= shapeName;
                    }
                }
                success++;
            }
        }
    }
    ~Square(){}
};

class Rectangle:public Shape
{
private:
    int RecLength;
    int RecWidth;
public:
    Rectangle(int RecLength, int RecWidth):RecLength(RecLength),RecWidth(RecWidth){}
    void fit(char** arr, int& success)
    {
        bool available = true;
        int nowX = randX+RecLength;
        int nowY = randY+RecWidth;
        if(nowY<widthArea && nowX<lengthArea && arr[randY][randX]=='.')
        {
            for(int i=randY; i<nowY; i++)
            {
                for(int j=randX; j<nowX; j++)
                {
                    if (arr[i][j]!='.')
                    {
                        available = false;
                        break;
                    }
                }
                if(!available)
                {
                    break;
                }
            }

            if(available)
            {
                for(int i=randY; i<nowY; i++)
                {
                    for(int j=randX; j<nowX; j++)
                    {
                        arr[i][j]= shapeName;
                    }
                }
                success++;
            }
        }
    }
    ~Rectangle(){}
};

class Triangle:public Shape
{
private:
    int TriHeight;
public:
    Triangle(int TriHeight):TriHeight(TriHeight){};
    void fit(char** arr, int& success)
    {
        bool available = true;
        int nowX = randX;
        int nowY = randY+TriHeight;
        int tempX = randX;
        int tempY = randY;
        if(nowY<widthArea && nowX<lengthArea && arr[randY][randX]=='.')
        {
            for(int i=0;i<TriHeight;i++)
            {
                for(int j=TriHeight;j>i+1;j--)
                {
                    tempX++;
                }

                for(int k=0;k<=i*2;k++)
                {
                    if(arr[tempY][tempX]!='.')
                    {
                        available = false;
                        break;
                    }
                    tempX++;
                }
                tempX=randX;
                tempY++;

                if(!available)
                {
                    break;
                }
            }

            if(available)
            {
                int tempX = randX;
                int tempY = randY;
                 for(int i=0;i<TriHeight;i++)
                {
                    for(int j=TriHeight;j>i+1;j--)
                    {
                        tempX++;
                    }

                    for(int k=0;k<=i*2;k++)
                    {
                        arr[tempY][tempX]=shapeName;

                        tempX++;
                    }
                    tempX=randX;
                    tempY++;

                }
                success++;
            }
        }
    }
    ~Triangle(){}
};
/*---------------------------------------------------------------------------------------------------*/

/*------------------------|
|--------Functions--------|
|------------------------*/
/*Read in the length and width of the default Area*/
void initArea(int& a, int& b, ifstream& c)
{
    c >> a >> b;
}

/*Read in the number of attempts of the default Area*/
void setAttempts(int& a, ifstream& b)
{
    b >> a;
}

/*Setting a 2D array for the default Area*/
void setArea(char** arr, int a, int b)
{
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
            arr[i][j] ='.';
        }
    }
}

/*Randomize and create a random point for X and Y*/
void RandomPosition(int& randX, int& randY, int widthArea, int lengthArea)
{
    randX=(rand()%lengthArea);
    randY=(rand()%widthArea);
}

/*Delete Area 2D array*/
void DeleteArray(char** arr, int widthArea)
{
    for(int i=0; i< widthArea; i++)
            {
                delete[] arr[i];
            }
    delete[] arr;
}

/*Output the results into corresponding text files*/
void SaveResult(char** arr, int widthArea, int lengthArea, ofstream& outFile )
{
    for(int i=0; i<widthArea; i++)
            {
                for(int j=0; j<lengthArea; j++)
                {
                    outFile<<arr[i][j];
                }
                outFile<<endl;
            }
            outFile.close();
}
/*---------------------------------------------------------------------------------------------------*/

char Shape::shapeName = 'A';
int Shape::widthArea = 0;
int Shape::lengthArea = 0;
int Shape::randX = 0;
int Shape::randY= 0;

/*---------------------------------------------------------------------------------------------------*/
/*Execution code*/
int main(int argc, char* argv[])
{
    /*---Initializing the variables----*/
    int randX = 0, randY = 0;
    int widthArea = 0, lengthArea = 0, SqLength = 0, RecLength = 0, RecWidth = 0, TriHeight = 0,
    NumOfAttempts = 0,NumOfShapes = 0, filenum=1,
    numofSq = 0, numofRec = 0, numofTri = 0;

    char** Area;
    srand (time(NULL));

    ifstream inFile;
    inFile.open("Batch.txt");

    initArea(widthArea, lengthArea, inFile);
    inFile >> NumOfShapes;
    setAttempts(NumOfAttempts, inFile);

    Shape::widthArea = widthArea;
    Shape::lengthArea = lengthArea;

    for(int i=0; i<NumOfAttempts; i++)
    {
        int exvalueX, exvalueY, exvalueAtt, exvalueShapes;
        char shapename = 'A'; /*Default Shape Name*/
        int ShapeSuccess=0;
        inFile.clear();
        inFile.seekg(0, inFile.beg); /*Reread Batch.txt*/

        /*Creating a 2D array for default Area*/
        Area = new char*[widthArea];
        for (int i=0; i<widthArea; i++)
          {
              Area[i] = new char [lengthArea];
          }

        setArea(Area, widthArea, lengthArea); /*Setting up 2D array for default Area*/

        Shape::shapeName = shapename;

        inFile >> exvalueX >> exvalueY >> exvalueAtt >>exvalueShapes; /*Read away excess values from Batch.txt*/

        /*Fitting in Triangle*/
        inFile >> numofTri;
        for(int i=0; i<numofTri; i++)
        {
            Shape::shapeName = shapename;
            inFile >> TriHeight;
            Triangle t1(TriHeight);

            RandomPosition(randX, randY, widthArea,lengthArea);
            Shape::randX = randX;
            Shape::randY = randY;

            t1.fit(Area,ShapeSuccess);
            shapename++;
        }

         /*Fitting in Squares*/
        inFile >> numofSq;
        for(int i=0; i<numofSq; i++)
        {
            Shape::shapeName = shapename;
            inFile >> SqLength;
            Square s1(SqLength);

            RandomPosition(randX, randY, widthArea,lengthArea);
            Shape::randX = randX;
            Shape::randY = randY;

            s1.fit(Area,ShapeSuccess);
            shapename++;
        }

         /*Fitting in Rectangles*/
        inFile >> numofRec;
        for(int i=0; i<numofRec; i++)
        {
            Shape::shapeName = shapename;
            inFile >> RecLength >> RecWidth;
            Rectangle r1(RecLength,RecWidth);

            RandomPosition(randX, randY, widthArea,lengthArea);
            Shape::randX = randX;
            Shape::randY = randY;

            r1.fit(Area,ShapeSuccess);
            shapename++;
        }

        /*Output the results into corresponding text files */
        if(ShapeSuccess==NumOfShapes)
        {
            ofstream outFile;

            string filename = "Successful.";
            stringstream nn;
            nn<<filename<<filenum<<".txt";
            outFile.open(nn.str());

            outFile <<"Successful Attempt" << endl <<endl;
            SaveResult(Area, widthArea, lengthArea, outFile);

            cout << "Attempt " << i+1 << ": Successful" << endl <<endl;

            return 0;
        }
        else if(ShapeSuccess<NumOfShapes)
        {
            ofstream outFile;

            string filename = "Failed.";
            stringstream nn;
            nn<<filename<<filenum<<".txt";
            outFile.open(nn.str());

            outFile <<"Failed Attempt" << endl <<endl;
            SaveResult(Area, widthArea, lengthArea, outFile);

            cout << "Attempt " << i+1 << ": Failed" << endl <<endl;
            filenum++;

            DeleteArray(Area, widthArea);
        }
    }
    return 0;
}
