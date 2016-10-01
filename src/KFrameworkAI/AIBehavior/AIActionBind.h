#pragma once
//Define various Action types.

#include "AICommon.h"


template <typename ReturnType, typename... FuncArgs>
class ActionBind
{
	typedef ReturnType(*FuncPtr)(void* callee, FuncArgs...);
public:
	
	ActionBind(void* callee, FuncPtr function)
	: m_callee(callee),
	  m_functionCallback(function){}


	template<class T, ReturnType (T::*TMethod)(FuncArgs...)>
	static ActionBind BindFunction(T* callee)
	{
		ActionBind actionBind(callee, &CallBindMethod < T, TMethod>);
		return actionBind;
	}

	ReturnType operator()(FuncArgs... fnArgs) const
	{
		return (*m_functionCallback)(m_callee, fnArgs...);
	}

private:
	void* m_callee;
	FuncPtr m_functionCallback;

	template<class T, ReturnType(T::*TMethod)(FuncArgs...)>
	static ReturnType CallBindMethod(void* callee, FuncArgs... fnArgs)
	{
		T* classPtr = static_cast<T*>(callee);
		return (classPtr->*TMethod)(fnArgs...);
	}
};

template<typename T, typename ReturnType, typename... FuncArgs>
struct DelegateWrapper
{
	template<ReturnType (T::*FuncPtr)(FuncArgs...)>
	static ReturnType BindCaller(void* callee, FuncArgs... funcArgs)
	{
		return (static_cast<T*>(callee)->*FuncPtr)(funcArgs...);
	}

	template<ReturnType(T::*FuncPtr)(FuncArgs...)>
	inline static ActionBind<ReturnType, FuncArgs...> BindFunc(T* callee)
	{
		return ActionBind<ReturnType, FuncArgs...>(callee, &DelegateWrapper::BindCaller<FuncPtr>);
	}
};

template<typename T, typename ReturnType, typename... FuncArgs>
DelegateWrapper<T, ReturnType, FuncArgs...>	WrapDelegate(ReturnType (T::*)(FuncArgs...))
{
	return DelegateWrapper<T, ReturnType, FuncArgs...>();
}

#define ACTIONBIND(methodRef, objectRef)	(WrapDelegate(methodRef).BindFunc<methodRef>(objectRef));
