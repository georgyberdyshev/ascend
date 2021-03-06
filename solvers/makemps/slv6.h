/*
 *  MPS: Ascend MPS file generator
 *  by Craig Schmidt
 *  Created: 2/11/95
 *  Version: $Revision: 1.13 $
 *  Version control file: $RCSfile: slv6.h,v $
 *  Date last modified: $Date: 1997/07/18 12:16:23 $
 *  Last modified by: $Author: mthomas $
 *
 *  This file is part of the SLV solver.
 *
 *  Copyright (C) 1990 Karl Michael Westerberg
 *  Copyright (C) 1993 Joseph Zaher
 *  Copyright (C) 1994 Joseph Zaher, Benjamin Andrew Allan
 *  Copyright (C) 1995 Craig Schmidt
 *
 *  The SLV solver is free software; you can redistribute
 *  it and/or modify it under the terms of the GNU General Public License as
 *  published by the Free Software Foundation; either version 2 of the
 *  License, or (at your option) any later version.
 *
 *  The SLV solver is distributed in hope that it will be
 *  useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/** @file
 *  makeMPS solver registration module.
 *  <pre>
 *  Contents:     makeMPS module
 *
 *  Authors:      Karl Westerberg
 *                Joseph Zaher
 *
 *  Dates:        06/90 - original version
 *                04/91 - fine tuned modified marquadt computation,
 *                        provided minor iterations for step generation
 *                        within each major iteration of jacobian
 *                        updates
 *                06/93 - eliminated pointer sublists being generated
 *                        at the beginning of each block
 *                04/94 - extended scope to equality constrained
 *                        optimization.
 *
 *  Description:  This file is created by make_slv_header, so don't
 *                modify it yourself.  All functions defined in this
 *                header have identical protocols to the corresponding
 *                functions in slv.h except that slv_system_t ==>
 *                slv6_system_t and slv6_eligible_solver() only takes one
 *                parameter: the system.  Note also that the select
 *                solver functions don't exist.
 *  </pre>
 *  @todo makeMPS (solver/slv6.c) is out-of-date and will not compile.
 *        Should be either fixed or archived.
 *  @todo Restructure solver/slv6 & mps so can remove declarations in
 *        solver/slv6.h out of header.  Currently needed by mps.[ch].
 */

#ifndef ASC_SLV6_H
#define ASC_SLV6_H

#include <ascend/solver/solver.h>
#include <ascend/system/slv_client.h>

#include "mps_types.h"

typedef struct slv6_system_structure *slv6_system_t;

int slv6_register(SlvFunctionsT *sft);
/**<
 *  Registration function for the ASCEND makeMPS solver.
 *  This is the function that tells the system about the makeMPS solver.
 *  Our index is not necessarily going to be 6. That everything here is
 *  named slv6* is just a historical event.
 *
 *  @param sff SlvFunctionsT to receive the solver registration info.
 *  @return Returns non-zero on error (e.g. f == NULL), zero if all is ok.
 */

/* WOULD LIKE TO REMOVE EVERYTHING BELOW THIS POINT */
/* THIS DETAIL SHOULD BE IN SOURCE FILE, BUT IS NEEDED BY mps.[ch] */
/*
# if 0
*/
#define slv6_solver_name "makeMPS" /**< Solver's name. don't mess with the caps!*/
#define slv6_solver_number 6   /**< Solver's number */

extern boolean free_inc_var_filter(struct var_variable *var);
/**<
 ***  I've been calling this particular var filter a lot ,
 ***  so I decided to make it a subroutine.  Returns true if
 ***  var is not fixed and incident in something.
 **/

#if 0
extern void slv6_set_var_list();
extern struct var_variable **slv6_get_var_list();
extern void slv6_set_bnd_list();
extern void slv6_set_rel_list();
extern struct rel_relation **slv6_get_rel_list();
extern void slv6_set_extrel_list();
extern struct ExtRelCache **slv6_get_extrel_list();
extern int slv6_count_vars();
extern int slv6_count_bnds();
extern int slv6_count_rels();
extern void slv6_set_obj_relation();
extern struct rel_relation *slv6_get_obj_relation();
extern boolean slv6_eligible_solver();
extern void slv6_get_parameters();
extern void slv6_set_parameters();
extern void slv6_get_status();
//extern linsol_system_t slv6_get_linsol_sys();
extern void slv6_dump_internals();
extern void slv6_presolve();
extern boolean slv6_change_basis();
extern void slv6_resolve();
extern void slv6_iterate();
extern void slv6_solve();
#endif

