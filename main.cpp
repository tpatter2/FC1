/* 
 * File:   main.cpp
 * Author: travis.patterson
 *
 * Created on October 31, 2012, 12:01 PM
 */


#include "Vec_Functions.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int                         choice;
    float                       a,i, mag, result, vecLength;
    vector<float>               v(3),w(3),x(3),y(3);
    vector<float>::iterator     iter;
    ofstream                    CalcProj;
    //general output of the menu
    cout << "1. Scalar times a vector."<<setw(45)<<" 2. Magnitude of a vector. \n"
            "3. Normalization of a vector. 4. Sum of two vectors. \n"
            "5. Difference of two vectors. 6. Distance between the origin and a point. \n"
            "7. Distance between two points. 8. Dot product of two vectors. \n"
            "9. The scalar projection of two vectors. 10. The vector projection of two vectors. \n"
            "11. The cross product of two vectors. \n"
            "Enter the number of the operation you would like to perform:" << endl;
    cin >> choice;
    
    // Use menu selection to execute choice.
    switch (choice) {
        default: 
            cout << "That is not a valid choice. Try again. \n";
                    break;
        case 1: //scalar times a vector
                //lines starting with CalcProj are lines written to CalcProj.txt
            CalcProj.open("CalcProj.txt",ios::app);
            cout << "You have chosen scalar times a vector." << endl;
            CalcProj << "You have chosen scalar times a vector. \n" << endl;
            
            cout << "select 3 numbers for the vector separated by spaces: "<<endl;
            CalcProj << "select 3 numbers for the vector separated by spaces: \n"<<endl;
            
            cin >> v[0] >> v[1] >> v[2]; //user inputted vector
            CalcProj<< v[0]<<" " <<v[1]<<" "<<v[2]<<"\r\n";
            
            cout << "select your scalar: \n";
            CalcProj << "select your scalar: \n";
            
            cin >> a; //user inputted scalar
            CalcProj << a<<"\r\n";
            w = scalar_times_vector(a,v); //calling function from Vec_Functions.cpp
            
            cout << "The scalar " <<a<<" times the vector " //displaying results of function.
                    "<"<<v[0] <<","<<v[1]<<","<<v[2]<<"> is: "
                    "<"<<w[0] <<","<<w[1]<<","<<w[2]<<">"<< endl;
            CalcProj <<"The scalar " <<a<<" times the vector "
                    "<"<<v[0] <<","<<v[1]<<","<<v[2]<<"> is: "
                    "<"<<w[0] <<","<<w[1]<<","<<w[2]<<">"<< "\r\n\r\n"<<endl;
            CalcProj.close();
        break;
       case 2:
           CalcProj.open("CalcProj.txt",ios::app);
           cout<< "You have chosen Magnitude of a vector. \n";
           
           cout<< "Choose 3 numbers for the vector separated by spaces: "<<endl;
           cin >> v[0]>>v[1]>>v[2];
           
           a = magnitudeVector(v); //calling of function
           
           cout<< "the magnitude of vector <"<<v[0]<<","<<v[1]<<","<<v[2]<<"> is: ";
           cout<< a << endl;
           
           //taking I/O interaction above and writing it to CalcProj.txt
           CalcProj<< "You have chosen Magnitude of a vector. \r\n";
           
           CalcProj<< "Choose 3 numbers for the vector separated by spaces: "<<endl;
           CalcProj << v[0]<<" "<<v[1]<<" "<<v[2]<<" \r\n";
           
           CalcProj<< "the magnitude of vector <"<<v[0]<<","<<v[1]<<","<<v[2]<<"> is: ";
           CalcProj<< a << "\r\n\r\n"<<endl;
            
           CalcProj.close(); 
       break;
       case 3:
           CalcProj.open("CalcProj.txt",ios::app);
           cout<<"you have chosen Normalization of a vector." <<endl;
           
           cout<<"Select 3 numbers for the vector separated by spaces: "<<endl;
           cin >> v[0]>>v[1]>>v[2];
           
           w=unitVector(v,mag);
           
           cout<<"the unit vector is: "
               <<"<"<<w[0] <<","<<w[1]<<","<<w[2]<<">"<< endl;
           
           //Writing to CalcProj.txt
           CalcProj<<"you have chosen Normalization of a vector.  \r\n" <<endl;
           
           CalcProj<<"Select 3 numbers for the vector separated by spaces:  "<<endl;
           CalcProj << v[0]<<" "<<v[1]<<" "<<v[2]<<"\r\n";
           
           CalcProj<<"the unit vector is: "
               <<"<"<<w[0] <<","<<w[1]<<","<<w[2]<<">\r\n\r\n"<< endl;
          CalcProj.close();
            
       break;
       case 4:
           CalcProj.open("CalcProj.txt",ios::app);
           cout<<"you have chosen Addition of 2 vectors." <<endl;
           
           cout<<"Select 3 numbers for the first vector separated by spaces: "<<endl;
           cin >> x[0]>>x[1]>>x[2];
           
           cout<<"Select 3 numbers for the second vector separated by spaces: "<<endl;
           cin >> y[0]>>y[1]>>y[2];
           
           w=vecSum(x,y);
           cout<<"The new vector is " <<"<"<<w[0] <<","<<w[1]<<","<<w[2]<<">"<< endl;
           
           //writing to CalcProj.txt
           CalcProj<<"you have chosen Addition of 2 vectors.\r\n" <<endl;
           
           CalcProj<<"Select 3 numbers for the first vector separated by spaces: "<<endl;
           CalcProj << x[0]<<" "<<x[1]<<" "<<x[2]<<"\r\n";
           
           CalcProj<<"Select 3 numbers for the second vector separated by spaces: "<<endl;
           CalcProj << y[0]<<" "<<y[1]<<" "<<y[2]<<"\r\n";
           
           CalcProj<<"The new vector is " <<"<"<<w[0] <<","<<w[1]<<","<<w[2]<<">\r\n\r\n"<< endl;
           CalcProj.close(); 
       break;
       case 5:
           CalcProj.open("CalcProj.txt",ios::app);
           cout<<"you have chosen Difference of 2 vectors." <<endl;
           
           cout<<"Select 3 numbers for the first vector separated by spaces: "<<endl;
           cin >> x[0]>>x[1]>>x[2];
           
           cout<<"Select 3 numbers for the second vector separated by spaces: "<<endl;
           cin >> y[0]>>y[1]>>y[2];
           
           w=vecDif(x,y);
           cout<<"The new vector is " <<"<"<<w[0] <<","<<w[1]<<","<<w[2]<<">"<< endl;
           
           //writing to CalcProj.txt
           CalcProj<<"you have chosen Difference of 2 vectors.\r\n" <<endl;
           
           CalcProj<<"Select 3 numbers for the first vector separated by spaces: "<<endl;
           CalcProj << x[0]<<" "<<x[1]<<" "<<x[2]<<"\r\n";
           
           CalcProj<<"Select 3 numbers for the second vector separated by spaces: "<<endl;
           CalcProj<< y[0]<< " "<<y[1]<<" "<<y[2] << "\r\n";
           
           CalcProj<<"The new vector is " <<"<"<<w[0] <<","<<w[1]<<","<<w[2]<<">\r\n\r\n"<< endl;
            CalcProj.close();
       break;
       case 6:
           CalcProj.open("CalcProj.txt",ios::app);
           cout<<"you have chosen the distance between a point and the origin. \n";
           
           cout<<"Select three numbers for your point separated by spaces. \n";
           cin >>v[0]>>v[1]>>v[2];
           
           a = oriLength(v);
           cout<<"the distance between the point and origin is: "<<a<<" units.";
           
           //writing to CalcProj.txt
           CalcProj<<"you have chosen the distance between a point and the origin. \r\n";
           
           CalcProj<<"Select three numbers for your point separated by spaces. \n";
           CalcProj <<v[0]<<" "<<v[1]<<" "<<v[2]<<"\r\n";
           
           CalcProj<<"the distance between the point and origin is: "<<a<<" units.\r\n";
           CalcProj.close(); 
            
       break;
       case 7:
           CalcProj.open("CalcProj.txt",ios::app);
           cout<<"you have chosen the Distance between 2 points. \n\n";
           
           cout<<"Select three numbers for the first point: \n";
           cin >>x[0]>>x[1]>>x[2];
           cout << endl;
           
           cout<<"Select three numbers for the second pont: \n";
           cin >>y[0]>>y[1]>>y[2];
           cout << endl;
           
           a = pointDif(x,y);
           cout <<"the distance between the two points is "<< a <<" units.\n";
           
           //writing to CalcProj.txt
           CalcProj<<"you have chosen the Distance between 2 points. \r\n";
           
           CalcProj<<"Select three numbers for the first point: \n";
           CalcProj<<x[0]<<" "<<x[1]<<" "<<x[2]<<"\r\n";
           CalcProj << endl;
           
           CalcProj<<"Select three numbers for the second pont: \n";
           CalcProj<<y[0]<<" "<<y[1]<<" "<<y[2] << "\r\n";
           CalcProj << endl;
           
           CalcProj <<"the distance between the two points is "<< a <<" units.\r\n";
           CalcProj.close(); 
       break;
       case 8:
           CalcProj.open("CalcProj.txt",ios::app);
           cout<<"you have chosen Dot Product of 2 vectors." <<endl;
           
           cout<<"Select 3 numbers for the first vector separated by spaces: "<<endl;
           cin >> x[0]>>x[1]>>x[2];
           
           cout<<"Select 3 numbers for the second vector separated by spaces: "<<endl;
           cin >> y[0]>>y[1]>>y[2];
           
           a=dotProd(x,y);
           cout<<"The Dot Product is " <<a<< "."<<endl;
           
           //writing to CalcProj.txt
           CalcProj<<"you have chosen Dot Product of 2 vectors.\r\n" <<endl;
           
           CalcProj<<"Select 3 numbers for the first vector separated by spaces: "<<endl;
           CalcProj<< x[0]<<" "<<x[1]<<" "<<x[2]<<"\r\n";
           
           CalcProj<<"Select 3 numbers for the second vector separated by spaces: "<<endl;
           CalcProj<<y[0]<<" "<<y[1]<<" "<<y[2]<<"\r\n";
           
           CalcProj<<"The Dot Product is " <<a<< ".\r\n"<<endl;
           CalcProj.close();
            
       break;
       case 9:
           CalcProj.open("CalcProj.txt",ios::app);
           cout<<"you have chosen the Scalar Projection of 2 vectors." <<endl;
           
           cout<<"Select 3 numbers for the first vector separated by spaces: "<<endl;
           cin >> x[0]>>x[1]>>x[2];
           
           cout<<"Select 3 numbers for the second vector separated by spaces: "<<endl;
           cin >> y[0]>>y[1]>>y[2];
           
           a = scalarProj(x,y);
           cout<<"The Scalar Projection is "<<a<< " units."<< endl;
           
           //writing to CalcProj.txt
           CalcProj<<"you have chosen the Scalar Projection of 2 vectors.\r\n" <<endl;
           
           CalcProj<<"Select 3 numbers for the first vector separated by spaces: "<<endl;
           CalcProj<<x[0]<<" "<<x[1]<<" "<<x[2]<<"\r\n";
           
           CalcProj<<"Select 3 numbers for the second vector separated by spaces: "<<endl;
           CalcProj<<y[0]<<" "<<y[1]<<" "<<y[2]<<"\r\n";
           
           CalcProj<<"The Scalar Projection is "<<a<< " units.\r\n"<< endl;
           CalcProj.close();
            
       break;
       case 10:
           CalcProj.open("CalcProj.txt",ios::app);
           cout<<"you have chosen the Vector Projection of 2 vectors." <<endl;
           
           cout<<"Select 3 numbers for the first vector separated by spaces: "<<endl;
           cin >> x[0]>>x[1]>>x[2];
           
           cout<<"Select 3 numbers for the second vector separated by spaces: "<<endl;
           cin >> y[0]>>y[1]>>y[2];
           
           w = vecProj(x,y);
           cout<<"The Vector Projection is " <<"<"<<w[0] <<","<<w[1]<<","<<w[2]<<">"<< endl;
           
           //writing to CalcProj.txt
           CalcProj<<"you have chosen the Vector Projection of 2 vectors.\r\n" <<endl;
           
           CalcProj<<"Select 3 numbers for the first vector separated by spaces: "<<endl;
           CalcProj<< x[0]<<" "<<x[1]<<" "<<x[2]<<"\r\n";
           
           CalcProj<<"Select 3 numbers for the second vector separated by spaces: "<<endl;
           CalcProj<<y[0]<<" "<<y[1]<<" "<<y[2]<<"\r\n";
           
           CalcProj<<"The Vector Projection is " <<"<"<<w[0] <<","<<w[1]<<","<<w[2]<<">\r\n"<< endl;
           CalcProj.close();
            
       break;
       case 11:
           CalcProj.open("CalcProj.txt",ios::app);
           cout<<"you have chosen the Cross Product of 2 vectors." <<endl;
           
           cout<<"Select 3 numbers for the first vector separated by spaces: "<<endl;
           cin >> x[0]>>x[1]>>x[2];
           
           cout<<"Select 3 numbers for the second vector separated by spaces: "<<endl;
           cin >> y[0]>>y[1]>>y[2];
           
           w = crossProd(x,y);
           cout<<"The Cross Product is " <<"<"<<w[0] <<","<<w[1]<<","<<w[2]<<">"<< endl;
           
           //writing to CalcProj.txt
           CalcProj<<"you have chosen the Cross Product of 2 vectors.\r\n" <<endl;
           
           CalcProj<<"Select 3 numbers for the first vector separated by spaces: "<<endl;
           CalcProj<<x[0]<<" "<<x[1]<<" "<<x[2]<<"\r\n";
           
           CalcProj<<"Select 3 numbers for the second vector separated by spaces: "<<endl;
           CalcProj<<y[0]<<" "<<y[1]<<" "<<y[2]<<"\r\n";
           
           CalcProj<<"The Cross Product is " <<"<"<<w[0] <<","<<w[1]<<","<<w[2]<<">\r\n"<< endl;
           CalcProj.close();
            
       break;
    }
    return 0;
}

