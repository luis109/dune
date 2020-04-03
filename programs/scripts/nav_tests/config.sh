#!/usr/bin/env bash

# Options
CONCURRENT_REPLAYS=50
STORE_PATH=/media/luis/Fat_Man/param_tests
TEST_NAME="run_1"

declare -A values
declare -A max

QUANTITIES=("HVAL" "RVAL")

for q in ${QUANTITIES[@]}; do

  idx=0
  for v in {-10..1}; do
    values[$q,$idx]="1e$v"      
    ((++idx))
  done

  max[$q]=$idx
done

TEST_LOGS=("/home/luis/Downloads/logs/141915_navigation_test_cclw/Data.lsf")
VEHICLE="lauv-noptilus-3"