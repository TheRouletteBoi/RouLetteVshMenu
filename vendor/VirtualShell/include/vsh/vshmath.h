#ifndef __MATH_H__
#define __MATH_H__
#include "vshtypes.h"
#include "stdc.h"
#include <math.h>

_VSH_BEGIN

class vec2
{
public:
   union
   {
      float v[2];
      struct { float x, y; };
   };

   vec2()
   {
      this->x = this->y = 0;
   }

   vec2(float x, float y)
   {
      this->x = x;
      this->y = y;
   }

   vec2(float vec[2])
   {
      if (vec != 0)
      {
         this->x = vec[0];
         this->y = vec[1];
      }
      else
      {
         this->x = this->y = 0;
      }
   }

   vec2 operator+(const vec2 vec)
   {
      return vec2(this->x + vec.x, this->y + vec.y);
   }

   vec2 operator+(const float* vec)
   {
      return vec2(this->x + vec[0], this->y + vec[1]);
   }

   vec2 operator-(const vec2 vec)
   {
      return vec2(this->x - vec.x, this->y - vec.y);
   }

   vec2 operator-(const float* vec)
   {
      return vec2(this->x - vec[0], this->y - vec[1]);
   }

   vec2 operator-() const
   {
      return vec2(-x, -y);
   }

   vec2 operator*(const vec2 vec)
   {
      return vec2(this->x * vec.x, this->y * vec.y);
   }

   vec2 operator*(const float scalar)
   {
      return vec2(this->x * scalar, this->y * scalar);
   }

   void operator-=(const vec2 vec)
   {
      this->x -= vec.x;
      this->y -= vec.y;
   }

   void operator+=(const vec2 vec)
   {
      this->x += vec.x;
      this->y += vec.y;
   }

   void operator*=(const vec2 vec)
   {
      this->x *= vec.x;
      this->y *= vec.y;
   }

   void operator*=(const float scalar)
   {
      this->x *= scalar;
      this->y *= scalar;
   }

   bool operator==(const vec2 vec)
   {
      return (this->x == vec.x && this->y == vec.y);
   }

   bool operator==(const float value)
   {
      return (this->x == value && this->y == value);
   }

   bool operator!=(const vec2 vec)
   {
      return !operator==(vec);
   }

   bool operator!=(const float value)
   {
      return !operator==(value);
   }

   operator float* ()
   {
      return (float*)&this[0];
   }

   vec2& clamp(float min, float max)
   {
      this->x = (this->x > max) ? max : (this->x < min) ? min : this->x;
      this->y = (this->y > max) ? max : (this->y < min) ? min : this->y;
      return *this;
   }
};

class vec3
{
public:
   union
   {
      float v[3];
      struct { float x, y, z; };
      struct { float pitch, yaw, roll; };
   };

   vec3()
   {
      this->x = this->y = this->z = 0;
   }

   vec3(float x, float y, float z)
   {
      this->x = x;
      this->y = y;
      this->z = z;
   }

   vec3(float vec[3])
   {
      if (vec != 0)
      {
         this->x = vec[0];
         this->y = vec[1];
         this->z = vec[2];
      }
      else
      {
         this->x = this->y = this->z = 0;
      }
   }

   vec3 operator+(const vec3 vec)
   {
      return vec3(this->x + vec.x, this->y + vec.y, this->z + vec.z);
   }

   vec3 operator+(const float* vec)
   {
      return vec3(this->x + vec[0], this->y + vec[1], this->z + vec[2]);
   }

   vec3 operator-(const vec3 vec)
   {
      return vec3(this->x - vec.x, this->y - vec.y, this->z - vec.z);
   }

   vec3 operator-(const float* vec)
   {
      return vec3(this->x - vec[0], this->y - vec[1], this->z - vec[2]);
   }

   vec3 operator-() const
   {
      return vec3(-x, -y, -z);
   }

   vec3 operator*(const vec3 vec)
   {
      return vec3(this->x * vec.x, this->y * vec.y, this->z * vec.z);
   }

   vec3 operator*(const float scalar)
   {
      return vec3(this->x * scalar, this->y * scalar, this->z * scalar);
   }

   void operator-=(const vec3 vec)
   {
      this->x -= vec.x;
      this->y -= vec.y;
      this->z -= vec.z;
   }

   void operator+=(const vec3 vec)
   {
      this->x += vec.x;
      this->y += vec.y;
      this->z += vec.z;
   }

   void operator*=(const vec3 vec)
   {
      this->x *= vec.x;
      this->y *= vec.y;
      this->z *= vec.z;
   }

   void operator*=(const float scalar)
   {
      this->x *= scalar;
      this->y *= scalar;
      this->z *= scalar;
   }

   bool operator==(const vec3 vec)
   {
      return (this->x == vec.x && this->y == vec.y && this->z == vec.z);
   }

   bool operator==(const float value)
   {
      return (this->x == value && this->y == value && this->z == value);
   }

   bool operator!=(const vec3 vec)
   {
      return !operator==(vec);
   }

   bool operator!=(const float value)
   {
      return !operator==(value);
   }

   operator float* ()
   {
      return (float*)&this[0];
   }

   vec3 forward(float x)
   {
      float div = M_PI / 180.0f;

      float angle = this->y * div;
      float sy = vsh::f_sinf(angle);
      float cy = vsh::f_cosf(angle);

      angle = this->x * div;
      float sp = vsh::f_sinf(angle);
      float cp = vsh::f_cosf(angle);

      return vec3(cp * cy * x, cp * sy * x, -sp * x);
   }

