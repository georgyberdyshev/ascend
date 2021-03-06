/*	ASCEND modelling environment
	Copyright (C) 2007 Carnegie Mellon University

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
	Dense matrix module, as used by the LSODE Integrator in ASCEND.

	@example
	Usage of the DenseMatrix object:

	@code
		DenseMatrix M;
		M = densmatrix_create(2,2);
		DENSEMATRIX_ELEM(M,0,0) = 1;
		DENSEMATRIX_ELEM(M,0,1) = 2;
		DENSEMATRIX_ELEM(M,1,0) = 3;
		DENSEMATRIX_ELEM(M,1,1) = 4;
		densematrix_write_mmio(M,stdout);
		densematrix_destroy(M);
	@endcode

	Represents the matrix

	@code
	[ 1, 2;
	  3, 4 ]
	@code
	@endexample
*//*
	by John Pye, Jan 2007. Pulled out the routines from lsode.c and added
	a file export function so that these matrices can be viewed using outside
	tools.

	Also using these routines in the external methods 'finitediff' and 'sensitivity'.
*/
#ifndef ASC_DENSEMTX_H
#define ASC_DENSEMTX_H

#include <stdio.h>

#include <ascend/utilities/config.h>
#include <ascend/general/platform.h>

/**	@addtogroup linear Linear
	@{
*/

typedef struct DenseMatrixStruct{
	double **data;
	unsigned nrows;
	unsigned ncols;
} DenseMatrix;

#define DENSEMATRIX_NROWS(M)    ((M).nrows)
#define DENSEMATRIX_NCOLS(M)    ((M).ncols)
#define DENSEMATRIX_ELEM(M,I,J) ((M).data[I][J])
#define DENSEMATRIX_DATA(M)     ((M).data)
#define DENSEMATRIX_EMPTY       (DenseMatrix){NULL,0,0}

ASC_DLLSPEC DenseMatrix densematrix_create_empty();
ASC_DLLSPEC DenseMatrix densematrix_create(unsigned nrows, unsigned ncols);
ASC_DLLSPEC void densematrix_destroy(DenseMatrix matrix);

#ifdef ASC_WITH_MMIO
ASC_DLLSPEC void densematrix_write_mmio(DenseMatrix matrix, FILE *fp);
#endif

/* @} */

#endif
