#!/usr/bin/env bash

SCRIPT_PATH=$(realpath $(dirname $0))
BASE_FILE=$(realpath $SCRIPT_PATH/sgnav-replay-base.ini)
CONFIG_PATH="$(realpath $SCRIPT_PATH/../../../etc/navtests)"

source $SCRIPT_PATH/config.sh

getCommands()
{
  qi=$1
  prev_comm=$2
  for ((i = 0 ; i < ${max[${QUANTITIES[$qi]}]} ; i++)); do
    com=$prev_comm
    com+="s+\#${QUANTITIES[$qi]}\#+${values[${QUANTITIES[$qi]},$i]}+g;"
    if [[ $((qi + 1)) -lt ${#QUANTITIES[@]} ]]; then
        local COMMANDS+=($(getCommands $((qi + 1)) $com))
    else
        local COMMANDS+=($com)
    fi
  done
  echo ${COMMANDS[@]}
}

generate()
{
  if [[ ! -d $CONFIG_PATH ]]; then
    mkdir $CONFIG_PATH
  fi
  
  COMMANDS=($(getCommands 0 ""))
  for test_log in ${TEST_LOGS[@]}; do
    # Create test directory
    LOG_NAME=$(grep -Eo "[0-9]{6}_\w+" <<< $test_log)
    mkdir $CONFIG_PATH/$LOG_NAME $CONFIG_PATH/$LOG_NAME/results

    # Generate test files
    TEST_NUM=0
    for c in ${COMMANDS[@]}; do
      EXTRA_COMMANDS="s+\#TNUM\#+$TEST_NUM+g;"
      EXTRA_COMMANDS+="s+\#DFOL\#+$CONFIG_PATH/$LOG_NAME/results+g;"
      EXTRA_COMMANDS+="s+\#VEHICLE\#+$VEHICLE+g;"
      EXTRA_COMMANDS+="s+\#LOG\#+$test_log+g;"
      
      FULL_COMMAND=$c
      FULL_COMMAND+=$EXTRA_COMMANDS

      sed -e $FULL_COMMAND $BASE_FILE > $CONFIG_PATH/$LOG_NAME/test_$TEST_NUM.ini
      TEST_NUM=$((TEST_NUM + 1))
    done
  done
}

clean()
{
  if [[ -d $CONFIG_PATH ]]; then
    rm -r $CONFIG_PATH/*
  fi
}

# Main
case $1 in

  "clean")
    clean
    ;;

  "exportvars")
    ;;

  *)
    clean
    generate
    ;;
esac

