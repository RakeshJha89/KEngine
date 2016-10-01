/**************************************************************************************************
KarmaEngine (OpenGL)
File Created/Modified On: "02/09/2016"
File Created by: "Rakesh Jha"
All rights reserved.
***************************************************************************************************/

#pragma once

namespace Karma
{
	//If the singleton design type changes later we need to change the static instance to be initialize using new/malloc.
	template <typename T> class SingletonTemplate
	{
	public:

		SingletonTemplate()
		{
			m_instance = static_cast<T*>(this);
		}

		~SingletonTemplate()
		{
			if (m_instance == this)
				m_instance = 0;
		}

		static T* GetInstance()
		{
			return m_instance;
		}

		static T& GetRefInstance()
		{
			return *m_Instance;
		}

	protected:
		SingletonTemplate(const SingletonTemplate&) {}
		SingletonTemplate& operator=(const SingletonTemplate&) {}

	private:
		static T* m_instance;
	};

	template <typename T> T* SingletonTemplate<T>::m_instance = 0;
}