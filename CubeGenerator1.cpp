#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <iostream>
#include<algorithm>
using namespace std;




//point on a 3D plane with all operations implemented using operator overloading
class vec3D {
public:
	float x, y, z;

vec3D()
{
	x = y = z = 0;
}

vec3D(float a, float b, float c)
{
	x = a;y = b;z = c;
}

//float length()const
//{
//	return sqrtf(x * x + y * y + z * z);
//}
//
//vec3D normal()
//{
//	vec3D v(0, 0, 0);
//	v.x = (this->x) / length();
//	v.y = (this->y) / length();
//	v.z = (this->z) / length();
//	return v;
//
//}
//
//float dot(const vec3D& b)
//{
//	return acosf((x * b.x + y * b.y + z * b.z) / (length() * b.length()));
//}
//float prod(const vec3D& b)
//{
//	return(x * b.x + y * b.y + z * b.z);
//}
//vec3D& operator+=(const vec3D& rhs)
//{
//	this->x += rhs.x;
//	this->y += rhs.y;
//	this->z += rhs.z;
//	return *this;
//
//}
//vec3D& operator-=(const vec3D& rhs)
//{
//	this->x -= rhs.x;
//	this->y -= rhs.y;
//	this->z -= rhs.z;
//	return *this;
//
//}
//vec3D& operator*=(const vec3D& rhs)
//{
//	this->x *= rhs.x;
//	this->y *= rhs.y;
//	this->z *= rhs.z;
//	return *this;
//
//}
//vec3D& operator/=(const vec3D& rhs)
//{
//	this->x /= rhs.x;
//	this->y /= rhs.y;
//	this->z /= rhs.z;
//	return *this;
//
//}
//vec3D operator+(const vec3D& rhs)
//{
//	vec3D v(0, 0, 0);
//	v.x = this->x + rhs.x;
//	v.y = this->y + rhs.y;
//	v.z = this->z + rhs.z;
//	return v;
//
//}
//vec3D operator-(const vec3D& rhs)
//{
//	vec3D v(0, 0, 0);
//	v.x = this->x - rhs.x;
//	v.y = this->y - rhs.y;
//	v.z = this->z - rhs.z;
//	return v;
//
//}
//vec3D operator*(const vec3D& rhs)
//{
//	vec3D v = { 0, 0, 0 };
//	v.x = this->x * rhs.x;
//	v.y = this->y * rhs.y;
//	v.z = this->z * rhs.z;
//	return v;
//
//}
//vec3D operator/(const vec3D& rhs)
//{
//	vec3D v(0, 0, 0);
//	v.x = this->x / rhs.x;
//	v.y = this->y / rhs.y;
//	v.z = this->z / rhs.z;
//	return v;
//
//}

	
};

//triangle defined by 3 points & corresponding color
struct triangle {
	vec3D p[3];
	int col[3];
};

