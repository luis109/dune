# Example script for automated navigation tests
#
# Folder structure:
# test_folder/
# ├── og/
# │   ├── log1/
# │   │   └── Data.lsf
# │   └── log2/
# │       └── Data.lsf
# ├── test1/
# │   ├── test_list.sh
# │   ├── (result1/)
# │   ├── (result2/)
# │   └── (result3/)
# └── test2/
#     ├── test_list.sh
#     ├── (result1/)
#     └── (result2/)
#
# Have a master test_folder.
# Place original log folders in "og" folder (must be named "og").
# Use individual folders for the different tests (test1, test2, testwtv, etc)
# 
# DUNE_BUILD -> Full path to dune build directory
# BASE_FILE -> Full path to sgnav-replay-list-base.ini
# INI_FILE -> Full path to the generated ini file
# INI_FILE_RPATH -> Relative path to the generated ini file, from etc
#
# General variables:
#   logs -> List of full paths to the logs to be tested
#   vehicles -> List of full vehicle names corresponding to 'logs'. Must be same size as 'logs'
#
# Testable variables:
#   DISGPS -> Disable GPS
#   DISGPSWAITTIME -> GPS disable wait time
#   DISGPSAL -> Disable GPS When Aligned
#   IMUWAITTIME -> IMU initialization time
#   ALINDEX -> Heading Bias Alignment Index
#   ALINDEXTHRESH -> Alignment Index Threshold
#   PSIBASE -> Measure Noise Covariance[2] (Psi AHRS)
#   RBASE -> Measure Noise Covariance[3] (R AHRS)

#!/usr/bin/env bash
#   Directories
DUNE_SRC=/home/luis/workspace/dune/dune
DUNE_BUILD=/home/luis/workspace/dune/build
BASE_FILE=/home/luis/workspace/dune/dune/etc/testing/replays/sgnav-replay-list-base.ini
INI_FILE=/home/luis/workspace/dune/dune/etc/testing/replays/sgnav-replay-list.ini
INI_FILE_RPATH=testing/replays/sgnav-replay-list

# USER INPUTS:
#   Branch
branch='feature/NavTest_scripts_mst'

#   General variables:
logs=(  '164917_navigation_test_fig8'
        '123631_navigation_test_fig8'
        '142217_navigation_test_fig8')

vehicles=(  'lauv-noptilus-3'
            'lauv-noptilus-3' 
            'lauv-noptilus-3')

#   Testable variables:
AHRSONLY='false'

DISGPS='true'
DISGPSWAITTIME='20.0'
DISGPSAL='false'

ALINDEX='1e-5'
ALINDEXTHRESH='2e-5'

PSIBASE=('1e-3')
RBASE=('1e-3')

# FOLLOW THE RULES ABOVE AND LEAVE THIS ALONE:
#   Directories
TEST_DIR=$(realpath ${0%/*})

#   Check if user messed up
if [ ! ${#logs[@]} == ${#vehicles[@]} ]; then
    echo "ERROR: logs and vehicles are not the same length"
    exit 1
fi

#   Get test paths
for log in ${logs[@]}; do
    log_paths+=($(realpath $TEST_DIR/../og/$log/Data.lsf))
done

#   Switch to branch
cd $DUNE_SRC && git stash && git checkout $branch
cd $DUNE_BUILD && make rebuild_cache && make -j8
cd $TEST_DIR

#   Get start date (for getting replays)
date_start=$(date +"%Y%m%d")

#   Create ini's and run tests
for ((l=0; l<${#logs[@]}; l++)); do
    for ((n=0; n<${#PSIBASE[@]}; n++)); do
        # Commands
        COMMANDS="s+\#LOG\#+${log_paths[$l]}+g;"
        COMMANDS+="s+\#VEHICLE\#+${vehicles[$l]}+g;"
        COMMANDS+="s+\#DISGPS\#+${DISGPS}+g;"
        COMMANDS+="s+\#DISGPSWAITTIME\#+${DISGPSWAITTIME}+g;"
        COMMANDS+="s+\#DISGPSAL\#+${DISGPSAL}+g;"
        COMMANDS+="s+\#IMUWAITTIME\#+${IMUWAITTIME}+g;"
        COMMANDS+="s+\#ALINDEX\#+${ALINDEX}+g;"
        COMMANDS+="s+\#ALINDEXTHRESH\#+${ALINDEXTHRESH}+g;"
        COMMANDS+="s+\#PSIBASE\#+${PSIBASE}+g;"
        COMMANDS+="s+\#RBASE\#+${RBASE}+g;"

        if [ $AHRSONLY == 'true' ]; then
            COMMANDS+="/IMU,/d;"
        fi

        sed -e $COMMANDS $BASE_FILE > $INI_FILE
        $DUNE_BUILD/dune -c $INI_FILE_RPATH
        wait $!
        echo " "
    done
done

#   Get dates since start (for getting replays)
date_end=$(date +"%Y%m%d")
for i in {0..5}; do
    date_list+=($(date -d "$date_start +$i days" +"%Y%m%d"))
    
    if [ ${date_list[$i]} == $date_end ]; then
        break
    fi
done

#   Get test results (replays)
for ((l=0; l<${#logs[@]}; l++)); do
    for ((d=0; d<${#date_list[@]}; d++)); do
        results_list+=($(find $DUNE_BUILD/log/${vehicles[$l]}/${date_list[$d]}/ -type d -iname "*${logs[$l]}_replay"))
    done
done

for r in ${results_list[@]}; do
    mv $r $TEST_DIR
done