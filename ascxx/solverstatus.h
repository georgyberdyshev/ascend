#ifndef ASCXX_SOLVERSTATUS_H
#define ASCXX_SOLVERSTATUS_H

#include <cstdio>

#include "config.h"
extern "C"{
#include <ascend/system/slv_common.h>
}

#include "simulation.h"

/**
	Class to wrap slv_status_t and provide
	and query interface to access various data from it
*/
class SolverStatus{
private:
	slv_status_t s;

public:
	SolverStatus();
	SolverStatus(const SolverStatus &old);
	void getSimulationStatus(Simulation &);

	const bool isOK() const;
	const bool isOverDefined() const;
	const bool isUnderDefined() const;
	const bool isStructurallySingular() const;
	const bool isInconsistent() const;
	const bool isReadyToSolve() const;
	const bool isConverged() const;
	const bool isDiverged() const;
	const bool hasExceededIterationLimit() const;
	const bool hasExceededTimeLimit() const;
	const bool hasResidualCalculationErrors() const;
	const bool isInterrupted() const;
	const int getIterationNum() const;

	// block structure stuff...

	const int getNumBlocks() const;
	const int getCurrentBlockNum() const;
	const int getCurrentBlockSize() const;
	const int getCurrentBlockIteration() const;
	const int getNumConverged() const; /* previous total size */
	const int getNumJacobianEvals() const;
	const int getNumResidualEvals() const;
	const double getBlockResidualRMS() const;
};

#endif // ASCXX_SOLVERSTATUS_H