//Cube defined by a vector of triangles. function setTris to generate a cube of size s
class mesh {
public:
	vector<triangle>tris;
	mesh() {}
	void setTris (int s) {
		//takes each vertex as the top-right-front corner of a cube and creates triangles from it
		//in z,x and y axes if they don't exceed bounds aka the size of side s

		int x, y, z;
		vec3D verts[3];
		for (int x = s;x >= -s;x -= 2) {
			for (int y = s;y >= -s;y -= 2) {
				for (int z = s;z >= -s;z -= 2) {
					if (x != s && y != s && z != s && x != -s && y != -s && z != -s)continue;
					verts[0].x = x;verts[0].y = y;verts[0].z = z;
					if (y - 2 >= -s && x - 2 >= -s) {

						if (z > 0)
						{


							verts[1].x = x;verts[1].y = y - 2;verts[1].z = z;
							verts[2].x = x - 2;verts[2].y = y - 2;verts[2].z = z;

							tris.push_back({ verts[0],verts[1],verts[2] });

							verts[1].x = x - 2;verts[1].y = y - 2;verts[1].z = z;
							verts[2].x = x - 2;verts[2].y = y;verts[2].z = z;
							tris.push_back({ verts[0],verts[1],verts[2] });

						}
						else
						{

							verts[1].x = x;verts[1].y = y - 2;verts[1].z = z;
							verts[2].x = x - 2;verts[2].y = y - 2;verts[2].z = z;

							tris.push_back({ verts[0],verts[2],verts[1] });

							verts[1].x = x - 2;verts[1].y = y - 2;verts[1].z = z;
							verts[2].x = x - 2;verts[2].y = y;verts[2].z = z;
							tris.push_back({ verts[0],verts[2],verts[1] });


						}

					}



					if (z - 2 >= -s && x - 2 >= -s) {

						if (y > 0)
						{

							verts[1].x = x - 2;verts[1].y = y;verts[1].z = z - 2;
							verts[2].x = x;verts[2].y = y;verts[2].z = z - 2;

							tris.push_back({ verts[0],verts[1],verts[2] });

							verts[1].x = x - 2;verts[1].y = y;verts[1].z = z;
							verts[2].x = x - 2;verts[2].y = y;verts[2].z = z - 2;
							tris.push_back({ verts[0],verts[1],verts[2] });

						}
						else
						{
							verts[1].x = x - 2;verts[1].y = y;verts[1].z = z - 2;
							verts[2].x = x;verts[2].y = y;verts[2].z = z - 2;

							tris.push_back({ verts[0],verts[2],verts[1] });

							verts[1].x = x - 2;verts[1].y = y;verts[1].z = z;
							verts[2].x = x - 2;verts[2].y = y;verts[2].z = z - 2;
							tris.push_back({ verts[0],verts[2],verts[1] });

						}
					}
					if (y - 2 >= -s && z - 2 >= -s) {

						if (x > 0)
						{
							verts[1].x = x;verts[1].y = y;verts[1].z = z - 2;
							verts[2].x = x;verts[2].y = y - 2;verts[2].z = z - 2;

							tris.push_back({ verts[0],verts[1],verts[2] });

							verts[1].x = x;verts[1].y = y - 2;verts[1].z = z - 2;
							verts[2].x = x;verts[2].y = y - 2;verts[2].z = z;
							tris.push_back({ verts[0],verts[1],verts[2] });

						}
						else
						{
							verts[1].x = x;verts[1].y = y;verts[1].z = z - 2;
							verts[2].x = x;verts[2].y = y - 2;verts[2].z = z - 2;

							tris.push_back({ verts[0],verts[2],verts[1] });

							verts[1].x = x;verts[1].y = y - 2;verts[1].z = z - 2;
							verts[2].x = x;verts[2].y = y - 2;verts[2].z = z;
							tris.push_back({ verts[0],verts[2],verts[1] });


						}
					}




				}

			}


		}
	}
};

//Matrix used for projection calculations
struct mat4x4 {
	float m[4][4] = { 0 };//Very important to initialize
};

class olcEngine3D : public olc::PixelGameEngine {
private:

	mesh meshCube;//instance of mesh
	mat4x4 matProj;//matrix used for projection calculations
	float fTheta;//angle value that determines rotation of cube
	vec3D vCamera;//placeholder Camera
	

	//Failed function to set colors
	/*void setColor(int s) {
		int c = 0;
		for (auto tri : meshCube.tris) {
			
			if (tri.p[0].x == tri.p[1].x == tri.p[2].x == s) {
				
			}
			else if (tri.p[0].x == tri.p[1].x == tri.p[2].x == -s) {

				tri.col[0] = 255;tri.col[1] = 165;tri.col[2] = 0;
			}
			else if (tri.p[0].z == tri.p[1].z == tri.p[2].z == s) {

				tri.col[0] = 0;tri.col[1] = 255;tri.col[2] = 0;
			}
			else if (tri.p[0].z == tri.p[1].z == tri.p[2].z == -s) {

				tri.col[0] = 0;tri.col[1] = 0;tri.col[2] = 255;
			}
			else if (tri.p[0].y == tri.p[1].y == tri.p[2].y == s) {

				tri.col[0] = 255;tri.col[1] = 255;tri.col[2] = 255;
			}
			else if (tri.p[0].y == tri.p[1].y == tri.p[2].y == -s) {

				tri.col[0] = 255;tri.col[1] = 255;tri.col[2] = 0;
			}
			else { tri.col[0] = 106;tri.col[1] = 13;tri.col[2] = 173; }
		
			meshCube.tris[0].col[0] = 106;
			meshCube.tris[0].col[1] = 13;
			meshCube.tris[0].col[2] = 173;
		}
	}*/



