#ifndef __SINGLETON_H__
#define __SINGLETON_H__

template <typename T>
class SSingleton
{
public:
	static T* getInstance()
	{
		static T* instance = nullptr;
		if (!instance)
			instance = new T();
		return instance;
	}
protected:
	SSingleton() {}
	~SSingleton() {}
public:
	SSingleton(SSingleton const &) = delete; //??
	SSingleton& operator=(SSingleton const &) = delete; //??
};

#endif // !__SINGLETON_H__
