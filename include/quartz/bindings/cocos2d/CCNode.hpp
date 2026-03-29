#pragma once

namespace quartz
{
namespace bindings
{
namespace __cocos2d
{

class __CCNode
{
public:
	__CCNode();
	~__CCNode() = default;
};

} // __cocos2d
} // bindings
} // quartz

// static instance that queues this lua binding at startup
// the binding is executed later after lua is initialized
static quartz::bindings::__cocos2d::__CCNode __ccnode__;