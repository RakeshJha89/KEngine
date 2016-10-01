#pragma once
#include "KVector.h"

namespace Karma
{
    class Matrix4x4
    {
    public:

        const Vector4& operator[](int _index) const
        {
            ASSERT_CHECK(_index < 4)
                return m_internalVec[_index];
        }

        FORCEINLINE void setIdentity()
        {
            Set(1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1);
        }

        Matrix4x4()
        {
            for (auto var : m_internalVec)
                var.Zero();
        }

        /*
            Matrix4x4 representation in memory

            00, 01, 02, 03      xx, xy, xz, xw
            10, 11, 12, 13      yx, yy, yz, yw
            20, 21, 22, 23      zx, zy, zz, zw
            30, 31, 32, 33      wx, wy, wz, ww
        */

        Matrix4x4(Vector4 _r0, Vector4 _r1, Vector4 _r2, Vector4 _r3)
        {
            Set (_r0.x, _r0.y, _r0.z, _r0.w,
                 _r1.x, _r1.y, _r1.z, _r1.w,
                 _r2.x, _r2.y, _r2.z, _r2.w,
                 _r3.x, _r3.y, _r3.z, _r3.w
                );
        }

        Matrix4x4(const Matrix4x4& _ref)
        {
            Vector4 xx(_ref[0]); 
            Vector4 yy(_ref[1]); 
            Vector4 zz(_ref[2]); 
            Vector4 ww(_ref[3]);
            Set(xx.x, xx.y, xx.z, xx.w,
                yy.x, yy.y, yy.z, yy.w,
                zz.x, zz.y, zz.z, zz.w,
                ww.x, ww.y, ww.z, ww.w);
        }

        void operator=(const Matrix4x4& _ref)
        {
            Vector4 xx(_ref[0]), yy(_ref[1]), zz(_ref[2]), ww(_ref[3]);
            Set(xx.x, xx.y, xx.z, xx.w,
                yy.x, yy.y, yy.z, yy.w,
                zz.x, zz.y, zz.z, zz.w,
                ww.x, ww.y, ww.z, ww.w);
        }

        void Set(Vector4 _r0, Vector4 _r1, Vector4 _r2, Vector4 _r3)
        {
            Set(_r0.x, _r0.y, _r0.z, _r0.w,
                _r1.x, _r1.y, _r1.z, _r1.w,
                _r2.x, _r2.y, _r2.z, _r2.w,
                _r3.x, _r3.y, _r3.z, _r3.w
            );
        }

        void Set(float _m00, float _m01, float _m02, float _m03,
                 float _m10, float _m11, float _m12, float _m13,
                 float _m20, float _m21, float _m22, float _m23,
                 float _m30, float _m31, float _m32, float _m33
                )
        {
            m_internalVec[0].Set(_m00, _m01, _m02, _m03);
            m_internalVec[1].Set(_m10, _m11, _m12, _m13);
            m_internalVec[2].Set(_m20, _m21, _m22, _m23);
            m_internalVec[3].Set(_m30, _m31, _m32, _m33);
        }        

    private:
        Vector4 m_internalVec[4];
    };
}