/*********************************************************************
    Craig Schmidt 2/15/95

    This section describes the parameters, subparameters,
    and status flags as used by the solver.

    *** See slv6_create() for more specific information   ***
    *** on parameters and status flags                  ***

    *** Note: the parameters can be changed by the user ***
    ***       with the slv6_set_parameters routine      ***


    Use of subparameters in iarray and rarray:

    iarray[SP6_NONLIN]   0->require linear model,
                         1->solve linearization at current pt
    iarray[SP6_RELAXED]  0->solve regular problem
                         1->solve LP relaxation of problem
    iarray[SP6_NONNEG]   0->solver handles free vars
                         1->solver requires that all vars have LB=0, UB=infinity, no FR or MI
    iarray[SP6_OBJ]      0->solver assumes minimization, do nothing special
                         1->solver assumes maximization, swap obj coeff for min problems
                         2->solver support SCICONIC style MINIMIZE
                         3->solver supports QOMILP style MAX/MIN in names section
    iarray[SP6_BINARY]   0->solver supports binary variables using INTORG
                         1->solver supports binary variables with BV option in BOUNDS
                         2->no support
    iarray[SP6_INTEGER]  0->solver defines integer vars using INTORG
                         1->solver defines integer vars using UI in BOUNDS
                         2->no support for integer vars
    iarray[SP6_SEMI]     0->no support
                         1->solver supports SCICONIC style semi-continuous vars
    iarray[SP6_SOS1]     0->no support
                         1->solver supports SOS1, i.e. sum(Xi)  = 1
    iarray[SP6_SOS2]     0->no support
                         1->solver supports SOS2, i.e. sum(xi) <=2, with 2 nonzeros being adjacent
                         Note: this parameter currently ignored, no support offered for type 2
    iarray[SP6_SOS3]     0->no support
                         1->solver supports SOS3, i.e.  sum(xi) <= 1
    iarray[SP6_BO]       0->no support
                         1->solver supports QOMILP style BO cutoff bound in names section
                         Note: value of bound is in rarray[SP6_BNDVAL]
    iarray[SP6_EPS]      0->no support
                         1->solver supports QOMILP style EPS termination criterion
                         Note: value of bound is in rarray[SP6_EPSVAL]

    rarray[SP6_BOVAL]    value of QOMILP style BO cutoff bound in names section
                         Note: Ignored if iarray[SP6_BO]=0
    rarray[SP6_EPSVAL]   value of QOMILP style EPS termination criterion
                         Note: Ignored if iarray[SP6_EPS]=0
    rarray[SP6_PINF]     any UB >= pinf is set to + infinity
    rarray[SP6_MINF]     any LB <= minf is set to - infinity

    carray[SP6_FILENAME] pointer to filename to create

*********************************************************************/
#if 0
#define slv6_IA_SIZE 12
#define slv6_RA_SIZE 4
#define slv6_CA_SIZE 1
#define slv6_VA_SIZE 0

/**< subscripts for ia */
#define SP6_NONLIN   0
#define SP6_RELAXED  1
#define SP6_NONNEG   2
#define SP6_OBJ      3
#define SP6_BINARY   4
#define SP6_INTEGER  5
#define SP6_SEMI     6
#define SP6_SOS1     7
#define SP6_SOS2     8
#define SP6_SOS3     9
#define SP6_BO       10
#define SP6_EPS      11

/**< subscripts for ra */
#define SP6_BOVAL   0
#define SP6_EPSVAL  1
#define SP6_PINF    2
#define SP6_MINF    3

/**< subscripts for ca */
#define SP6_FILENAME 0
#endif


enum{
	/** ASCEND OPTIONS */
	ASCEND_PARAM_SAFEEVAL = 0
	/**< integer-valued */
	, SP6_NONLIN
	, SP6_RELAXED
	, SP6_NONNEG
	, SP6_OBJ
	, SP6_BINARY
	, SP6_INTEGER
	, SP6_SEMI
	, SP6_SOS1
	, SP6_SOS2
	, SP6_SOS3
	, SP6_BO
	, SP6_EPS
	/* real-valued */
	, SP6_BOVAL
	, SP6_EPSVAL
	, SP6_PINF
	, SP6_MINF
	/* string-valued */
	, SP6_FILENAME
	, SP6_PARAMS
};

/**< define another token to go with
   rel_TOK_less, rel_TOK_equal, and rel_TOK_greater,
   defined in rel.h */
#define rel_TOK_nonincident 00

#endif  /* ASC_SLV6_H */

