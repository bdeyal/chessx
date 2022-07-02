#!/bin/sh
 
############################################################################################################
# You should edit the following 3 paths when necessary
############################################################################################################

PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/MacGPG2/bin:/Library/Apple/usr/bin

# Get the path to the current folder
SCRIPT_DIR=$PWD
echo "Zero coverage in $SCRIPT_DIR"

# SRC_DIR is the directory containing the .gcno files (%{buildDir} in Qt Creator)
SRC_DIR="$SCRIPT_DIR/obj_dbg"

# COV_DIR is the directory where the coverage results will be stored
COV_DIR="$SCRIPT_DIR/coverage"

############################################################################################################

# Reset our counts
lcov -d "${COV_DIR}" -z
