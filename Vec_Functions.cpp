/* 
 * File:   Vec_Functions.cpp
 * Author: travis.patterson
 *
 * Created on October 31, 2012, 12:30 PM
 */

#include "Vec_Functions.h"

using namespace std;

/* functions used in the Calculus III project.
 * 
 */
vector<float> scalar_times_vector(float a, vector<float> v) {
    
    vector<float> result(3);
    vector<float>::iterator iter=v.begin();
    int i;
    for (i=0;i<3;i++)
        result[i] = a * v[i]; //multiplies scalar times the user-defined vector
    while (iter != v.end()){
        *iter *= a;
        iter++;
    }
    return result;
}

float magnitudeVector(vector<float> v) {
    float w;
    w = sqrt(pow(v[0],2)+pow(v[1],2)+pow(v[2],2)); //squares the sum of the squared components
    return w;
}

vector<float> unitVector (vector<float> v, float mag){
    
    float magnitude,i;
    vector<float>               w(3);
    vector<float>::iterator     iter = v.begin();
    
    magnitude=magnitudeVector(v); //re-using function magnitudeVector
    
    for (i=0;i<3;i++)
        w[i] = v[i]/magnitude; //divides user-defined vector by the magnitude fxn.
    while (iter != v.end()){
        *iter /= magnitude;
        iter++;
    }
    return v;
}

vector<float> vecSum (vector<float> x,vector<float> y){
    int i;
    vector<float>               vecsum(3);
    vector<float>::iterator     iterx = x.begin(), itery = y.begin();
    
    for (i=0;i<3;i++)
        vecsum[i] = x[i]+y[i]; //adds 2 user-defined vectors
    while(iterx != x.end() && itery != y.end()){
        *iterx += *itery;
        iterx++, itery++;
        
    }
    return x; 
}

vector<float> vecDif (vector<float> x,vector<float> y){
    int i;
    vector<float>               vecdif(3);
    vector<float>::iterator     iterx = x.begin(), itery = y.begin();
    
    for (i=0;i<3;i++)
        vecdif[i] = x[i]-y[i];//subtracts the two vectors
    while(iterx != x.end() && itery != y.end()){
        *iterx -= *itery;
        iterx++, itery++;
        
    }
    return x; 
}

float oriLength(vector<float> v) {
    float w;
    w = sqrt(pow(v[0],2)+pow(v[1],2)+pow(v[2],2));//basically re-using magnitude
    return w;
}

float pointDif (vector<float> x, vector<float> y){
    int i;
    float                       ans;
   
   //subtracts the difference between the components of the two vectors    
   ans = sqrt(pow((x[0]-y[0]),2)+pow((x[1]-y[1]),2)+pow((x[2]-y[2]),2));
    
    return ans;
}

float dotProd (vector<float> x, vector<float> y){
    int i;
    float                       ans;
       
   ans = (x[0]*y[0])+(x[1]*y[1])+(x[2]*y[2]); //multiplies the components of the vectors
    
    return ans;
}

float scalarProj (vector<float> x, vector<float>y){
    float                       dot_product,vecMag,ans;
    
    dot_product = (x[0]*y[0])+(x[1]*y[1])+(x[2]*y[2]); //get the dot product of the vectors
    vecMag = sqrt(pow(y[0],2)+pow(y[1],2)+pow(y[2],2));//gets the magnitude of the second vector
    ans = dot_product/vecMag;//divides the dot product by the magnitude of the second vector
    
    return ans;
}

vector<float> vecProj (vector<float> x, vector<float> y){
    int i;
    float                               scalarA,scalarB,ratio1;
    vector<float>                       vec_proj;
    
    scalarA = dotProd(x,y); //finds dot product of vectors x and y
    scalarB = dotProd(y,y); //finds dot product of vectors y and y
    ratio1=scalarA/scalarB; //finds the ratio of two dot products
    vec_proj = scalar_times_vector(ratio1,y);//uses first function to multiply a vector times a function
    
   return vec_proj;    
}

vector<float> crossProd (vector<float>x, vector<float>y){
int i;
vector<float>                           XProd(3);

//<a2b3-a3b2,a3b1-a1b3,a1b2-a2b1> <-- formula for cross product
XProd[0] = x[1]*y[2]-x[2]*y[1]; // finds the value of the x component
XProd[1] = x[2]*y[0]-x[0]*y[2]; // finds the value of the y component
XProd[2] = x[0]*y[1]-x[1]*y[0]; // finds the value of the z component
return XProd; //returns the values of the components in the form of a vector
}
