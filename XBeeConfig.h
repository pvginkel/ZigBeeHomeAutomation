#pragma once

#include "arduino.h"
#include <XBee.h>
#include <LinkedList.h>
#include "support.h"

void buildResetCommands(LinkedList<AtCommandRequest>& commands);
void buildRetrieveConfigurationCommands(LinkedList<AtCommandRequest>& commands);
