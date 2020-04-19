#include "NetMsgCreateWO.h"
#ifdef AFTR_CONFIG_USE_BOOST

#include <iostream>
#include <sstream>
#include <string>
#include "AftrManagers.h"
#include "Vector.h"
#include "WO.h"
#include "GLView.h"
#include "WorldContainer.h"
#include "NetMsgAntGsSetback.h"
#include "Model.h"
#include "WOLight.h"
#include "GLViewNewModule.h"

using namespace Aftr;

//NetMsgMacroDefinition( NetMsgAntGsSetback );

NetMsgAntGsSetback::NetMsgAntGsSetback()
{
	this->antSetbackCourse = 0;
}

NetMsgAntGsSetback::~NetMsgAntGsSetback()
{
}

bool NetMsgAntGsSetback::toStream( NetMessengerStreamBuffer& os ) const
{
	os << this->string_size;
	for (size_t i = 0; i < string_size; i++)
	{

	}
	return true;
}

bool NetMsgAntGsSetback::fromStream( NetMessengerStreamBuffer& is )
{
	is >> this->antSetbackCourse;
	return true;
}

void NetMsgAntGsSetback::onMessageArrived()
{
	std::cout << this->toString() << std::endl;
}

std::string NetMsgAntGsSetback::toString() const
{
   std::stringstream ss;

   ss << NetMsg::toString();
   ss << " Data: Course Setback " << this->antSetbackCourse << "...\n";

   return ss.str();
}

#endif
