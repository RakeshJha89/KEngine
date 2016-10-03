#pragma once
//Define various Action types.
#include <iostream>

template<typename T>
class ActionBind;

template <typename T, typename ReturnType, typename... FuncArgs>
class ActionBind<ReturnType (T::*) (FuncArgs...)>
{
	typedef ReturnType (T::*FuncPtr)( FuncArgs...);
public:
	
	ActionBind( FuncPtr function, T& callee )
	: m_functionCallback(function),
	  m_callee(callee) {}

	ReturnType operator()(FuncArgs... fnArgs) const
	{
		return (m_callee.*m_functionCallback)( fnArgs...);
	}

private:
	T& m_callee;
	FuncPtr m_functionCallback;

};

//Specialized for global functions.
template <typename ReturnType, typename... FuncArgs>
class ActionBind<ReturnType (*) (FuncArgs...)>
{
	typedef ReturnType (*FuncPtr) ( FuncArgs...);
public:

	ActionBind(FuncPtr function)
		: m_functionCallback(function) {}

	ReturnType operator()(FuncArgs... fnArgs) const
	{
		return (*m_functionCallback)(fnArgs...);
	}

private:
	FuncPtr m_functionCallback;
};


template<typename ReturnType, typename T>
ActionBind<ReturnType>	WrapAction(ReturnType funcPtr, T& objRef)
{
	return ActionBind<ReturnType>(funcPtr, objRef);
}

template<typename ReturnType>
ActionBind<ReturnType>	WrapAction(ReturnType funcPtr)
{
	return ActionBind<ReturnType>(funcPtr);
}

#define ACTIONBIND WrapAction
//#define ACTIONBINDGLOBAL WrapAction;
