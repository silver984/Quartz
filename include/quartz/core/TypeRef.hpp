#pragma once

namespace quartz
{

template <typename TYPE>
class TypeRef
{
public:
	explicit TypeRef(TYPE* ptr) : m_val(ptr) {}

	inline TYPE get() const
	{
		return *m_val;
	}

	inline void set(TYPE newVal)
	{
		if (m_val)
		{
			*m_val = newVal;
		}
	}

private:
	TYPE* m_val = nullptr;
};

} // quartz