	//Function to multiply a vector by a matrix to give a vector
	void MultiplyMatrixVector(vec3D& i, vec3D& o, mat4x4& m) {
		o.x = i.x * m.m[0][0] + i.y * m.m[1][0] + i.z * m.m[2][0] + m.m[3][0];
		o.y = i.x * m.m[0][1] + i.y * m.m[1][1] + i.z * m.m[2][1] + m.m[3][1];
		o.z = i.x * m.m[0][2] + i.y * m.m[1][2] + i.z * m.m[2][2] + m.m[3][2];
		float w;//fourth vector element that is set to 1 at the end. Used to handle multiplication by a 4x4 matrix
		w = i.x * m.m[0][3] + i.y * m.m[1][3] + i.z * m.m[2][3] + m.m[3][3];
		//sets w to 1 by dividing vector by w. This gives us a 3D vector again
		if (w != 0) {
			o.x /= w;o.y /= w;o.z /= w;
		}
	}




public:
	olcEngine3D() {
		sAppName = "Cube";
	}
	bool OnUserCreate() override
	{
		vCamera = { 0,0,-200 };
		meshCube.setTris(3);
		//setColor(3);
		

		



		//Applying Projection 

		float fNear = 0.1f;//Screen from user
		float fFar = 1000.0f;//Object from screen
		float fFov = 90.0f;//Field of view
		float fAspectRatio = (float)ScreenHeight() / (float)ScreenWidth();//Aspect ratio
		float fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * 3.14159f);//For tangent calculations in radians

		//Setting these values in our projection matrix
		matProj.m[0][0] = fAspectRatio * fFovRad;
		matProj.m[1][1] = fFovRad;
		matProj.m[2][2] = fFar / (fFar - fNear);
		matProj.m[3][2] = (-fFar * fNear) / (fFar - fNear);
		matProj.m[2][3] = 1.0f;
		matProj.m[3][3] = 0.0f;


