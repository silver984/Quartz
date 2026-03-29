#pragma once

namespace quartz
{
namespace bindings
{

class __PlayerObject
{
public:
	__PlayerObject();
	~__PlayerObject() = default;
};

} // bindings
} // quartz

// static instance that queues this lua binding at startup
// the binding is executed later after lua is initialized
static quartz::bindings::__PlayerObject __playerobject__;