#include "systemc.h"
#include "driver.h"
#include "mux.h"
#include "monitor.h"

int main(int argc, char * argv[])
{
sc_in<bool> i0, i1, i2, i3, s1, s0;

