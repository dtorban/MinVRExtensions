/*
 * Copyright Regents of the University of Minnesota, 2014.  This software is released under the following license: http://opensource.org/licenses/lgpl-3.0.html.
 * Source code originally developed at the University of Minnesota Interactive Visualization Lab (http://ivlab.cs.umn.edu).
 *
 * Code author(s):
 * 		Dan Orban (dtorban)
 */

#include "plugin/Plugin.h"
#include <iostream>

class TestPlugin : public MinVR::Plugin {
public:
	PLUGIN_API TestPlugin() {
		std::cout << "TestPlugin created." << std::endl;
	}
	PLUGIN_API virtual ~TestPlugin() {
		std::cout << "TestPlugin destroyed." << std::endl;
	}
	PLUGIN_API bool registerPlugin(MinVR::PluginInterface *interface)
	{
		std::cout << "Registering TestPlugin with the following interface: " << interface->getName() << std::endl;
		return true;
	}
	PLUGIN_API bool unregisterPlugin(MinVR::PluginInterface *interface)
	{
		std::cout << "Unregistering TestPlugin with the following interface: " << interface->getName() << std::endl;

		return true;
	}
};

extern "C"
{
	PLUGIN_API MinVR::Plugin* loadPlugin() {
		return new TestPlugin();
	}
}
