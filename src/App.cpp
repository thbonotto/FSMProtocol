#include "Context.h"
#include "Events.h"

int main(){
	Context c{new State0};
	Event e;
	e.eventId = 0;
	c.Request(e);
	c.Request(e);
	c.Request(e);
	c.Request(e);
	c.Request(e);
}
