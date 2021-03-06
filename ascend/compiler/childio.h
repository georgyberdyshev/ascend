/*	ASCEND modelling environment
	Copyright (C) 1998 Carnegie Mellon University
	Copyright (C) 2006 Carnegie Mellon University

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2, or (at your option)
	any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*//** @file
	This is a package of routines to process child list I/O.
*//*
	by Ben Allan
	Last in CVS: $Revision: 1.3 $, $Date: 1998/06/11 17:36:23 $, $Author: ballan $
*/

#ifndef ASC_CHILDIO_H
#define ASC_CHILDIO_H

/**	@addtogroup compiler_inst Compiler Instance Hierarchy
	@{
*/

#include <ascend/general/platform.h>
#include "child.h"

/*
 *  WriteChildList(fp,cl)
 */
/**
 *  Write what is known at parse time about the children in the child list
 *  given.  What is known may be surprising. It may be only mildly
 *  accurate.
 */
ASC_DLLSPEC void WriteChildList(FILE *fp, ChildListPtr cl);

/**
 * Return a string containing buckets o'stuff about the nth child in list.
 * The string will make use of braces as necessary to delimit
 * items. What each item is will be subject to change according
 * to the meta-data given by WriteChildMetaDetails.
 * Items are booleans, integers or strings as explained below.<br><br>
 *
 * The string returned is the caller's responsibility.
 */
ASC_DLLSPEC char *WriteChildDetails(ChildListPtr cl, unsigned long n);

/**
 * Returns a string with fields brace delimited. Each field
 * describes the corresponding field of a WriteChildDetails
 * return string. The ordering and size may be expected to shift as
 * ASCEND evolves. The hope is that the contents of metas individual
 * fields will shift much more slowly than the ordering, number of
 * fields and so forth. Using metas, one can expect to write code
 * which survives changes in plain s.<br><br>
 *
 * The returned string is NOT yours to free. (safe to keep, though).
 * The format is one or more elements in braces like:  <br>
 * "{data} {data} {data}"                              <br>
 * where data is a triplet separated by - "name-ctype-{explanation}"
 * Name is a single string with no blanks,
 * ctype is boolean, integer, or string.
 * explanation is for human consumption and explains the field.
 */
ASC_DLLSPEC CONST char *WriteChildMetaDetails(void);

/**
 * Issues a child missing error to file if the same childname/scope
 * has not been missing since the last call with any NULL argument.
 */
ASC_DLLSPEC void WriteChildMissing(FILE *fp, char *scope, symchar *childname);

/* @} */

#endif  /* ASC_CHILDIO_H */

