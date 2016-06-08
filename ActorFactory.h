#pragma once

class Actor;
class ActorFactory
{
public:
	ActorFactory();
	~ActorFactory();

	Actor blob();
};

