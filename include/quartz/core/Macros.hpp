#pragma once
#define FUNCTION(CLASS, FN)		[](CLASS* self, auto... args) { return self->CLASS::FN(args...); }
#define HOOK_PRIO(CLASS, FN)	quartz::enableHookPriority(self, #CLASS "::" #FN)