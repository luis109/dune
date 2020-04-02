#!/usr/bin/env bash

#Options
BASE_FILE="sgnav-replay-base.ini"
VEHICLE="lauv-noptilus-3"
CONCURRENT_REPLAYS=30

# Dune paths
DUNE=/home/luis/workspace/dune/build
DUNEC=/home/luis/workspace/dune/dune

# General paths
LOG_PATH=$DUNEC/log/$VEHICLE
STORE_PATH=/mnt/Big_Boy/param_tests
CONFIG_PATH=$DUNEC/etc/navtests

# Date
START_DATE=$(date +"%Y%m%d")

end_run()
{
    STORE_PATH=$STORE_PATH/run_$(date +"%Y%m%d_%H%M%S")
    mkdir $STORE_PATH
    mv $CONFIG_PATH/* $STORE_PATH
    mkdir $STORE_PATH/$VEHICLE
    mv $LOG_PATH/$START_DATE $STORE_PATH/$VEHICLE
    mv $LOG_PATH/$(($START_DATE + 1)) $STORE_PATH/$VEHICLE
}

gen_config()
{
    while read TEST_LOG; do
        # Create test directory
        TEST_NAME=$(grep -Eo "[0-9]{6}_\w+" <<< $TEST_LOG)
        mkdir $CONFIG_PATH/$TEST_NAME $CONFIG_PATH/$TEST_NAME/results

        # Generate test files
        TEST_NUM=0
        for h in {-10..1}; do
            for r in {-10..1}; do
                sed -e "s/\#HVAL\#/1e$h/g"\
                    -e "s/\#RVAL\#/1e$r/g"\
                    -e "s/\#TNUM\#/$TEST_NUM/g"\
                    -e "s+\#DFOL\#+$CONFIG_PATH/$TEST_NAME/results+g"\
                    -e "s+\#LOG\#+$TEST_LOG+g"\
                    $BASE_FILE > $CONFIG_PATH/$TEST_NAME/test_$TEST_NUM.ini
                TEST_NUM=$((TEST_NUM + 1))
            done
        done
    done < $1
}

run_test()
{
    cd $DUNE
    TEST_NAMES=($(find $CONFIG_PATH/* -maxdepth 0 -type d -iname "*" -printf "%f "))

    for tn in ${TEST_NAMES[@]}; do
        TEST_FILES=($(find $CONFIG_PATH/$tn -maxdepth 1 -type f -iname "test_[0-9]*" -printf "%f "))
        INDEX=0
        TESTS_RAN=0

        for tf in ${TEST_FILES[@]}; do
            echo "$tn -> ${tf::-4}"

            ./dune -c navtests/$tn/${tf::-4} 2>/dev/null &
            PROCESS+=($!)
            sleep 2
            ((++INDEX))

            if [[ $INDEX -ge $CONCURRENT_REPLAYS ]]; then
                echo "ENTERED WAIT"
                wait ${PROCESS[@]}

                TESTS_RAN=$((TESTS_RAN + INDEX))
                echo "$tn completed $TESTS_RAN tests"
                
                unset PROCESS
                INDEX=0
            fi
        done

        wait ${PROCESS[@]}
        unset PROCESS
        echo "$tn completed $INDEX tests"

        cat $(find "$CONFIG_PATH/$tn/results" -type f -iname "test_*") \
            > $CONFIG_PATH/$tn/results/test_$tn.dat
    done
}

# Cleanups
clean_config()
{
    rm -r $CONFIG_PATH/**/*.ini
}

clean_results()
{
    rm -r $CONFIG_PATH/**/**/*.dat
}

clean()
{
    rm -r $LOG_PATH/$START_DATE/*
    rm -r $CONFIG_PATH/*
}


# Main
if [[ "$1" == "clean" ]]; then
    clean
elif [[ "$1" == "clean_config" ]]; then
    clean_config
elif [[ "$1" == "gen_config" ]]; then
    gen_config $2
elif [[ "$1" == "run" ]]; then
    run_test
else
    clean
    gen_config $1
    run_test
    end_run
fi


# rm "$RES_PATH/$OUT_FILE.dat"
# cat $(find "$RES_PATH" -type f -iname "test_*") > $RES_PATH/$OUT_FILE.dat
# # find $RES_PATH -type f -iname "test_*" | xargs rm