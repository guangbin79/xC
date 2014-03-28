#include "../../include/sys_xfile.h"
#include "../include/sys_xfiledef.h"

void xsys_xfile_fEnumEnd(xsys_file_enum_t * pfe)
{
    delete pfe;
}
