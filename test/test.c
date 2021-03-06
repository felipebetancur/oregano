#include <glib.h>

// may be already defined, if not:
#ifndef DEBUG_FORCE_FAIL
#define DEBUG_FORCE_FAIL 0
#endif


#include "test_wire.c"
#include "test_engine.c"
#include "test_nodestore.c"

#if DEBUG_FORCE_FAIL
void
test_false ()
{
	g_assert (FALSE==TRUE);
}
#endif


int
main (int argc, char *argv[])
{
#if !(GLIB_CHECK_VERSION(2,36,0))
	g_type_init();
#endif

	g_test_init (&argc, &argv, NULL);

	g_test_add_func ("/core/coords", test_coords);
	g_test_add_func ("/core/model/wire/intersection", test_wire_intersection);
	g_test_add_func ("/core/model/wire/tcrossing", test_wire_tcrossing);
	g_test_add_func ("/core/model/nodestore", test_nodestore);
	g_test_add_func ("/core/engine", test_engine);
#if DEBUG_FORCE_FAIL
	g_test_add_func ("/false", test_false);
#endif
	return g_test_run ();
}
