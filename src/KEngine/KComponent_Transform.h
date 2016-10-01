#pragma once
#include "KComponentBase.h"
#include "KMatrix.h"

namespace Karma
{
    class Component_Transform : public ComponentBase
    {
    public:
        void Initialize() override {}
        void Update() override {}
        void Terminate() override {}

        Vector3 FORCEINLINE GetPosition()
        {
            return Vector3(m_internalMatrix[0].w, m_internalMatrix[1].w, m_internalMatrix[2].w);
        }

        void FORCEINLINE    SetPosition(Vector3& _pos)
        {
            Vector4 xx(m_internalMatrix[0]), yy(m_internalMatrix[1]), zz(m_internalMatrix[2]), ww(m_internalMatrix[3]);
            xx.w = _pos.x;
            yy.w = _pos.y;
            zz.w = _pos.z;
            m_internalMatrix.Set(xx, yy, zz, ww);
        }

    private:
        Matrix4x4 m_internalMatrix;
    };
}