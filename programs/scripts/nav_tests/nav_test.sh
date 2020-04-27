#!/usr/bin/env bash

# Dune paths
BUILD=/home/luis/workspace/dune/build
LOG_PATH=$BUILD/log

run_test()
{
  cd $BUILD
  local TEST_NAMES=($(find $CONFIG_PATH/* -maxdepth 0 -type d -iname "*" -printf "%f "))

  for tn in ${TEST_NAMES[@]}; do
    local TEST_FILES=($(find $CONFIG_PATH/$tn -maxdepth 1 -type f -iname "test_[0-9]*" -printf "%f "))
    local TESTS_RAN=0

    for tf in ${TEST_FILES[@]}; do
      echo "$tn -> ${tf::-4}"

      if [[ ${#PROCESS[@]} -gt 0 ]]; then
        ./dune -c navtests/$tn/${tf::-4} 2>/dev/null &
      else
        ./dune -c navtests/$tn/${tf::-4} & # 2>/dev/null
      fi
      
      local PROCESS+=($!)
      local TO_REMOVE+=($CONFIG_PATH/$tn/$tf)
      sleep 2

      if [[ ${#PROCESS[@]} -ge $CONCURRENT_REPLAYS ]]; then
          echo "ENTERED WAIT - $(date +"%H:%M:%S")"
          wait ${PROCESS[@]}

          TESTS_RAN=$((TESTS_RAN + ${#PROCESS[@]}))
          echo "$tn completed $TESTS_RAN tests"

          rm ${TO_REMOVE[@]}
          unset TO_REMOVE
          unset PROCESS
      fi
    done

    echo "ENTERED WAIT - $(date +"%H:%M:%S")"
    wait ${PROCESS[@]}

    TESTS_RAN=$((TESTS_RAN + ${#PROCESS[@]}))
    echo "$tn completed $TESTS_RAN tests"

    rm ${TO_REMOVE[@]}
    unset TO_REMOVE
    unset PROCESS

    RESULT_FILES=($(find "$CONFIG_PATH/$tn/results" -type f -iname "test_*"))
    cat ${RESULT_FILES[@]} > $CONFIG_PATH/$tn/results/test_$tn.dat
    rm $RESULT_FILES
  done
}

fullClean()
{
  source gen_config.sh "exportvars"
  source gen_config.sh "clean"
  rm -r $LOG_PATH/$VEHICLE
}

end_run()
{
  STORE_PATH=$STORE_PATH/$TEST_NAME
  mkdir $STORE_PATH
  mv $CONFIG_PATH/* $STORE_PATH
  mv $LOG_PATH/$VEHICLE $STORE_PATH
}

# Main
case $1 in

  "clean")
    fullClean
    ;;

  "continue")
    source gen_config.sh "exportvars"
    run_test
    end_run
    ;;

  "end_run")
    source gen_config.sh "exportvars"
    end_run
    ;;

  *)
    fullClean
    source gen_config.sh
    run_test
    end_run
    ;;
esac