   vec3 normalize()
   {
      vec3 newvec;
      newvec.x = this->x / length();
      newvec.y = this->y / length();
      newvec.z = this->z / length();
      return newvec;
   }

   float distance(vec3 vec)
   {
      float _x = this->x - vec.x;
      float _y = this->y - vec.y;
      float _z = this->z - vec.z;
      return vsh::sqrtf((_x * _x) + (_y * _y) + (_z * _z));
   }

   float length()
   {
      return (float)vsh::sqrtf(x * x + y * y + z * z);
   }

   void vectors(vec3* forward, vec3* right, vec3* up)
   {
      float angle;
      float sr, sp, sy, cr, cp, cy;

      angle = this->y * (M_PI * 2.0f / 360.0f);
      sy = vsh::f_sinf(angle);
      cy = vsh::f_cosf(angle);

      angle = this->x * (M_PI * 2.0f / 360.0f);
      sp = vsh::f_sinf(angle);
      cp = vsh::f_cosf(angle);

      angle = this->z * (M_PI * 2.0f / 360.0f);
      sr = vsh::f_sinf(angle);
      cr = vsh::f_cosf(angle);

      if (forward)
      {
         forward->x = cp * cy;
         forward->y = cp * sy;
         forward->z = -sp;
      }
      if (right)
      {
         right->x = (-1 * sr * sp * cy + -1 * cr * -sy);
         right->y = (-1 * sr * sp * sy + -1 * cr * cy);
         right->z = -1 * sr * cp;
      }
      if (up)
      {
         up->x = (cr * sp * cy + -sr * -sy);
         up->y = (cr * sp * sy + -sr * cy);
         up->z = cr * cp;
      }
   }

   vec3& clamp(float min, float max)
   {
      this->x = (this->x > max) ? max : (this->x < min) ? min : this->x;
      this->y = (this->y > max) ? max : (this->y < min) ? min : this->y;
      this->z = (this->z > max) ? max : (this->z < min) ? min : this->z;
      return *this;
   }
};

class vec4
{
public:
   union
   {
      float v[4];
      struct { float x, y, z, w; };
      struct { float r, g, b, a; };
   };

   vec4()
   {
      this->x = this->y = this->z = this->w = 0;
   }

   vec4(float x, float y, float z, float w)
   {
      this->x = x;
      this->y = y;
      this->z = z;
      this->w = w;
   }

   vec4(float vec[4])
   {
      if (vec != 0)
      {
         this->x = vec[0];
         this->y = vec[1];
         this->z = vec[2];
         this->w = vec[3];
      }
      else
      {
         this->x = this->y = this->z = this->w = 0;
      }
   }

   vec4 operator+(const vec4 vec)
   {
      return vec4(this->x + vec.x, this->y + vec.y, this->z + vec.z, this->w + vec.w);
   }

   vec4 operator+(const float* vec)
   {
      return vec4(this->x + vec[0], this->y + vec[1], this->z + vec[2], this->w + vec[3]);
   }

   vec4 operator-(const vec4 vec)
   {
      return vec4(this->x - vec.x, this->y - vec.y, this->z - vec.z, this->w - vec.w);
   }

   vec4 operator-(const float* vec)
   {
      return vec4(this->x - vec[0], this->y - vec[1], this->z - vec[2], this->w - vec[3]);
   }

   vec4 operator-() const
   {
      return vec4(-x, -y, -z, -w);
   }

   vec4 operator*(const vec4 vec)
   {
      return vec4(this->x * vec.x, this->y * vec.y, this->z * vec.z, this->w * vec.w);
   }

   vec4 operator*(const float scalar)
   {
      return vec4(this->x * scalar, this->y * scalar, this->z * scalar, this->w * scalar);
   }

   void operator-=(const vec4 vec)
   {
      this->x -= vec.x;
      this->y -= vec.y;
      this->z -= vec.z;
      this->w -= vec.w;
   }

   void operator+=(const vec4 vec)
   {
      this->x += vec.x;
      this->y += vec.y;
      this->z += vec.z;
      this->w += vec.w;
   }

   void operator*=(const vec4 vec)
   {
      this->x *= vec.x;
      this->y *= vec.y;
      this->z *= vec.z;
      this->w *= vec.w;
   }

   void operator*=(const float scalar)
   {
      this->x *= scalar;
      this->y *= scalar;
      this->z *= scalar;
      this->w *= scalar;
   }

   bool operator==(const vec4 vec)
   {
      return (this->x == vec.x && this->y == vec.y && this->z == vec.z && this->w == vec.w);
   }

   bool operator==(const float value)
   {
      return (this->x == value && this->y == value && this->z == value && this->w == value);
   }

   bool operator!=(const vec4 vec)
   {
      return !operator==(vec);
   }

   bool operator!=(const float value)
   {
      return !operator==(value);
   }

   operator float* ()
   {
      return (float*)&this[0];
   }

   vec4& clamp(float min, float max)
   {
      this->x = (this->x > max) ? max : (this->x < min) ? min : this->x;
      this->y = (this->y > max) ? max : (this->y < min) ? min : this->y;
      this->z = (this->z > max) ? max : (this->z < min) ? min : this->z;
      this->w = (this->w > max) ? max : (this->w < min) ? min : this->w;
      return *this;
   }
};

_VSH_END

#endif // __MATH_H__