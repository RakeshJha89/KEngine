/**************************************************************************************************
KarmaEngine (OpenGL)
File Created/Modified On: "16/09/2016"
File Created by: "Rakesh Jha"
All rights reserved.
***************************************************************************************************/
#pragma once
#include "KMacro.h"

namespace Karma
{
    class Vector3
    {
    public:
        Vector3()
        {
            Zero();
        }

        Vector3(float _x, float _y, float _z)
            :x(_x), y(_y), z(_z)
        {
        }

        Vector3(const Vector3& _ref)
            :x(_ref.x), y(_ref.y), z(_ref.z)
        {
        }

        void Set(float _x, float _y, float _z) { x = _x, y = _y, z = _z; }
        virtual void Zero() { x = y = z = 0; }
        virtual void Identity() { x = y = z = 1; }

        void Invert() { x *= -1, y *= -1, z *= -1; }
        Vector3 Normalize() { return Vector3((x == 0 ? 0 : x / Magnitude()), (y == 0 ? 0 : y / Magnitude()), (z == 0 ? 0 : z / Magnitude())); }

        Vector3 ProjectionVector(Vector3& planeNorm)
        {
            Vector3 normal = planeNorm.Normalize();
            return normal * this->Dot(normal);
        }

        Vector3 ReflectionVector(Vector3& planeNorm)
        {
            Vector3 projectionVector = ProjectionVector(planeNorm);
            return *this - projectionVector * 2;
        }

        
        void FORCEINLINE operator()(const Vector3& rhs) { x = rhs.x, y = rhs.y, z = rhs.z; }
        Vector3 FORCEINLINE operator+(const Vector3& rhs) { return Vector3(x + rhs.x, y + rhs.y, z + rhs.z); }
        Vector3 FORCEINLINE operator-(const Vector3& rhs) { return Vector3(x - rhs.x, y - rhs.y, z - rhs.z); }
        Vector3 FORCEINLINE operator*(const float scale) { return Vector3(x * scale, y * scale, z * scale); }
        Vector3 FORCEINLINE operator+=(const Vector3& rhs) { x + rhs.x, y + rhs.y, z + rhs.z; return *this; }

        Vector3 Cross(const Vector3& rhs)
        {
            return Vector3(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x);
        }

        float Dot(const Vector3& rhs)
        {
            return x*rhs.x + y*rhs.y + z*rhs.z;
        }

        float Magnitude()
        {
            return max(MIN_FLOAT_THRESHOLD, sqrt(x*x + y*y + z*z));
        }

        float x, y, z;
    };


    class Vector4 : public Vector3
    {
    public:
        Vector4()
        {
        }

        Vector4(float _x, float _y, float _z, float _w)
        {
            x = _x;	y = _y;	z = _z;	w = _w;
        }

        Vector4(const Vector4& _ref)
            : Vector3(_ref.x, _ref.y, _ref.z), w(_ref.w)
        {
        }

        void Set(float _x, float _y, float _z, float _w)
        {
            Vector3::Set(_x, _y, _z);
            w = _w;
        }

        void Zero() override
        {
            Vector3::Zero();
            w = 0;
        }

        void Identity() override
        {
            Vector3::Identity();
            w = 1;
        }

        float w;
    };

}