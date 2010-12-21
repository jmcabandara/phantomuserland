/**
 *
 * Phantom OS
 *
 * Copyright (C) 2005-2010 Dmitry Zavalishin, dz@dz.ru
 *
 * Buses. Mostly unused.
 *
**/

#include "device.h"

phantom_bus_t etc_bus =
{
    "Unknown Bus", PHANTOM_BUS_TYPE_UNKNOWN,
    0, 0, 0,
};


phantom_bus_t pci_bus =
{
    "PCI Bus", PHANTOM_BUS_TYPE_PCI,
    0, 0, &etc_bus,
};


phantom_bus_t isa_bus =
{
    "ISA Bus", PHANTOM_BUS_TYPE_ISA,
    0, 0, &pci_bus,
};



phantom_bus_t root_bus =
{
    "Root Bus", PHANTOM_BUS_TYPE_ROOT,
    0, &isa_bus, 0,
};


// TODO kernel debugger cmd - list devs
