#pragma once

namespace
{
	class C
	{
	public:
		const char * msg()
		{
			return "msg";
		}
	};
}

static int d;

class B
{
	C c;
public:
	B()
	{

	}

};




