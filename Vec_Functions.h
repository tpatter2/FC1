/* 
 * File:   Vec_Functions.h
 * Author: travis.patterson
 *
 * Created on October 31, 2012, 12:05 PM
 */
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <iostream>

using   namespace std;
#ifndef VEC_FUNCTIONS_H
#define	VEC_FUNCTIONS_H
//declare a function for 3
//function prototypes for project.
vector<float> scalar_times_vector(float, vector<float>);

float oriLength (vector<float>);

float magnitudeVector (vector<float>);

vector<float> unitVector (vector<float>, float);

vector<float> vecSum (vector<float>, vector<float>);

vector<float> vecDif (vector<float>, vector<float>);

float pointDif (vector<float>, vector<float>);

float dotProd (vector<float>, vector<float>);

float scalarProj (vector<float>, vector<float>);

vector<float> vecProj (vector<float>, vector<float>);

vector<float> crossProd (vector<float>, vector<float>);

#endif	/* VEC_FUNCTIONS_H */

