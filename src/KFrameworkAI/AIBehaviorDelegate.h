#pragma once
//Define various Action types.
#include <iostream>
//#include <functional>

template<typename T, typename ReturnType, typename... Args>
using TFuncPtr = ReturnType(T::*) (Args...);

template<typename ReturnType, typename... Args>
using TFuncPtrG = ReturnType(*) (Args...);

template<typename... T>
class BehaviorDelegate;

template <typename T, typename ReturnType, typename... FuncArgs>
class BehaviorDelegate<ReturnType (T::*) (FuncArgs...)>
{
    using FuncPtr = ReturnType (T::*)( FuncArgs...);
public:

    BehaviorDelegate()
        :m_functionCallback(nullptr), m_callee(nullptr)
    {}
    
    BehaviorDelegate( typename FuncPtr function, T* callee )
    : m_functionCallback(function),
      m_callee(callee) {}

    BehaviorDelegate(const BehaviorDelegate& action)
    {
        m_callee = action.m_callee;
        m_functionCallback = action.m_functionCallback;
    }

    void operator=(const BehaviorDelegate& action)
    {
        m_callee = action.m_callee;
        m_functionCallback = action.m_functionCallback;
    }

    ReturnType operator()(FuncArgs... fnArgs) const
    {
        return (m_callee->*m_functionCallback)( fnArgs...);
    }


private:
    T* m_callee;
    FuncPtr m_functionCallback;

};

//Specialized for global functions.
template <typename ReturnType, typename... FuncArgs>
class BehaviorDelegate<ReturnType (*) (FuncArgs...)>
{
    using FuncPtr = ReturnType (*) ( FuncArgs...);
public:

    BehaviorDelegate()
        :m_functionCallback(nullptr){}

    BehaviorDelegate(typename FuncPtr function)
        : m_functionCallback(function) {}

    BehaviorDelegate(const BehaviorDelegate& action)
    {
        m_functionCallback = action.m_functionCallback;
    }

    void operator=(const BehaviorDelegate& action)
    {
        m_functionCallback = action.m_functionCallback;
    }

    ReturnType operator()(FuncArgs... fnArgs) const
    {
        return (*m_functionCallback)(fnArgs...);
    }
    
private:
    FuncPtr m_functionCallback;
};


template<typename ReturnType, typename T>
BehaviorDelegate<ReturnType>  WrapAction(ReturnType funcPtr, T* objRef)
{
    return BehaviorDelegate<ReturnType>(funcPtr, objRef);
}

template<typename ReturnType>
BehaviorDelegate<ReturnType>  WrapAction(ReturnType funcPtr)
{
    return BehaviorDelegate<ReturnType>(funcPtr);
}

#define ACTIONBIND WrapAction