		return true;
	}
	bool OnUserUpdate(float fElapsedTime)override {

		FillRect(0, 0, ScreenWidth(), ScreenHeight(), olc::Pixel(86, 95, 107));//nice titanium gray

		mat4x4 matRotZ, matRotX;// Matricess used to rotate cube, so that we can fully realize it
		fTheta += 1.0f * fElapsedTime;//fTheta is constantly changing as a result of using Elapsed Time


		//Rotation Z
		matRotZ.m[0][0] = cosf(fTheta * 1.0f);
		matRotZ.m[0][1] = sinf(fTheta * 1.0f);
		matRotZ.m[1][0] = -sinf(fTheta * 1.0f);
		matRotZ.m[1][1] = cosf(fTheta * 1.0f);
		matRotZ.m[2][2] = 1;
		matRotZ.m[3][3] = 1;

		//Rotation X
		matRotX.m[0][0] = 1;
		matRotX.m[1][1] = cosf(fTheta * 0.5f);
		matRotX.m[1][2] = sinf(fTheta * 0.5f);
		matRotX.m[2][1] = -sinf(fTheta * 0.5f);
		matRotX.m[2][2] = cosf(fTheta * 0.5f);
		matRotX.m[3][3] = 1;

		//stores triangles to be sorted
		vector<triangle> vecTrianglesToRaster;

		//Drawing the triangles:

		for (auto tri : meshCube.tris) {//Goes through each triangle, tri, in meshCube

			triangle triProjected;//holds result of matrix multiplication
			triangle triTranslated;//hold translated matrix
			triangle triRotatedZ;//hold Z rotated triangle
			triangle triRotatedZX;//holds X rotated Z rotated triangle

			// ALL the following operations will be made efficient later on by operator overloading implemented in vec3D
			//Rotate triangle along Z axis
			MultiplyMatrixVector(tri.p[0], triRotatedZ.p[0], matRotZ);
			MultiplyMatrixVector(tri.p[1], triRotatedZ.p[1], matRotZ);
			MultiplyMatrixVector(tri.p[2], triRotatedZ.p[2], matRotZ);

			//Rotated triangle along X axis
			MultiplyMatrixVector(triRotatedZ.p[0], triRotatedZX.p[0], matRotX);
			MultiplyMatrixVector(triRotatedZ.p[1], triRotatedZX.p[1], matRotX);
			MultiplyMatrixVector(triRotatedZ.p[2], triRotatedZX.p[2], matRotX);



			//We need to Translate the cube before projecting it, so that the viewing origin may be different
			//to the cubes origin, thus we can add perspective to the cube by offsetting it

			triTranslated = triRotatedZX;
			triTranslated.p[0].z = triRotatedZX.p[0].z + 20.0f;
			triTranslated.p[1].z = triRotatedZX.p[1].z + 20.0f;
			triTranslated.p[2].z = triRotatedZX.p[2].z + 20.0f;

			//Setting Normal by finding cross product
			vec3D normal, line1, line2;

			line1.x = triTranslated.p[1].x - triTranslated.p[0].x;
			line1.y = triTranslated.p[1].y - triTranslated.p[0].y;
			line1.z = triTranslated.p[1].z - triTranslated.p[0].z;


			line2.x = triTranslated.p[2].x - triTranslated.p[0].x;
			line2.y = triTranslated.p[2].y - triTranslated.p[0].y;
			line2.z = triTranslated.p[2].z - triTranslated.p[0].z;

			normal.x = line1.y * line2.z - line1.z * line2.y;
			normal.y = line1.z * line2.x - line1.x * line2.z;
			normal.z = line1.x * line2.y - line1.y * line2.x;

			//normalizing normal to turn it into a unit vector
			float l = sqrtf(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
			normal.x /= l;normal.y /= l;normal.z /= l;


			//Finding dot product to compare our POV to the cube. If<0, that means the vector 
			//has a component facing us, and thus we render it
			if (normal.x * (triTranslated.p[0].x - vCamera.x) +
				normal.y * (triTranslated.p[0].y - vCamera.y) +
				normal.z * (triTranslated.p[0].z - vCamera.z) )
			{


				//Illumination and shading (We dont need currently)
				/*vec3D light_direction = {0.0f,0.0f,-1.0f};//z=-1 indicated light shining towards us
				//normalize light direction
				float l = sqrtf(light_direction.x * light_direction.x + light_direction.y * light_direction.y + light_direction.z * light_direction.z);
				light_direction.x /= l;light_direction.y /= l;light_direction.z /= l;

				//dot product of normal and light direction
					dp = normal.x * light_direction.x +
					normal.y * light_direction.y +
					normal.z * light_direction.z;
				if (dp < 0)dp = dp * -1;
				if (dp < (0.25))dp = 0.25;*/
				//Projecting all vertices of current triangle, from 3D to 2D, tri, and storng it in triProjected
				MultiplyMatrixVector(triTranslated.p[0], triProjected.p[0], matProj);
				MultiplyMatrixVector(triTranslated.p[1], triProjected.p[1], matProj);
				MultiplyMatrixVector(triTranslated.p[2], triProjected.p[2], matProj);

				//Right now, the matrix has been projected, but not Scaled into view. For that, We do the following:

				triProjected.p[0].x += 1.0f; triProjected.p[0].y += 1.0f;
				triProjected.p[1].x += 1.0f; triProjected.p[1].y += 1.0f;
				triProjected.p[2].x += 1.0f; triProjected.p[2].y += 1.0f;
				// now everything is between 0 and +2, so we need to half it to bring it between 0 and +1,
				//and bring it into screen width

				triProjected.p[0].x *= 0.5f * (float)ScreenWidth();
				triProjected.p[0].y *= 0.5f * (float)ScreenWidth();
				triProjected.p[1].x *= 0.5f * (float)ScreenWidth();
				triProjected.p[1].y *= 0.5f * (float)ScreenWidth();
				triProjected.p[2].x *= 0.5f * (float)ScreenWidth();
				triProjected.p[2].y *= 0.5f * (float)ScreenWidth();
				triProjected.col[0] = tri.col[0];
				triProjected.col[1] = tri.col[1];
				triProjected.col[2] = tri.col[2];


				//stores triangles to raster in order to sort them later
				vecTrianglesToRaster.push_back(triProjected);





			}


		}

		//Sort triangles back to front in terms of z axis. This makes the program wayyy smoother

		sort(vecTrianglesToRaster.begin(), vecTrianglesToRaster.end(), [](triangle& t1, triangle& t2)
			{
				//Avg z points for the triangles. swaps if z1>z2
				float z1 = (t1.p[0].z + t1.p[1].z + t1.p[2].z) / 3.0f;
				float z2 = (t2.p[0].z + t2.p[1].z + t2.p[2].z) / 3.0f;

				return z1 > z2;

			});
		for (auto& triProjected : vecTrianglesToRaster) {//loops thru triangles to raster now instead of unsorted list
			FillTriangle(triProjected.p[0].x, triProjected.p[0].y,
				triProjected.p[1].x, triProjected.p[1].y,
				triProjected.p[2].x, triProjected.p[2].y,
				olc::Pixel(255,255,255));

			DrawTriangle(triProjected.p[0].x, triProjected.p[0].y,
				triProjected.p[1].x, triProjected.p[1].y,
				triProjected.p[2].x, triProjected.p[2].y,
				olc::Pixel(0, 0, 0));
		}
		return true;
	}

};
int main()
{
	olcEngine3D demo;
	if (demo.Construct(512, 512, 2, 2))
		demo.Start();

	return 0;

}